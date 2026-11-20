#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <Windows.h>

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM uParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, uParam, lParam);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    std::cout << "\33[0;34m" << "[PID] " << GetCurrentProcessId() << std::endl;
    WNDCLASS wc{};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = L"myClass";
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(L"myClass", L"Hello Win32", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    if (hwnd == nullptr) {
        return -1;
    }
    ShowWindow(hwnd, nShowCmd);
    MSG msg{};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}