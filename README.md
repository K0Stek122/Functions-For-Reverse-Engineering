# Functions-For-Reverse-Engineering
Functions To Get You Started For Hacking Games !
Game hacking kit that has all the hacking functions you need.

This repository has following files:
  - Functions.cpp
  - Functions.hpp
  
  - d3dHooking.cpp
  - d3dHooking.h
  
  - detours.h
  - detours.lib
---
<b>Functions file contains 2 namespaces:</b>
  - internalFuncs
  - externalFuncs
  
    - internalFuncs contains following functions:
      - GetModuleInfo
      - PatternScan
      - Patch
      - Nop
      - FindDmaAddy
      - FunctionHook
      
    - externalFuncs contains following functions:
      - GetProcID
      - GetModuleEntry
      - GetModuleBaseAddy
      - FindDmaAddyEx
      - PatternScanEx
      - PatternScanExModule
      - PatchEx
      - NopEx
      - FunctionHookEx
---
<b>d3dHooking file contains 4 functions:</b>
  - EnumWindowsCallback
  - GetProcessWindow
  - GetD3D9Device
  - GetD3D11SwapchainDeviceContext
---
<b>detours file is a microsoft library for detouring functions:</b>
  - See Github: [Microsoft Detours](https://github.com/Microsoft/Detours)
  
---
<b>Credits:</b>
  - Thanks to [GuidedHacking.com](https://Guidedhacking.com) for their tutorials on gamehacking
