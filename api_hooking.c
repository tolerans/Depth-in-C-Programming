#include <windows.h>

#define SIZE 6

typedef int (WINAPI *pMessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT);
int WINAPI MyMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);

void BeginRedirect(LPVOID);

pMessageBoxW pOrigMBAddress = NULL;
BYTE oldBytes[SIZE] = {0};
BYTE JMP[SIZE] = {0};
DWORD oldProtect, myProtect = PAGE_EXECUTE_READWRITE;

INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved)
{
    switch(Reason)
    {
    case DLL_PROCESS_ATTACH:
        pOrigMBAddress = (pMessageBoxW)
            GetProcAddress(GetModuleHandle("user32.dll"), 
                           "MessageBoxW");
        if(pOrigMBAddress != NULL)
            BeginRedirect(MyMessageBoxW);    
        break;
    case DLL_PROCESS_DETACH:
        memcpy(pOrigMBAddress, oldBytes, SIZE);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}

void BeginRedirect(LPVOID newFunction)
{
    BYTE tempJMP[SIZE] = {0xE9, 0x90, 0x90, 0x90, 0x90, 0xC3};
    memcpy(JMP, tempJMP, SIZE);
    DWORD JMPSize = ((DWORD)newFunction - (DWORD)pOrigMBAddress - 5);
    VirtualProtect((LPVOID)pOrigMBAddress, SIZE, 
                    PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(oldBytes, pOrigMBAddress, SIZE);
    memcpy(&JMP[1], &JMPSize, 4);
    memcpy(pOrigMBAddress, JMP, SIZE);
    VirtualProtect((LPVOID)pOrigMBAddress, SIZE, oldProtect, NULL);
}

int  WINAPI MyMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uiType)
{
    VirtualProtect((LPVOID)pOrigMBAddress, SIZE, myProtect, NULL);
    memcpy(pOrigMBAddress, oldBytes, SIZE);
    int retValue = MessageBoxW(hWnd, lpText, lpCaption, uiType);
    memcpy(pOrigMBAddress, JMP, SIZE);
    VirtualProtect((LPVOID)pOrigMBAddress, SIZE, oldProtect, NULL);
    MessageBoxW(NULL, L"This should pop up", L"Hooked MBW", MB_ICONEXCLAMATION);
    return retValue;
}
