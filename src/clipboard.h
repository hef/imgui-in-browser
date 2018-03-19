#pragma once
#include <string>
#include <memory>
#include <emscripten/val.h>


class Clipboard
{
public:
    static void init();
    static std::string data;
};
void onWebPasteEvent(emscripten::val e);

