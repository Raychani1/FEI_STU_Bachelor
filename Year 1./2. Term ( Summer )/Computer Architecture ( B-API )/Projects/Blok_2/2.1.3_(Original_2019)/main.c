#include <stdio.h>

int uloha13() {
    int a, b = 10, c;
    scanf("%d", &a);
    __asm
    {
    MOV EAX, a
    MOV EBX, b
    CMP EBX, EAX
    JB V2
    JA V1
    V1:
    ADD EAX, 48
    JMP END

    V2:
    ADD EAX, 55
    JMP END

    END:
    MOV c, EAX
    }
    printf("%c", (char) c);

}

void main() {
    uloha13();
}