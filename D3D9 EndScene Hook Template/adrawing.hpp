#pragma once
#include <memory>
//#include "DirectX.h"

#pragma warning( disable : 4244 )
#pragma warning( disable : 4996 )

#include <d3dx9.h>
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")


typedef D3DCOLOR MY_D3DCOLOR;
typedef _D3DRECT MY_D3DRECT;

#define MY_D3DCOLOR_ARGB(a,r,g,b) \
		((MY_D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

namespace adrawing
{

	extern MY_D3DCOLOR BrightBlack;
	extern MY_D3DCOLOR DarkGrey;
	extern MY_D3DCOLOR BrightGrey;
	extern MY_D3DCOLOR White;
	extern //MY_D3DCOLOR myBlue = MY_D3DCOLOR_ARGB(255, 0, 122, 204);

	class draw
	{	
		IDirect3DDevice9Ex* device;
		ID3DXFont* smallFont;
		ID3DXFont* middleFont;

		bool m_initDrawing;
		bool m_cleanedUp;

	public:
		draw();
		~draw();

		void initDrawing(IDirect3DDevice9Ex* pDevice = nullptr);
		void cleanUp();

		void DrawStringCenter(const char* str, _D3DRECT rect, D3DCOLOR color, bool bigFont);
		void DrawStringLeft(const char* str, _D3DRECT rect, D3DCOLOR color, bool bigFont);
		void DrawFilledRectangle(_D3DRECT rect, D3DCOLOR color);

	};

	extern std::unique_ptr<draw> gDraw;
}