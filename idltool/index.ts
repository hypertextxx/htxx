import { writeFile } from "fs";

import htmlJson from "./webref/ed/idlparsed/html.json" with { type: "json" };
const htmlIdl = htmlJson.idlparsed;
import elementJson from "./webref/ed/elements/html.json" with { type: "json" };
import { makeCssPropertiesSection } from "./csstool.js";
const htmlElementsRef = elementJson.elements;

const typeMap = {
    "boolean": "bool",
    "DOMString": "std::string_view",
    "USVString": "std::string_view",
    "double": "double",
    "unrestricted double": "double",
    "long": "long",
    "unsigned long": "unsigned long",
    "EventHandler": "std::string_view"
}

const skipInterfaces = new Set(["HTMLTemplateElement"]);
const skipElements = new Set([]);

const htmlElements = htmlElementsRef.filter(el => !skipInterfaces.has(el.interface) && !skipElements.has(el.name))

interface Attribute {
    attrName: string
    attrType: string | string[]
}

interface IdlInterface {
    interfaceName: string
    parents: string[]
    includes: string[]
    attributes: Attribute[]
}

function makeAttributeType(a) {
    if (Array.isArray(a)) {
        return a.map(i => makeAttributeType(i))
    } else {
        return a.idlType || a;
    }
}

function makeAttrVariant(att) {
    if (Array.isArray(att)) {
        return `std::variant<${att.map(a => makeAttrVariant(a)).join(", ")}>`;
    } else {
        if (!typeMap[att]) {
            console.warn(`missing type map for ${att}`);
            return "std::string_view";
        }
        return typeMap[att];
    }
}

function getDependencies(interfaceName: string): string[] {
    let toAdd = new Set<string>();
    if (htmlIdl.idlNames[interfaceName]?.inheritance) {
        toAdd.add(htmlIdl.idlNames[interfaceName].inheritance);
    }
    htmlIdl.idlExtendedNames[interfaceName]?.forEach(ext => {
        if (ext["name"] === interfaceName && ext["inheritance"]) {
            toAdd.add(ext["inheritance"]);
        }
        if (ext["type"] === "includes") {
            toAdd.add(ext["includes"]);
        }
    })
    if (toAdd.size > 0) {
        return [...([...toAdd].flatMap(a => getDependencies(a))), ...toAdd];
    } else {
        return [];
    }
}

let indentLevel = 0;

function indent(text: string) {
    return " ".repeat(4 * indentLevel) + text;
}

type AttrSpecs = { [name: string]: Attribute[] };

function makeAttributeSpecSection(defs: IdlInterface[]) {
    let attributeSpecSection = "";
 
    
    const specs = defs.flatMap(d => d.attributes).reduce<AttrSpecs>((prev, current) => {
        prev[`${current.attrName}`] = current.attrName in prev ? [...prev[`${current.attrName}`], current] : [current];
        return prev;
    }, { });

    for (let [name, attrs] of Object.entries(specs)) {
        const templateTypes = [...new Set(attrs.map(t => makeAttrVariant(t.attrType)))];
        if (templateTypes.length > 1) {
            attributeSpecSection += indent(`inline constexpr aspect_generator<^^std::variant<${templateTypes.join(", ")}>, "${name}"> $${name};\n`);
        } else {
            attributeSpecSection += indent(`inline constexpr aspect_generator<^^${templateTypes[0]}, "${name}"> $${name};\n`);
        }
    }

    return attributeSpecSection;
}

function makeElementSection(defs: IdlInterface[]) {
    let elementSection = "";
    const inheritedInterfaces = new Set<IdlInterface>();
    let interfaceSection = "";
    let count = 0;
    defs.forEach(def => {
        const tags = htmlElements.filter(e => e.interface === def.interfaceName).map(e => e.name);
        tags.forEach(tag => {
            elementSection += indent(`template <class ...A> struct `);
            // make this recurse
            elementSection += `[[=permit(${def.attributes.map(attr => `$${attr.attrName}`).join(", ")})]] `;
            elementSection += `${tag}: virtual element<${tag}<A...>>`;
            if (def.parents.length > 0 || def.includes.length > 0) {
                elementSection += `, ${defs.filter(d => def.parents.includes(d.interfaceName) || def.includes.includes(d.interfaceName)).map(d => {
                    inheritedInterfaces.add(d);
                    return `idl_interface<"${d.interfaceName}">`;
                }).join(", ")}`
            }
            elementSection += ` {\n`;
            indentLevel++;
            elementSection += indent(`constexpr ${tag}() = default;\n`);
            elementSection += indent(`constexpr ${tag}(A ...args): ${tag}::element{ std::move(args)... } { }\n`);
            indentLevel--;
            elementSection += indent(`};\n\n`);
        });
    });
    console.log(`found ${count} elements`)

    inheritedInterfaces.forEach(iface => {
        interfaceSection += indent(`template <> struct [[=permit(${iface.attributes.map(a => `$${a.attrName}`).join(", ")})]] idl_interface<"${iface.interfaceName}">`);
        if (iface.parents.length > 0 || iface.includes.length > 0) {
            interfaceSection += `: ${[...iface.parents, ...iface.includes].map(i => `idl_interface<"${i}">`).join(", ")}`
        }
        interfaceSection += ` {\n`;
        indentLevel++;
        interfaceSection += indent(`constexpr idl_interface() = default;\n`);
        indentLevel--;
        interfaceSection += indent(`};\n\n`);
    });
    
    return interfaceSection + elementSection;
}

let interfaceNames = new Set<string>();
htmlElements.forEach(e => {
    getDependencies(e.interface).forEach(d => interfaceNames.add(d));
    interfaceNames.add(e.interface)
});

const defs = [...interfaceNames].map(i => {
    let idlInterface: IdlInterface = {
        interfaceName: i,
        parents: [htmlIdl.idlNames[i], ...(htmlIdl.idlExtendedNames[i] || [])].map(ext => ext?.inheritance).filter(i => i),
        includes: [htmlIdl.idlNames[i], ...(htmlIdl.idlExtendedNames[i] || []).filter(ext => ext && ext["type"] === "includes")].flatMap(ext => ext?.includes).filter(i => i),
        attributes: [htmlIdl.idlNames[i], ...(htmlIdl.idlExtendedNames[i] || [])].flatMap(ext => ext?.members).filter(m => m && m["type"] === "attribute").map(attr => ({
            attrName: attr["name"],
            attrType: makeAttributeType(attr["idlType"]["idlType"])
        }))
    };
    return idlInterface;
}).filter(d => !skipInterfaces.has(d.interfaceName));

console.log(`found ${defs.length} interfaces`);

const outDir = process.argv.length >= 3 ? process.argv[2] : "out";

writeFile(`${outDir}/aspects.def`, makeAttributeSpecSection(defs), () => { console.log("wrote aspects.def") });
writeFile(`${outDir}/elements.def`, makeElementSection(defs), () => { console.log("wrote elements.def") });

makeCssPropertiesSection().then(c => writeFile(`${outDir}/style.def`, c, () => { console.log("wrote style.def") }));

