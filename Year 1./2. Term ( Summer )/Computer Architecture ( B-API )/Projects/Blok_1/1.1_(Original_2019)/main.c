#include <stdio.h>


int binary(int x) {
    int a[50], i;
    for (i = 0; x > 0; i++) {
        a[i] = x % 2;
        x = x / 2;
    }
    for (i = i - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    return 0;
}

int main() {
    char m;
    printf("Zadajte znak: ");
    scanf("%c", &m);
    printf("\n%c v deka = %d", m, m);
    printf("\n%c v binarnom = ", m);
    binary(m);
    printf("\n%c v octa = %o", m, m);
    printf("\n%c v hexa = %x\n", m, m);

    int n;
    printf("\nZadajte cislo: ");
    scanf("%d", &n);
    printf("\n%d v binarnom = ", n);
    binary(n);
    printf("\n%d v octa = %o", n, n);
    printf("\n%d v hexa = %x\n", n, n);
    return 0;
}