#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <Windows.h>

static LRESULT wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            std::cout << "PAINT" << std::endl;
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            TextOutW(hdc, 0, 0, L"Hello!", 6);
            TextOutW(hdc, 0, 20, L"你好!", 3);
            TextOutW(hdc, 0, 40, L"こんにちは！", 6);
            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    WNDCLASSW wc{};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = wndProc;
    wc.lpszClassName = L"MyClass";
    RegisterClassW(&wc);
    HWND hwnd = CreateWindowExW(0, L"MyClass", L"Hi", WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}