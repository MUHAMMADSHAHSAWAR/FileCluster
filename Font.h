#pragma once

#include <Windows.h>
#include <string>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")

namespace TkinterWindow
{
	class Font
	{
	private:
		// Variables
		HFONT hFont;
		bool ItalicFont = false;
		bool underLineFont = false;
		bool midLineFont = false;
		int heightFont = 0;
		int sizeFont = 15;
		int weightFont = 0;
		int fontEscapment = 0;
		int fontOrientation = 0;
		std::string styleFont = "Comicsans";

	public:
		// Functions
		__declspec (dllexport) HFONT GetFont(HDC hDC);
		__declspec (dllexport) void DeleteFontObject();
		__declspec (dllexport) void SetItalicFontStyle(bool italicStyle);
		__declspec (dllexport) void SetMidLineFontStyle(bool midLineStyle);
		__declspec (dllexport) void SetFontWeight(int fontWeight);
		__declspec (dllexport) void SetFontSize(int fontSize);
		__declspec (dllexport) void SetFontWidth(int fontWidth);
		__declspec (dllexport) void SetFontHeight(int fontHeight);
		__declspec (dllexport) void SetUnderLineFontStyle(bool underLineStyle);
		__declspec (dllexport) void SetFontEscapment(int degree);
		__declspec (dllexport) void SetFontOrientation(int degree);
		__declspec (dllexport) void SetFontStyle(std::string fontStyle);
	};
}
