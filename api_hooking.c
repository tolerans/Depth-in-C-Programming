#include <Windows.h>

typedef int (WINAPI *pMessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT);
int WINAPI MyMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);

int main (void) {

    printf("Debug\n");
    return EXIT_SUCCESS;
}