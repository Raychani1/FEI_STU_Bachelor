#include<stdio.h>

int main() {
    char str[12];

    __asm
    {
    mov EAX, 0
    cpuid
    mov DWORD PTR  str[0], EBX
    mov DWORD PTR  str[4], EDX
    mov DWORD PTR  str[8], ECX
    }

    printf("Typ Procesora je: ");
    for (int i = 0; i < 12; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}