#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <Windows.h>

static HWND g_HWND;

static LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            if (hwnd == g_HWND) {
                PostQuitMessage(0);
                return 0;
            }
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    WNDCLASSW wc{};
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyClass";
    wc.lpfnWndProc = wndProc;
    RegisterClassW(&wc);
    g_HWND = CreateWindowExW(0, L"MyClass", L"Hello Win32", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    HWND child = CreateWindowExW(0, L"MyClass", L"I am a child window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, g_HWND, nullptr, hInstance, nullptr);
    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}