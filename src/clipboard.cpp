#include "clipboard.h"
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <stdio.h>

std::string Clipboard::data;
void Clipboard::init()
{
    EM_ASM(document.addEventListener("paste",Module.onWebPasteEvent,false););
}

void onWebPasteEvent(emscripten::val e)
{
    emscripten::val clipboardData = e["clipboardData"];
    emscripten::val textData = clipboardData.call<emscripten::val>("getData", std::string("text/plain"));
    Clipboard::data = textData.as<std::string>();
    printf("clipboard paste: %s\n", Clipboard::data.c_str());
}

EMSCRIPTEN_BINDINGS(foo){
   emscripten::function("onWebPasteEvent",&onWebPasteEvent);
}
