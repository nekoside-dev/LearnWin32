#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <Windows.h>
#include <glad/glad.h>

static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            std::cout << "WM_PAINT" << std::endl;
            PAINTSTRUCT ps{};
            HDC hdc = BeginPaint(hwnd, &ps);

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            SwapBuffers(hdc);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    WNDCLASSW wc{};
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"MyClass";
    wc.style = CS_OWNDC;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(0, L"MyClass", L"Hi", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
    HDC hdc = GetDC(hwnd);
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.dwFlags = PFD_DOUBLEBUFFER;
    int format = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, format, &pfd);
    HGLRC hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);
    if (!gladLoadGL()) {
        MessageBoxW(nullptr, L"Failed to load glad", L"Error", MB_OK);
        return -1;
    }
    ShowWindow(hwnd, nShowCmd);

    MSG msg{};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}