#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    WNDCLASSW wc{};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"MyClass";
    RegisterClassW(&wc);
    HWND hwnd = CreateWindowExW(0, L"MyClass", L"Hello WIN32", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    std::cout << "\33[34m[PID]\33[0m Current process: " << GetCurrentProcessId() << std::endl;
    STARTUPINFOW si{};
    PROCESS_INFORMATION pi{};
    std::wstring cmd = L"notepad.exe";
    CreateProcessW(nullptr, cmd.data(), nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi);
    std::cout << "\33[34m[PID]\33[0m New process: " << pi.dwProcessId << std::endl;

    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}