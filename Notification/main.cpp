#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <windows.h>
#include <shellapi.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nShowCmd) {
    HWND hwnd = CreateWindowExW(0, L"STATIC", L"", 0, 0, 0, 0, 0, nullptr, nullptr, hInstance, nullptr);
    NOTIFYICONDATAW nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATAW);
    nid.hWnd = hwnd;
    nid.uID = 100;
    nid.uFlags = NIF_INFO | NIF_ICON;
    nid.hIcon = LoadIconW(nullptr, IDI_INFORMATION);
    lstrcpyW(nid.szInfo, L"Hi!");
    lstrcpyW(nid.szInfoTitle, L"A notification");
    bool bTray = Shell_NotifyIconW(NIM_ADD, &nid);
    if (!bTray) {
        std::cerr << "Fail to create the tray" << std::endl;
        return -1;
    }
    Sleep(3000);
    bool bDelete = Shell_NotifyIconW(NIM_DELETE, &nid);
    if (!bDelete) {
        std::cerr << "Fail to send the notification" << std::endl;
        return -1;
    }
    DestroyWindow(hwnd);
    return 0;
}