#include <stdio.h>
#include <math.h>

const double PI = 3.1415926535897932384650288;

int faktorial(int a) {
    int k = 1;
    for (int i = 1; i <= a; i++) {
        k = k * i;
    }
    return k;
}

float sinus(float x, float epsilon) {
    x *= PI / 180.0;
    float rad = x;
    double sum = 0;

    double zlomok = x;

    int a;
    int i = 1;
    for (i = 1; i < 2 * x + 1; i++)
        sum += zlomok;
    double citatel = pow(x, i);
    double menovatel = faktorial(i);
    a = pow(-1, i);
    zlomok = citatel * a / menovatel;

    return sum;
}


int main() {
    double x, ans;
    scanf("%lf", &x);
    ans = sinus(x, 0.0001);
    printf("%lf", ans);
    return 0;
}