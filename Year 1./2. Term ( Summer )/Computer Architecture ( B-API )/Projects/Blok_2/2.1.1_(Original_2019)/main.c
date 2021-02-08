#include<stdio.h>

int add() {
    int a, b, c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    __asm {
    MOV EAX, a
    MOV ECX, b
    ADD EAX, ECX
    MOV c, EAX
    }
    printf("\na + b = %d \n", c);
    getchar();
    return 0;

}

void main() {
    add();
}