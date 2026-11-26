#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <ShlObj.h>
#include <iostream>

static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nShowCmd) {
    WNDCLASSW wc{};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"MyClass";
    RegisterClassW(&wc);
    HWND hwnd = CreateWindowExW(0, L"MyClass", L"Hi", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!IsUserAnAdmin()) {
        MessageBoxW(hwnd, L"Current: Non-Admin", L"INFO", MB_OK);
        wchar_t path[128];
        GetModuleFileNameW(nullptr, path, 128);
        ShellExecuteW(hwnd, L"runas", path, nullptr, nullptr, nShowCmd);
        return 0;
    }
    MessageBoxW(hwnd, L"Current: Admin", L"INFO", MB_OK);

    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
