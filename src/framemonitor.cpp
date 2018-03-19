#include "framemonitor.h"
#include "imgui.h"
#include <emscripten/emscripten.h>
#include <string>
#include <emscripten/html5.h>

FrameMonitor::FrameMonitor()
{
    values.resize(60,0);
    lastTime = emscripten_get_now();
}

void FrameMonitor::debugDraw()
{
    std::string overlay = std::to_string(values[0]);
    ImGui::Begin("Performance", &bShow);
    ImGui::Text("Hello, World!");
    ImGui::PlotHistogram(
            "frametime",
            values.data(),
            values.size(),
            0,
            overlay.c_str(),
            0.0f,
            100.0f,
            ImVec2(0,100)
    );
    ImGui::Text("width: %d, height: %d, fullscreen: %d",width,height,isFullscreen);
    bool goFullscreen = ImGui::Button("Fullscreen");
    if(goFullscreen)
    {
        emscripten_request_fullscreen("canvas",true);
    }
    ImGui::End();
}

void FrameMonitor::update()
{
    if(bShow)
    {
        double newTime = emscripten_get_now();
        values[frame++%values.size()] = newTime - lastTime;
        lastTime = newTime;

        emscripten_get_canvas_size(&width, &height, &isFullscreen);

    }
}
