#pragma once

#include <Windows.h>
#include <string>

#define EXPORTFUNCTION __declspec(dllexport) 

namespace function
{
    #define WM_DATAMESSAGEBYPARENTWINDOW 0x0400 + 1

    typedef struct 
    {
        // [ Starting ] Label Styles.
        COLORREF labelBackgroundColor = RGB(0, 12, 24);
        COLORREF labelTextColor = RGB(255, 255, 255);
        int labelBorderRadius = 14;
        COLORREF labelBorderColor = RGB(0, 12, 24);
        // [ Ending ] Label Styles.

        // [ Starting ] Window Styles.
        COLORREF windowBackgroundColor = RGB(0, 12, 24);
        COLORREF windowBorderColorFocused = RGB(0, 148, 255);
        COLORREF windowBorderColorUnFocused = RGB(100, 100, 100);
        COLORREF windowTitleBarBackgroundColor = RGB(16, 25, 44);
        int windowBorderRadius = 14;
        COLORREF windowTitleBarTextColorFocused = RGB(204, 204, 204);
        COLORREF windowTitleBarTextColorUnFocused = RGB(100, 100, 100);
        COLORREF windowCloseButtonHoverColor = RGB(210, 17, 35);
        COLORREF windowCloseButtonTextHoverColor = RGB(200, 200, 200);
        COLORREF windowCloseButtonTextColor = RGB(200, 200, 200);
        COLORREF windowTitleBarButtonTextColor = RGB(200, 200, 200);
        COLORREF windowTitleBarButtonTextHoverColor = RGB(200, 200, 200);
        COLORREF windowTitleBarButtonsHoverColor = RGB(40, 48, 65);
        COLORREF windowStatusBarBackgroundColor = RGB(0, 148, 255);
        // [ Ending ] Window Styles.

    } TKINTERWINDOWTHEME;

    typedef struct 
    {
        int labelTextAlignment = DT_CENTER | DT_VCENTER | DT_SINGLELINE;
        int labelBorderWidth = 1;
        int labelBorderStyle = PS_SOLID;
    } LABELTHEME;

    typedef TKINTERWINDOWTHEME (*TKINTERWINDOWTHEMEFUNCTION)();
    COLORREF transparentColor = RGB(1, 1, 1);
}
