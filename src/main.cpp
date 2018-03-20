#include "main.h"
#include "draw.h"
#include "funimgui.h"
#include <stdio.h>
#include <imgui.h>
#include <emscripten/emscripten.h>
static Draw GDraw;

EMSCRIPTEN_KEEPALIVE
bool init()
{
    
    bool result = GDraw.init();
    FunImGui::init();
    return result;
}

EMSCRIPTEN_KEEPALIVE
void loop()
{
    static bool bShowTestWindow = true;
    FunImGui::BeginFrame();
    ImGui::ShowDemoWindow(&bShowTestWindow);
    Draw::clear();
    ImGui::Render();
}
