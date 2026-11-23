#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
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
    wc.lpszClassName = L"class";
    wc.lpfnWndProc = WndProc;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(0, L"class", L"Hi", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    CreateWindowExW(0, L"Button", L"Click me", WS_CHILD | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, hwnd, nullptr, hInstance, nullptr);

    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}