#include "pixlpch.h"
#include "Window.h"

namespace PIXL {
    HWND Window::hwnd = nullptr;

	void PIXL::Window::Init(WinArgs args) 
	{
        WNDCLASSEXW wc = { 0 };
        wc.cbSize = sizeof(WNDCLASSEXW);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WindowProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = args.hins;
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = L"PIXLWindow";
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

        RegisterClassExW(&wc);

        hwnd = CreateWindowExW(
            0,
            wc.lpszClassName,
            L"PIXL window",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            1280,
            720,
            NULL,
            NULL,
            args.hins,
            NULL
        );

        ShowWindow(hwnd, args.showcmd);
	}

    LRESULT CALLBACK PIXL::Window::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcW(hwnd, msg, wparam, lparam);
        }
    }

}