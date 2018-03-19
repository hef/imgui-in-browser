#pragma once
class Download {
    char url[512];
    int handle = -1;
    int m_progress = 0;
    int m_total = 0;
    static void onLoad(unsigned unknown, void* arg, void* data, unsigned size);
    static void onError(unsigned unknown, void* arg, int httpErrorCode, const char* httpError);
    static void onProgress(unsigned unknown, void* arg, int progres, int total);
public:
    void debugDraw();
    void download();
};
