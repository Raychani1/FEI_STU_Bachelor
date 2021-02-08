#include <stdio.h>

/*
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900
M             1000
*/

int main() {

    int n, i, r;

    printf("Zadajte cislo: ");
    scanf("%d", &n);
    printf("\nZadane cislo %d rimskymi cislicami: ", n);
    if (n >= 1000) {
        r = n / 1000;
        for (i = 0; i < r; i++) {
            printf("M");
        }
        n = n - r * 1000;
    }

    if (n < 1000 && n >= 900) {
        r = n / 900;
        for (i = 0; i < r; i++) {
            printf("CM");
        }
        n = n - r * 900;
    }
    if (n < 900 && n >= 500) {
        r = n / 500;
        for (i = 0; i < r; i++) {
            printf("D");
        }
        n = n - (r * 500);
    }
    if (n < 500 && n >= 400) {
        r = n / 400;
        for (i = 0; i < r; i++) {
            printf("CD");
        }
        n = n - r * 400;
    }
    if (n < 400 && n >= 100) {
        r = n / 100;
        for (i = 0; i < r; i++) {
            printf("C");
        }
        n = n - r * 100;
    }
    if (n < 100 && n >= 90) {
        r = n / 90;
        for (i = 0; i < r; i++) {
            printf("XC");
        }
        n = n - r * 90;
    }

    if (n < 90 && n >= 50) {
        r = n / 50;
        for (i = 0; i < r; i++) {
            printf("L");
        }
        n = n - r * 50;
    }
    if (n < 50 && n >= 40) {
        r = n / 40;
        for (i = 0; i < r; i++) {
            printf("XL");
        }
        n = n - r * 40;
    }
    if (n < 40 && n >= 10) {
        r = n / 10;
        for (i = 0; i < r; i++) {
            printf("X");
        }
        n = n - r * 10;
    }
    if (n < 10 && n >= 9) {
        r = n / 9;
        for (i = 0; i < r; i++) {
            printf("IX");
        }
        n = n - r * 9;
    }
    if (n < 9 && n >= 5) {
        r = n / 5;
        for (i = 0; i < r; i++) {
            printf("V");
        }
        n = n - r * 5;
    }
    if (n < 5 && n >= 4) {
        r = n / 4;
        for (i = 0; i < r; i++) {
            printf("IV");
        }
        n = n - r * 4;
    }
    if (n < 4 && n >= 1) {
        r = n / 1;
        for (i = 0; i < r; i++) {
            printf("I");
        }
        n = n - r * 1;
    }
    if (n == 0) {
        printf("\n");
        return 0;
    }
}