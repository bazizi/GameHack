// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

void WINAPI MainThread()
{
    unsigned char *lmp = nullptr;
    // 00428E4C   895C05 00        MOV DWORD PTR SS:[EBP+EAX],EBX           ; VisualBo.00640444
    lmp = (unsigned char*)0x55F700C;
    unsigned char* lHP = (unsigned char*)0x142BE0D0;
    while (true)
    {
        if (*lmp < 0x63)
        {
            *lmp = 0x63;
        }
        //if (*lHP < 0x63)
        //{
        //    *lHP = 0x63;
        //}
        Sleep(1000);
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);

        if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL) {
            return FALSE;
        }

        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

