#include "ThemeController.h"
#include <Windows.h>
#include <gdiplus.h>
#include <windowsx.h>
#include "Font.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "Font.lib")

namespace function
{
    typedef struct
    {
        bool closeButtonHover = false;
        bool minimizeButtonHover = false;
        bool maximizeButtonHover = false;
        bool settingButtonHover = false;
        bool trackingMouse = false;
    } PROCEDURECONTROLLER;

    typedef struct
    {
        int startXPosition = 0;
        int startYPosition = 0;
        bool fullScreen = false;
        bool maximizeWindow = false;
    } STATECONTROLLER;
}

namespace TkinterWindow
{
    class Window
    {
        private:
            // Variables
            WNDCLASSEXA __windowClass;
            LPCSTR __windowClassName = (LPCSTR)"TkinterWindow-Window";
            HWND __windowHandle = NULL;
            int __x = GetSystemMetrics(SM_CXSCREEN) / 2 - (800 / 2), __y = GetSystemMetrics(SM_CYSCREEN) / 2 - (600 / 2), __width = 800, __height = 600;
            HINSTANCE __hInstance;
            function::TKINTERWINDOWTHEME __tkinterWindowTheme;
            std::string __windowText = "TkinterWindow";
            MSG __message;
            Gdiplus::GdiplusStartupInput __gdiplusStartupInput;
            ULONG_PTR __gdiplusToken;
            HICON __focusedWindowIcon = NULL, __unfocusedWindowIcon = NULL;
            TkinterWindow::Font __titleTextFont;
            function::PROCEDURECONTROLLER __procedureController;
            RECT __closeButtonRect, __minimizeButtonRect, __maximizeButtonRect, __settingButtonRect;
            function::STATECONTROLLER __stateController;
            std::string __statusBarText = "Ready..";
            
            // Functions
            static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
            LRESULT TkinterWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
            void __RePaintWindow();
            RECT __GetTitleBarRect(HWND hWnd);
            HICON __LoadImageFromFile(std::string path);
            void __DrawCloseButton(HDC hDC, bool painting = false);
            void __DrawMaximizeButton(HDC hDC);
            void __DrawMinimizeButton(HDC hDC);
            void __DrawSettingButton(HDC hDC);

        public:
            // Variables
            HWND self;
            HWND Self;

            // Functions
            EXPORTFUNCTION void InitializeWindow(HINSTANCE hInstance, std::string sWindowClassName = "TkinterWindow-Window");
            EXPORTFUNCTION void StartMainLoop(int nMin = 0, int nMax = 0);

            // [ Starting ] Setting Icons
            EXPORTFUNCTION void SetWindowTaskBarIcon(std::string sPath);
            EXPORTFUNCTION void SetTaskBarIcon(std::string sPath);

            EXPORTFUNCTION void SetWindowFocusedIcon(std::string sPath);
            EXPORTFUNCTION void SetFocusedIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowFocusIcon(std::string sPath);
            EXPORTFUNCTION void SetFocusIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowHoverIcon(std::string sPath);
            EXPORTFUNCTION void SetHoverIcon(std::string sPath);

            EXPORTFUNCTION void SetWindowUnFocusedIcon(std::string path);
            EXPORTFUNCTION void SetUnFocusedIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowUnfocusIcon(std::string sPath);
            EXPORTFUNCTION void SetUnfocusIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowUnFocusIcon(std::string path);
            EXPORTFUNCTION void SetUnFocusIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowUnHoverIcon(std::string path);
            EXPORTFUNCTION void SetUnHoverIcon(std::string sPath);
            EXPORTFUNCTION void SetWindowUnfocusedIcon(std::string path);
            EXPORTFUNCTION void SetUnfocusedIcon(std::string sPath);
            // [ Ending ] Setting Icons.

            // [ Starting ] Setting window title.
            EXPORTFUNCTION void SetWindowTitle(std::string sWindowTitle);
            EXPORTFUNCTION void SetTitle(std::string sWindowTitle);
            EXPORTFUNCTION void SetWindowText(std::string sWindowTitle);
            EXPORTFUNCTION void SetText(std::string sWindowTitle);
            EXPORTFUNCTION void SetWindowName(std::string sWindowTitle);
            EXPORTFUNCTION void SetName(std::string sWindowTitle);
            EXPORTFUNCTION void SetWindowCaption(std::string sWindowTitle);
            EXPORTFUNCTION void SetCaption(std::string sWindowTitle);
            EXPORTFUNCTION void SetWindowLabel(std::string sWindowTitle);
            EXPORTFUNCTION void SetLabel(std::string sWindowTitle);
            // [ Ending ] Setting window title.

            // [ Starting ] Setting border color.
            EXPORTFUNCTION void SetWindowBorderFocusedColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowBorderFocusColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowBorderHoverColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderFocusedColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderFocusColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderHoverColor(int nRed, int nGreen, int nBlue);

            EXPORTFUNCTION void SetWindowBorderUnFocusedColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowBorderUnfocusColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowBorderUnFocusColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowBorderUnHoverColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderUnFocusedColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderUnfocusColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetBorderUnHoverColor(int nRed, int nGreen, int nBlue);
            // [ Ending ] Setting border color.

            // [ Starting ] Setting the window text color.
            EXPORTFUNCTION void SetWindowFocusedTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowFocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowHoverTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetFocusedTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetFocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetHoverTextColor(int nRed, int nGreen, int nBlue);

            EXPORTFUNCTION void SetWindowUnFocusedTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowUnfocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowUnFocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowUnHoverTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetUnFocusedTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetUnfocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetUnFocusTextColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetUnHoverTextColor(int nRed, int nGreen, int nBlue);
            // [ Ending ] Setting the window text color.

            // [ Starting ] Setting the title bar background color.
            EXPORTFUNCTION void SetWindowTitleBarBackgroundColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetTitleBarBackgroundColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowCaptionBarBackgroundColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetCaptionBarBackgroundColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowTitleBarColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetTitleBarColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetWindowCaptionBarColor(int nRed, int nGreen, int nBlue);
            EXPORTFUNCTION void SetCaptionBarColor(int nRed, int nGreen, int nBlue);
            // [ Ending ] Setting the title bar background color.

            // [ Starting ] Setting title bar button text color.
            // [ Ending ] Setting title bar button text color.

            // [ Starting ] Setting title bar button background color.
            // [ Ending ] setting title bar button background color.
     };
}
