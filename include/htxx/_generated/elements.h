template <> struct [[=permit($innerHTML, $outerHTML)]] idl_interface<"Element"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($onabort, $onauxclick, $onbeforeinput, $onbeforematch, $onbeforetoggle, $onblur, $oncancel, $oncanplay, $oncanplaythrough, $onchange, $onclick, $onclose, $oncontextlost, $oncontextmenu, $oncontextrestored, $oncopy, $oncuechange, $oncut, $ondblclick, $ondrag, $ondragend, $ondragenter, $ondragleave, $ondragover, $ondragstart, $ondrop, $ondurationchange, $onemptied, $onended, $onerror, $onfocus, $onformdata, $oninput, $oninvalid, $onkeydown, $onkeypress, $onkeyup, $onload, $onloadeddata, $onloadedmetadata, $onloadstart, $onmousedown, $onmouseenter, $onmouseleave, $onmousemove, $onmouseout, $onmouseover, $onmouseup, $onpaste, $onpause, $onplay, $onplaying, $onprogress, $onratechange, $onreset, $onresize, $onscroll, $onscrollend, $onsecuritypolicyviolation, $onseeked, $onseeking, $onselect, $onslotchange, $onstalled, $onsubmit, $onsuspend, $ontimeupdate, $ontoggle, $onvolumechange, $onwaiting, $onwebkitanimationend, $onwebkitanimationiteration, $onwebkitanimationstart, $onwebkittransitionend, $onwheel)]] idl_interface<"GlobalEventHandlers"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($contentEditable, $enterKeyHint, $isContentEditable, $inputMode)]] idl_interface<"ElementContentEditable"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($dataset, $nonce, $autofocus, $tabIndex)]] idl_interface<"HTMLOrSVGElement"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] idl_interface<"HTMLElement">: idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit()]] idl_interface<"LinkStyle"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($onafterprint, $onbeforeprint, $onbeforeunload, $onhashchange, $onlanguagechange, $onmessage, $onmessageerror, $onoffline, $ononline, $onpagehide, $onpagereveal, $onpageshow, $onpageswap, $onpopstate, $onrejectionhandled, $onstorage, $onunhandledrejection, $onunload)]] idl_interface<"WindowEventHandlers"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($href, $origin, $protocol, $username, $password, $host, $hostname, $port, $pathname, $search, $hash)]] idl_interface<"HTMLHyperlinkElementUtils"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($error, $src, $srcObject, $currentSrc, $crossOrigin, $networkState, $preload, $buffered, $readyState, $seeking, $currentTime, $duration, $paused, $defaultPlaybackRate, $playbackRate, $preservesPitch, $played, $seekable, $ended, $autoplay, $loop, $controls, $volume, $muted, $defaultMuted, $audioTracks, $videoTracks, $textTracks)]] idl_interface<"HTMLMediaElement">: idl_interface<"HTMLElement"> {
    constexpr idl_interface() = default;
};

template <> struct [[=permit($popoverTargetElement, $popoverTargetAction)]] idl_interface<"PopoverInvokerElement"> {
    constexpr idl_interface() = default;
};

template <class ...A> struct [[=permit()]] fencedframe: element<fencedframe<A...>> {
    constexpr fencedframe() = default;
    constexpr fencedframe(A ...args): fencedframe::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] geolocation: element<geolocation<A...>> {
    constexpr geolocation() = default;
    constexpr geolocation(A ...args): geolocation::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] article: element<article<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr article() = default;
    constexpr article(A ...args): article::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] section: element<section<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr section() = default;
    constexpr section(A ...args): section::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] nav: element<nav<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr nav() = default;
    constexpr nav(A ...args): nav::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] aside: element<aside<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr aside() = default;
    constexpr aside(A ...args): aside::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] hgroup: element<hgroup<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr hgroup() = default;
    constexpr hgroup(A ...args): hgroup::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] header: element<header<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr header() = default;
    constexpr header(A ...args): header::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] footer: element<footer<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr footer() = default;
    constexpr footer(A ...args): footer::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] address: element<address<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr address() = default;
    constexpr address(A ...args): address::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] dt: element<dt<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr dt() = default;
    constexpr dt(A ...args): dt::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] dd: element<dd<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr dd() = default;
    constexpr dd(A ...args): dd::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] figure: element<figure<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr figure() = default;
    constexpr figure(A ...args): figure::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] figcaption: element<figcaption<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr figcaption() = default;
    constexpr figcaption(A ...args): figcaption::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] main: element<main<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr main() = default;
    constexpr main(A ...args): main::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] search: element<search<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr search() = default;
    constexpr search(A ...args): search::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] em: element<em<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr em() = default;
    constexpr em(A ...args): em::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] strong: element<strong<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr strong() = default;
    constexpr strong(A ...args): strong::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] small: element<small<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr small() = default;
    constexpr small(A ...args): small::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] s: element<s<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr s() = default;
    constexpr s(A ...args): s::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] cite: element<cite<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr cite() = default;
    constexpr cite(A ...args): cite::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] dfn: element<dfn<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr dfn() = default;
    constexpr dfn(A ...args): dfn::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] abbr: element<abbr<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr abbr() = default;
    constexpr abbr(A ...args): abbr::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] ruby: element<ruby<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr ruby() = default;
    constexpr ruby(A ...args): ruby::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] rt: element<rt<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr rt() = default;
    constexpr rt(A ...args): rt::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] rp: element<rp<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr rp() = default;
    constexpr rp(A ...args): rp::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] code: element<code<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr code() = default;
    constexpr code(A ...args): code::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] var: element<var<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr var() = default;
    constexpr var(A ...args): var::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] samp: element<samp<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr samp() = default;
    constexpr samp(A ...args): samp::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] kbd: element<kbd<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr kbd() = default;
    constexpr kbd(A ...args): kbd::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] sub: element<sub<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr sub() = default;
    constexpr sub(A ...args): sub::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] sup: element<sup<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr sup() = default;
    constexpr sup(A ...args): sup::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] i: element<i<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr i() = default;
    constexpr i(A ...args): i::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] b: element<b<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr b() = default;
    constexpr b(A ...args): b::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] u: element<u<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr u() = default;
    constexpr u(A ...args): u::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] mark: element<mark<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr mark() = default;
    constexpr mark(A ...args): mark::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] bdi: element<bdi<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr bdi() = default;
    constexpr bdi(A ...args): bdi::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] bdo: element<bdo<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr bdo() = default;
    constexpr bdo(A ...args): bdo::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] wbr: element<wbr<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr wbr() = default;
    constexpr wbr(A ...args): wbr::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] summary: element<summary<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr summary() = default;
    constexpr summary(A ...args): summary::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($title, $lang, $translate, $dir, $hidden, $inert, $accessKey, $accessKeyLabel, $draggable, $spellcheck, $writingSuggestions, $autocapitalize, $autocorrect, $innerText, $outerText, $popover)]] noscript: element<noscript<A...>>, idl_interface<"Element">, idl_interface<"GlobalEventHandlers">, idl_interface<"ElementContentEditable">, idl_interface<"HTMLOrSVGElement"> {
    constexpr noscript() = default;
    constexpr noscript(A ...args): noscript::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($version)]] html: element<html<A...>>, idl_interface<"HTMLElement"> {
    constexpr html() = default;
    constexpr html(A ...args): html::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] head: element<head<A...>>, idl_interface<"HTMLElement"> {
    constexpr head() = default;
    constexpr head(A ...args): head::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($text)]] title: element<title<A...>>, idl_interface<"HTMLElement"> {
    constexpr title() = default;
    constexpr title(A ...args): title::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($href, $target)]] base: element<base<A...>>, idl_interface<"HTMLElement"> {
    constexpr base() = default;
    constexpr base(A ...args): base::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($href, $crossOrigin, $rel, $as, $relList, $media, $integrity, $hreflang, $type, $sizes, $imageSrcset, $imageSizes, $referrerPolicy, $blocking, $disabled, $fetchPriority, $charset, $rev, $target)]] link: element<link<A...>>, idl_interface<"HTMLElement">, idl_interface<"LinkStyle"> {
    constexpr link() = default;
    constexpr link(A ...args): link::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($name, $httpEquiv, $content, $media, $scheme)]] meta: element<meta<A...>>, idl_interface<"HTMLElement"> {
    constexpr meta() = default;
    constexpr meta(A ...args): meta::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($disabled, $media, $blocking, $type)]] style: element<style<A...>>, idl_interface<"HTMLElement">, idl_interface<"LinkStyle"> {
    constexpr style() = default;
    constexpr style(A ...args): style::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($text, $link, $vLink, $aLink, $bgColor, $background)]] body: element<body<A...>>, idl_interface<"HTMLElement">, idl_interface<"WindowEventHandlers"> {
    constexpr body() = default;
    constexpr body(A ...args): body::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h1: element<h1<A...>>, idl_interface<"HTMLElement"> {
    constexpr h1() = default;
    constexpr h1(A ...args): h1::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h2: element<h2<A...>>, idl_interface<"HTMLElement"> {
    constexpr h2() = default;
    constexpr h2(A ...args): h2::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h3: element<h3<A...>>, idl_interface<"HTMLElement"> {
    constexpr h3() = default;
    constexpr h3(A ...args): h3::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h4: element<h4<A...>>, idl_interface<"HTMLElement"> {
    constexpr h4() = default;
    constexpr h4(A ...args): h4::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h5: element<h5<A...>>, idl_interface<"HTMLElement"> {
    constexpr h5() = default;
    constexpr h5(A ...args): h5::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] h6: element<h6<A...>>, idl_interface<"HTMLElement"> {
    constexpr h6() = default;
    constexpr h6(A ...args): h6::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] p: element<p<A...>>, idl_interface<"HTMLElement"> {
    constexpr p() = default;
    constexpr p(A ...args): p::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align, $color, $noShade, $size, $width)]] hr: element<hr<A...>>, idl_interface<"HTMLElement"> {
    constexpr hr() = default;
    constexpr hr(A ...args): hr::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($width)]] pre: element<pre<A...>>, idl_interface<"HTMLElement"> {
    constexpr pre() = default;
    constexpr pre(A ...args): pre::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($cite)]] blockquote: element<blockquote<A...>>, idl_interface<"HTMLElement"> {
    constexpr blockquote() = default;
    constexpr blockquote(A ...args): blockquote::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($cite)]] q: element<q<A...>>, idl_interface<"HTMLElement"> {
    constexpr q() = default;
    constexpr q(A ...args): q::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($reversed, $start, $type, $compact)]] ol: element<ol<A...>>, idl_interface<"HTMLElement"> {
    constexpr ol() = default;
    constexpr ol(A ...args): ol::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($compact, $type)]] ul: element<ul<A...>>, idl_interface<"HTMLElement"> {
    constexpr ul() = default;
    constexpr ul(A ...args): ul::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($compact)]] menu: element<menu<A...>>, idl_interface<"HTMLElement"> {
    constexpr menu() = default;
    constexpr menu(A ...args): menu::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($value, $type)]] li: element<li<A...>>, idl_interface<"HTMLElement"> {
    constexpr li() = default;
    constexpr li(A ...args): li::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($compact)]] dl: element<dl<A...>>, idl_interface<"HTMLElement"> {
    constexpr dl() = default;
    constexpr dl(A ...args): dl::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] div: element<div<A...>>, idl_interface<"HTMLElement"> {
    constexpr div() = default;
    constexpr div(A ...args): div::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($target, $download, $ping, $rel, $relList, $hreflang, $type, $text, $referrerPolicy, $coords, $charset, $name, $rev, $shape)]] a: element<a<A...>>, idl_interface<"HTMLElement">, idl_interface<"HTMLHyperlinkElementUtils"> {
    constexpr a() = default;
    constexpr a(A ...args): a::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($value)]] data: element<data<A...>>, idl_interface<"HTMLElement"> {
    constexpr data() = default;
    constexpr data(A ...args): data::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($dateTime)]] time: element<time<A...>>, idl_interface<"HTMLElement"> {
    constexpr time() = default;
    constexpr time(A ...args): time::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] span: element<span<A...>>, idl_interface<"HTMLElement"> {
    constexpr span() = default;
    constexpr span(A ...args): span::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($clear)]] br: element<br<A...>>, idl_interface<"HTMLElement"> {
    constexpr br() = default;
    constexpr br(A ...args): br::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($cite, $dateTime)]] ins: element<ins<A...>>, idl_interface<"HTMLElement"> {
    constexpr ins() = default;
    constexpr ins(A ...args): ins::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($cite, $dateTime)]] del: element<del<A...>>, idl_interface<"HTMLElement"> {
    constexpr del() = default;
    constexpr del(A ...args): del::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] picture: element<picture<A...>>, idl_interface<"HTMLElement"> {
    constexpr picture() = default;
    constexpr picture(A ...args): picture::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($src, $type, $srcset, $sizes, $media, $width, $height)]] source: element<source<A...>>, idl_interface<"HTMLElement"> {
    constexpr source() = default;
    constexpr source(A ...args): source::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($alt, $src, $srcset, $sizes, $crossOrigin, $useMap, $isMap, $width, $height, $naturalWidth, $naturalHeight, $complete, $currentSrc, $referrerPolicy, $decoding, $loading, $fetchPriority, $name, $lowsrc, $align, $hspace, $vspace, $longDesc, $border)]] img: element<img<A...>>, idl_interface<"HTMLElement"> {
    constexpr img() = default;
    constexpr img(A ...args): img::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($src, $srcdoc, $name, $sandbox, $allow, $allowFullscreen, $width, $height, $referrerPolicy, $loading, $contentDocument, $contentWindow, $align, $scrolling, $frameBorder, $longDesc, $marginHeight, $marginWidth)]] iframe: element<iframe<A...>>, idl_interface<"HTMLElement"> {
    constexpr iframe() = default;
    constexpr iframe(A ...args): iframe::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($src, $type, $width, $height, $align, $name)]] embed: element<embed<A...>>, idl_interface<"HTMLElement"> {
    constexpr embed() = default;
    constexpr embed(A ...args): embed::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($data, $type, $name, $form, $width, $height, $contentDocument, $contentWindow, $willValidate, $validity, $validationMessage, $align, $archive, $code, $declare, $hspace, $standby, $vspace, $codeBase, $codeType, $useMap, $border)]] object: element<object<A...>>, idl_interface<"HTMLElement"> {
    constexpr object() = default;
    constexpr object(A ...args): object::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($width, $height, $videoWidth, $videoHeight, $poster, $playsInline)]] video: element<video<A...>>, idl_interface<"HTMLMediaElement"> {
    constexpr video() = default;
    constexpr video(A ...args): video::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] audio: element<audio<A...>>, idl_interface<"HTMLMediaElement"> {
    constexpr audio() = default;
    constexpr audio(A ...args): audio::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($kind, $src, $srclang, $label, $default, $readyState, $track)]] track: element<track<A...>>, idl_interface<"HTMLElement"> {
    constexpr track() = default;
    constexpr track(A ...args): track::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($name, $areas)]] map: element<map<A...>>, idl_interface<"HTMLElement"> {
    constexpr map() = default;
    constexpr map(A ...args): map::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($alt, $coords, $shape, $target, $download, $ping, $rel, $relList, $referrerPolicy, $noHref)]] area: element<area<A...>>, idl_interface<"HTMLElement">, idl_interface<"HTMLHyperlinkElementUtils"> {
    constexpr area() = default;
    constexpr area(A ...args): area::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($caption, $tHead, $tFoot, $tBodies, $rows, $align, $border, $frame, $rules, $summary, $width, $bgColor, $cellPadding, $cellSpacing)]] table: element<table<A...>>, idl_interface<"HTMLElement"> {
    constexpr table() = default;
    constexpr table(A ...args): table::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($align)]] caption: element<caption<A...>>, idl_interface<"HTMLElement"> {
    constexpr caption() = default;
    constexpr caption(A ...args): caption::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($span, $align, $ch, $chOff, $vAlign, $width)]] colgroup: element<colgroup<A...>>, idl_interface<"HTMLElement"> {
    constexpr colgroup() = default;
    constexpr colgroup(A ...args): colgroup::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($span, $align, $ch, $chOff, $vAlign, $width)]] col: element<col<A...>>, idl_interface<"HTMLElement"> {
    constexpr col() = default;
    constexpr col(A ...args): col::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($rows, $align, $ch, $chOff, $vAlign)]] tbody: element<tbody<A...>>, idl_interface<"HTMLElement"> {
    constexpr tbody() = default;
    constexpr tbody(A ...args): tbody::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($rows, $align, $ch, $chOff, $vAlign)]] thead: element<thead<A...>>, idl_interface<"HTMLElement"> {
    constexpr thead() = default;
    constexpr thead(A ...args): thead::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($rows, $align, $ch, $chOff, $vAlign)]] tfoot: element<tfoot<A...>>, idl_interface<"HTMLElement"> {
    constexpr tfoot() = default;
    constexpr tfoot(A ...args): tfoot::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($rowIndex, $sectionRowIndex, $cells, $align, $ch, $chOff, $vAlign, $bgColor)]] tr: element<tr<A...>>, idl_interface<"HTMLElement"> {
    constexpr tr() = default;
    constexpr tr(A ...args): tr::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($colSpan, $rowSpan, $headers, $cellIndex, $scope, $abbr, $align, $axis, $height, $width, $ch, $chOff, $noWrap, $vAlign, $bgColor)]] td: element<td<A...>>, idl_interface<"HTMLElement"> {
    constexpr td() = default;
    constexpr td(A ...args): td::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($colSpan, $rowSpan, $headers, $cellIndex, $scope, $abbr, $align, $axis, $height, $width, $ch, $chOff, $noWrap, $vAlign, $bgColor)]] th: element<th<A...>>, idl_interface<"HTMLElement"> {
    constexpr th() = default;
    constexpr th(A ...args): th::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($acceptCharset, $action, $autocomplete, $enctype, $encoding, $method, $name, $noValidate, $target, $rel, $relList, $elements, $length)]] form: element<form<A...>>, idl_interface<"HTMLElement"> {
    constexpr form() = default;
    constexpr form(A ...args): form::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($form, $htmlFor, $control)]] label: element<label<A...>>, idl_interface<"HTMLElement"> {
    constexpr label() = default;
    constexpr label(A ...args): label::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($accept, $alpha, $alt, $autocomplete, $defaultChecked, $checked, $colorSpace, $dirName, $disabled, $form, $files, $formAction, $formEnctype, $formMethod, $formNoValidate, $formTarget, $height, $indeterminate, $list, $max, $maxLength, $min, $minLength, $multiple, $name, $pattern, $placeholder, $readOnly, $required, $size, $src, $step, $type, $defaultValue, $value, $valueAsDate, $valueAsNumber, $width, $willValidate, $validity, $validationMessage, $labels, $selectionStart, $selectionEnd, $selectionDirection, $align, $useMap)]] input: element<input<A...>>, idl_interface<"HTMLElement">, idl_interface<"PopoverInvokerElement"> {
    constexpr input() = default;
    constexpr input(A ...args): input::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($disabled, $form, $formAction, $formEnctype, $formMethod, $formNoValidate, $formTarget, $name, $type, $value, $willValidate, $validity, $validationMessage, $labels)]] button: element<button<A...>>, idl_interface<"HTMLElement">, idl_interface<"PopoverInvokerElement"> {
    constexpr button() = default;
    constexpr button(A ...args): button::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($autocomplete, $disabled, $form, $multiple, $name, $required, $size, $type, $options, $length, $selectedOptions, $selectedIndex, $value, $willValidate, $validity, $validationMessage, $labels)]] select: element<select<A...>>, idl_interface<"HTMLElement"> {
    constexpr select() = default;
    constexpr select(A ...args): select::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($options)]] datalist: element<datalist<A...>>, idl_interface<"HTMLElement"> {
    constexpr datalist() = default;
    constexpr datalist(A ...args): datalist::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($disabled, $label)]] optgroup: element<optgroup<A...>>, idl_interface<"HTMLElement"> {
    constexpr optgroup() = default;
    constexpr optgroup(A ...args): optgroup::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($disabled, $form, $label, $defaultSelected, $selected, $value, $text, $index)]] option: element<option<A...>>, idl_interface<"HTMLElement"> {
    constexpr option() = default;
    constexpr option(A ...args): option::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($autocomplete, $cols, $dirName, $disabled, $form, $maxLength, $minLength, $name, $placeholder, $readOnly, $required, $rows, $wrap, $type, $defaultValue, $value, $textLength, $willValidate, $validity, $validationMessage, $labels, $selectionStart, $selectionEnd, $selectionDirection)]] textarea: element<textarea<A...>>, idl_interface<"HTMLElement"> {
    constexpr textarea() = default;
    constexpr textarea(A ...args): textarea::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($htmlFor, $form, $name, $type, $defaultValue, $value, $willValidate, $validity, $validationMessage, $labels)]] output: element<output<A...>>, idl_interface<"HTMLElement"> {
    constexpr output() = default;
    constexpr output(A ...args): output::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($value, $max, $position, $labels)]] progress: element<progress<A...>>, idl_interface<"HTMLElement"> {
    constexpr progress() = default;
    constexpr progress(A ...args): progress::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($value, $min, $max, $low, $high, $optimum, $labels)]] meter: element<meter<A...>>, idl_interface<"HTMLElement"> {
    constexpr meter() = default;
    constexpr meter(A ...args): meter::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($disabled, $form, $name, $type, $elements, $willValidate, $validity, $validationMessage)]] fieldset: element<fieldset<A...>>, idl_interface<"HTMLElement"> {
    constexpr fieldset() = default;
    constexpr fieldset(A ...args): fieldset::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($form, $align)]] legend: element<legend<A...>>, idl_interface<"HTMLElement"> {
    constexpr legend() = default;
    constexpr legend(A ...args): legend::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] selectedcontent: element<selectedcontent<A...>> {
    constexpr selectedcontent() = default;
    constexpr selectedcontent(A ...args): selectedcontent::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($name, $open)]] details: element<details<A...>>, idl_interface<"HTMLElement"> {
    constexpr details() = default;
    constexpr details(A ...args): details::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($open, $returnValue)]] dialog: element<dialog<A...>>, idl_interface<"HTMLElement"> {
    constexpr dialog() = default;
    constexpr dialog(A ...args): dialog::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($src, $type, $noModule, $async, $defer, $crossOrigin, $text, $integrity, $referrerPolicy, $blocking, $fetchPriority, $charset, $event, $htmlFor)]] script: element<script<A...>>, idl_interface<"HTMLElement"> {
    constexpr script() = default;
    constexpr script(A ...args): script::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($name)]] slot: element<slot<A...>>, idl_interface<"HTMLElement"> {
    constexpr slot() = default;
    constexpr slot(A ...args): slot::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit($width, $height)]] canvas: element<canvas<A...>>, idl_interface<"HTMLElement"> {
    constexpr canvas() = default;
    constexpr canvas(A ...args): canvas::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] model: element<model<A...>> {
    constexpr model() = default;
    constexpr model(A ...args): model::element{ std::move(args)... } { }
};

template <class ...A> struct [[=permit()]] portal: element<portal<A...>> {
    constexpr portal() = default;
    constexpr portal(A ...args): portal::element{ std::move(args)... } { }
};

