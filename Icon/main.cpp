#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

static LRESULT wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
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
    wc.lpfnWndProc = wndProc;
    wc.lpszClassName = L"MyClass";
    wc.hIcon = LoadIconW(hInstance, MAKEINTRESOURCEW(101));
    RegisterClassW(&wc);
    HWND window = CreateWindowExW(0, L"MyClass", L"Hi", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}