#include "download.h"
#include "imgui.h"
#include "emscripten/emscripten.h"


void Download::onLoad(unsigned unknown, void* arg, void* data, unsigned size)
{
}

void Download::onError(unsigned unknown, void* arg, int httpErrorCode, const char* httpError)
{
}

void Download::onProgress(unsigned unknown, void* arg, int progress, int total)
{
   Download* d = (Download*)arg;
   d->m_progress = progress;
   d->m_total = total;
}
void Download::debugDraw()
{
    ImGui::Begin("Download");
    ImGui::InputText("url", url, 512);
    ImGui::ProgressBar((float)m_progress/(float)m_total,ImVec2(0.0f,0.0f));
    bool doDownload = ImGui::Button("Download");
    if(doDownload)
    {
        download();
    }
    ImGui::End();
}

void Download::download()
{
    handle = emscripten_async_wget2_data(
        url, "GET", nullptr, this, true, &onLoad, &onError, onProgress
    );
}
