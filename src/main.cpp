#include "main.h"
#include "draw.h"
#include "funimgui.h"
#include <stdio.h>
#include <imgui.h>
#include "framemonitor.h"
#include <emscripten/emscripten.h>
#include "download.h"
#include "clipboard.h"
static Draw GDraw;
static FrameMonitor* gFrameMonitor = nullptr;
static Download* gDownload = nullptr;

EMSCRIPTEN_KEEPALIVE
bool init()
{
    
    bool result = GDraw.init();
    FunImGui::init();
    gFrameMonitor = new FrameMonitor;
    gDownload = new Download;
    Clipboard::init();
    return result;
}

EMSCRIPTEN_KEEPALIVE
void loop()
{
    static bool bShowTestWindow = true;
    FunImGui::BeginFrame();
    //gFrameMonitor->update();
    //gFrameMonitor->debugDraw();
    //gDownload->debugDraw();
    ImGui::ShowDemoWindow(&bShowTestWindow);
    Draw::clear();
    ImGui::Render();
}
