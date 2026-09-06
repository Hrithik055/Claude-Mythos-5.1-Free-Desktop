// rev-c3d90e-20260902 Core.cpp
// Mythos 5.1 Desktop - Core shell
#include "../include/Core.h"

namespace M5 {

bool Core::Init(HINSTANCE hInst) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "M5Desktop";
    wc.hbrBackground = CreateSolidBrush(RGB(28, 28, 32));
    RegisterClass(&wc);
    HWND hwnd = CreateWindowEx(WS_EX_ACCEPTFILES, "M5Desktop", "Mythos 5.1 Desktop",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1100, 720,
        nullptr, nullptr, hInst, nullptr);
    DragAcceptFiles(hwnd, TRUE);
    ShowWindow(hwnd, SW_SHOW);
    return hwnd != nullptr;
}

int Core::Loop() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

} // namespace M5
