#pragma once
#pragma comment(lib, "d3dx9.lib")

#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <d3dx9.h>
#include <d3d9.h>

#include "d3dHooking.h"

static HWND window;

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam);

HWND GetProcessWindow();

bool GetD3D9Device(void ** pTable, size_t Size);

bool GetD3D11SwapchainDeviceContext(void ** pSwapchainTable, size_t Size_Swapchain, void ** pDeviceTable, size_t Size_Device, void ** pContextTable, size_t Size_Context);