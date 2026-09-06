// rev-c3d90e-20260902 main.cpp
// Mythos 5.1 Desktop - Entry point
#include "../include/Core.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int show) {
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    M5::Core core;
    if (!core.Init(hInst)) return 1;
    return core.Loop();
}
