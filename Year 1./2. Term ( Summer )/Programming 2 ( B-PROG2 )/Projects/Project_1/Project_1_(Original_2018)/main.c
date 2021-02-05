#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int get_speed(int v) {
    int x = 0;
    if (v == 0) {
        x = rand() % 101 + 350;
    } else {
        int rych = rand() % 20 - 5;
        x = v + rych;
    }
    return x;
}

int main() {
    int v_bezec1 = 0, v_bezec2 = 0, d_bezec1 = 0, d_bezec2 = 0, sec = 0, najvacsia1 = 0, najvacsia2 = 0, spadol1 = 0, spadol2 = 0, total_dist = 40000;
    srand(time(NULL));
    while (d_bezec1 < total_dist && d_bezec2 < total_dist) {
        sec = sec + 1;
        v_bezec1 = get_speed(v_bezec1);
        if (v_bezec1 > najvacsia1) {
            najvacsia1 = v_bezec1;
        }
        d_bezec1 = d_bezec1 + v_bezec1;
        double d_b1m = (0.01 * d_bezec1);
        double kilo1 = (0.036 * v_bezec1);
        double perecent1 = (float) d_bezec1 / total_dist * 100.0;
        printf("VB1: %d cm/s \t (%.2f km/h)\t", v_bezec1, kilo1);
        printf("DB1: %d cm \t (%.2f m) \t (%.2f%%)\n", d_bezec1, d_b1m, perecent1);

        if (d_bezec1 < total_dist && d_bezec1 % 5000 == 0) {
            printf("\n\t\t\tBezec 1 narazil do prekazky!!!\n\n");
            v_bezec1 = 0;
            spadol1 = spadol1 + 1;
        }


        v_bezec2 = get_speed(v_bezec2);
        if (v_bezec2 > najvacsia2) {
            najvacsia2 = v_bezec2;
        }
        d_bezec2 = d_bezec2 + v_bezec2;
        double d_b2m = (0.01 * d_bezec2);
        double kilo2 = (0.036 * v_bezec2);
        double perecent2 = (float) d_bezec2 / total_dist * 100.0;
        printf("VB2: %d cm/s \t (%.2f km/h)\t", v_bezec2, kilo2);
        printf("DB2: %d cm \t (%.2f m) \t (%.2f%%)\n", d_bezec2, d_b2m, perecent2);

        if (d_bezec2 < total_dist && d_bezec2 % 5000 == 0) {
            printf("\n\t\t\tBezec 2 narazil do prekazky!!!\n\n");
            v_bezec2 = 0;
            spadol2 = spadol2 + 1;
        }


        if (d_bezec2 >= total_dist || d_bezec1 >= total_dist) {
            break;
        }
        printf("________________________________________________________________________________\n");

    }
    int m, s;
    m = sec / 60;
    s = sec - (m * 60);
    if (d_bezec1 >= total_dist) {
        printf("________________________________________________________________________________\n\n");
        double kilozah1 = (0.036 * najvacsia1);
        printf("Vyhral 1. bezec, za %d sekund (%d minut %d sekund) s najvacsou rychlostou %d cm/s (%.2f km/h), spadol %d x!\n",
               sec, m, s, najvacsia1, kilozah1, spadol1);
    }
    if (d_bezec2 >= total_dist) {
        printf("________________________________________________________________________________\n\n");
        double kilozah2 = (0.036 * najvacsia2);
        printf("Vyhral 2. bezec, za %d sekund (%d minut %d sekund) s najvacsou rychlostou %d cm/s (%.2f km/h), spadol %d x!\n",
               sec, m, s, najvacsia2, kilozah2, spadol2);
    }


    return 0;
}

