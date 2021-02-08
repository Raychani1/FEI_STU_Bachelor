#include <stdio.h>

void sucin() {
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    __asm
    {
    MOV EAX, a
    //SHL EAX, 1
    SHR EAX, 1
    MOV b, EAX
    }
    printf("a / 2 = %d", b);
    //printf("a * 2 = %d", b);
}


void main() {
    sucin();
}
