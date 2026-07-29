import css from "@webref/css";

const cssTypeMap = {
    "length": "measure",
    "number": "double",
    "integer": "int"
};

interface StyleTemplateSpecialization {
    propName: string;
    synTypeName: string;
    members: {
        typ: string;
        name: string;
    }[];
};

interface CssProperty {
    name: string;
    initial?: string;
    syntax?: string;
    longhands?: string[];
};

export async function makeCssPropertiesSection() {
    const { atrules, functions, properties, selectors, types } = await css.listAll();
    let cssPropSection = "";
    for (const prop of properties) {
        const cssProp = prop as CssProperty;
        if (cssProp.name.startsWith("-")) continue;
        const cppName = cssProp.name.replace(/\-/g, "_");
        cssPropSection += `inline constexpr aspect_generator<^^std::string_view, "${cppName}", [][[=format_name("${cssProp.name}")]]{}> $${cppName};\n`;
    }
    return cssPropSection;
}

