#include "Drawing.h"

ID3DXFont* pFont;

void drawing::CreateFontFunc(IDirect3DDevice9* pDevice, LPCWSTR choiceFont)
{
	D3DXCreateFont(pDevice, 15, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		choiceFont, &pFont);
}

void drawing::DrawTextFunc(LPCSTR string, int x, int y, D3DCOLOR color)
{
	RECT rect;
	rect.left = x;
	rect.top = y;
	pFont->DrawTextA(NULL, string, -1, &rect, DT_NOCLIP, color);
}

void drawing::DrawFilledRectangle(IDirect3DDevice9* pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void drawing::DrawBorderBox(IDirect3DDevice9* pDevice, int x, int y, int w, int h, int thickness, D3DCOLOR color)
{
	DrawFilledRectangle(pDevice, x, y, w, thickness, color); // x
	DrawFilledRectangle(pDevice, x, y, thickness, h, color); // y
	DrawFilledRectangle(pDevice, x + w, y, thickness, h, color); // w
	DrawFilledRectangle(pDevice, x, y + h, w + thickness, thickness, color); // h
}