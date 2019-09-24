#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <Psapi.h>
#include <vector>
#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

namespace externalFuncs
{
	//Gets Process ID (usage: 
	DWORD GetProcID(wchar_t* exeName);

	//Get Module Entry (usage: GetModuleEntry(procID, "ModuleName.dll"))
	MODULEENTRY32 GetModuleEntry(DWORD dwProcID, wchar_t* moduleName);

	//Get Module Base Address (usage: GetModuleBaseAddy(procID, "ModuleName.dll"))
	uintptr_t GetModuleBaseAddy(DWORD procID, const wchar_t* moduleName);

	//Find MultiLevel Pointer (usage: FindDmaAddyEx(hProcess, baseAddress, MultiPointers))
	uintptr_t FindDmaAddyEx(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);

	//External Pattern Scan Wrapper (usage: DO NOT FUCKING USE)
	void* PatternScanEx(HANDLE hProcess, uintptr_t begin, uintptr_t end, char* pattern, char* mask);

	//External Pattern Scan (usage: PatternScanExModule(hProcess, "coolExe.exe", "moduleName.dll", "\x78\xB2\xA7", "xx??x"))
	void* PatternScanExModule(HANDLE hProcess, wchar_t* exeName, wchar_t* moduleName, char* pattern, char* mask);

	//External patch (usage: PatchEx(hProcess, (BYTE*)moduleBase + Addy, (BYTE*)\x89\xNEW\xBYTES, 3))
	void PatchEx(HANDLE hProcess, BYTE* dst, BYTE* src, unsigned int size);

	//External Nop (usage: NopEx(hProcess, AssemblyAddy, amountOfBytes))
	void NopEx(HANDLE hProcess, void* dst, unsigned int size);

	//External Function Hook
	bool FunctionHookEx(HANDLE hProcess, void* whereToHook, void* function, int length);

	//For Finding Variables Externally
	DWORD FindSigs(DWORD procID, HANDLE hProcess, uintptr_t gameModule, const char* pattern);
}

namespace internalFuncs
{
	//Get Module Info (idk why but there u go: usage: GetModuleInfo("InternalModuleName.dll"))
	MODULEINFO GetModuleInfo(char* Module);

	//Pattern Scan, Cool Stuff (usage: PatternScan("ModuleName.dll", BytesToRead, "\x87\x65\xA7\xB3", "xx?xxx????xx"))
	void* PatternScan(char* base, size_t size, char* pattern, char* mask);

	//Internal Patch (usage: Patch((BYTE*)moduleBase + Addy), (BYTE*)\x89\xNEW\xBYTES))
	void Patch(BYTE* dst, BYTE* src, unsigned int size);

	//Internal Nop (usage: AssemblyAddy, amountOfBytes)
	void Nop(BYTE* dst, unsigned int size);

	//Find MultiLevel Pointer (usage: FindDmaAddy(baseAddy, MultiLevel Pointer))
	uintptr_t FindDmaAddy(uintptr_t ptr, std::vector<unsigned int> offsets);

	//Internal Function Hook
	bool FunctionHook(void* whereToHook, void* function, int length);

	//For Finding Variables
	DWORD FindSigs(std::string moduleName, std::string pattern);
}