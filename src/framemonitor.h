#pragma once
#include <vector>
class FrameMonitor
{
    bool bShow = true;
    std::vector<float> values;
    int frame = 0;
    double lastTime = 0.0;

    int width = 0;
    int height = 0;
    int isFullscreen = 0;
    
public:
    FrameMonitor();
    void debugDraw();
    void update();
};
