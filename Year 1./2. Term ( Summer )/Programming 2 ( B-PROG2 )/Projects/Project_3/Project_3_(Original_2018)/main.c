#include<stdio.h>
#include "cp_data1.h" // posledna zastavka 392
//#include "cp_data2.h" // posledna zastavka 180
//#include "cp_data3.h" // posledna zastavka  101
//#include "cp_data4.h"  // posledna zastavka  537

int zastavka = 1, volba;

int cp_data();

void vybrat_zastavku() {
    CLEAR_SCREEN();
    printf("Vyberte si zastavku:");
    scanf("%d", &zastavka);
}

int najblizsi_spoj() {
    CLEAR_SCREEN();
    int hodina = 0, minuta = 0;
    printf("\t Hodina: ");
    scanf("%d", &hodina);
    printf("\t Minuta: ");
    scanf("%d", &minuta);
    int key;
    int delt = (zastavka - 1) * DELTA;
    int h = PRVY_SPOJ_H, m;
    if (hodina < PRVY_SPOJ_H) {
        hodina = PRVY_SPOJ_H;
        minuta = PRVY_SPOJ_M;
    }
    for (m = PRVY_SPOJ_M + delt; m < 60; m = m + INTERVAL_NORMAL) {
        if (h - hodina == 0 && m - minuta >= 0) {
            hodina = h;
            minuta = m;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }
    if (h - hodina == 0 && minuta - m < 0) {
        hodina = h + m / 60;
        minuta = m % 60;
        printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
        printf("\n\n0 - vratit do menu: ");
        scanf("%d", &key);
        if (key == 0) {
            cp_data();
            return 0;
        }
    }


    for (h = RANO_START; h <= RANO_END; h++) {
        for (m = (m - 60); m < 60; m = m + INTERVAL_RANO) {
            if (h - hodina == 0 && m - minuta >= 0) {
                hodina = h;
                minuta = m;
                printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
                printf("\n\n0 - vratit do menu: ");
                scanf("%d", &key);
                if (key == 0) {
                    cp_data();
                    return 0;
                }
            }
        }
        if (h - hodina == 0 && minuta - m < 0) {
            hodina = h + m / 60;
            minuta = m % 60;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }

    for (h = RANO_END + 1; h < POOBEDE_START; h++) {
        for (m = (m - 60); m < 60; m = m + INTERVAL_NORMAL) {
            if (h - hodina == 0 && m - minuta >= 0) {

                hodina = h;
                minuta = m;
                printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
                printf("\n\n0 - vratit do menu: ");
                scanf("%d", &key);
                if (key == 0) {
                    cp_data();
                    return 0;
                }
            }
        }
        if (h - hodina == 0 && minuta - m < 0) {
            hodina = h + m / 60;
            minuta = m - 60;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }

    for (h = POOBEDE_START; h <= POOBEDE_END; h++) {
        for (m = (m - 60); m < 60; m = m + INTERVAL_POOBEDE) {
            if (h - hodina == 0 && m - minuta >= 0) {
                hodina = h;
                minuta = m;
                printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
                printf("\n\n0 - vratit do menu: ");
                scanf("%d", &key);
                if (key == 0) {
                    cp_data();
                    return 0;
                }
            }
        }
        if (h - hodina == 0 && minuta - m < 0) {
            hodina = h + m / 60;
            minuta = m % 60;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }

    for (h = POOBEDE_END + 1; h < POSLED_SPOJ_H; h++) {
        for (m = (m - 60); m < 60; m = m + INTERVAL_NORMAL) {
            if (h - hodina == 0 && m - minuta >= 0) {
                hodina = h;
                minuta = m;
                printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
                printf("\n\n0 - vratit do menu: ");
                scanf("%d", &key);
                if (key == 0) {
                    cp_data();
                    return 0;
                }
            }
        }
        if (h - hodina == 0 && minuta - m < 0) {
            hodina = h + m / 60;
            minuta = m - 60;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }
    //
    h = POSLED_SPOJ_H;
    for (m = (m - 60); m < 60; m = m + INTERVAL_NORMAL) {
        if (h - hodina == 0 && m - minuta >= 0) {
            hodina = h;
            minuta = m;
            printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
            printf("\n\n0 - vratit do menu: ");
            scanf("%d", &key);
            if (key == 0) {
                cp_data();
                return 0;
            }
        }
    }
    if (h - hodina == 0 && minuta - m < 0) {
        hodina = PRVY_SPOJ_H;
        minuta = PRVY_SPOJ_M;
        printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
        printf("\n\n0 - vratit do menu: ");
        scanf("%d", &key);
        if (key == 0) {
            cp_data();
            return 0;
        }
    }
    //
    if (hodina > POSLED_SPOJ_H) {
        if (hodina == 24) {
            hodina = 0;
        }
        hodina = PRVY_SPOJ_H;
        minuta = PRVY_SPOJ_M;
        printf("\n\t Najblizsi spoj: %02d:%02d", hodina, minuta);
        printf("\n\n0 - vratit do menu: ");
        scanf("%d", &key);
        if (key == 0) {
            cp_data();
            return 0;
        }
    }
}

void cestovny_poriadok() {
    CLEAR_SCREEN();
    int delt = (zastavka - 1) * DELTA;
    int h = PRVY_SPOJ_H, m;
    printf(" Hodina\t| Minuta\n...................................\n");
    printf(" %02d\t|  ", h);
    if ((PRVY_SPOJ_M + delt) > 60) {
        printf("NEPREMAVA\n");
        m = PRVY_SPOJ_M + delt;
    } else {
        for (m = PRVY_SPOJ_M + delt; m < 60; m = m + INTERVAL_NORMAL) {
            printf("%02d ", m);
        }
        printf("\n");
    }
    for (h = RANO_START; h <= RANO_END; h++) {
        printf(" %02d\t|  ", h);
        if ((m - 60) > 60) {
            printf("NEPREMAVA\n");
            m = m - 60;
        } else {
            for (m = (m - 60); m < 60; m = m + INTERVAL_RANO) {
                printf("%02d ", m);
            }
            printf("\n");
        }
    }
    for (h = RANO_END + 1; h < POOBEDE_START; h++) {
        printf(" %02d\t|  ", h);
        if ((m - 60) > 60) {
            printf("NEPREMAVA\n");
            m = m - 60;
        } else {
            for (m = (m - 60); m < 60; m = m + INTERVAL_NORMAL) {
                printf("%02d ", m);
            }
            printf("\n");
        }
    }
    for (h = POOBEDE_START; h <= POOBEDE_END; h++) {
        printf(" %d\t|  ", h);
        if ((m - 60) > 60) {
            printf("NEPREMAVA\n");
            m = m - 60;
        } else {
            for (m = (m - 60); m < 60; m = m + INTERVAL_POOBEDE) {
                printf("%02d ", m);
            }
            printf("\n");
        }
    }
    for (h = POOBEDE_END + 1; h <= POSLED_SPOJ_H; h++) {
        printf(" %d\t|  ", h);
        if ((m - 60) > 60) {
            printf("NEPREMAVA\n");
            m = m - 60;
        } else {

            for (m = (m - 60); m < 60; m = m + INTERVAL_NORMAL) {
                printf("%02d ", m);
            }
            printf("\n");
        }
    }
    printf("\n");
    int key;
    printf("\n\n0 - vratit do menu: ");
    scanf("%d", &key);
    if (key == 0) {
        cp_data();
    }

}

int cp_data() {
    int delt = (zastavka - 1) * DELTA;
    CLEAR_SCREEN();
    printf(" \t - - - - - - - - - - - - - - - -\n \t : \t CESTOVNY PORIADOK\t:\n..................................................\n \t\t 1. Vybrat zastavku\n \t\t 2. Ukazat cestovny poriadok\n \t\t 3. Najst najblizsi spoj\n \t\t 4. Koniec\n - - - - - - - - - - - - - - - - - - - - - - - - - \n \t\t Cislo zastavky: %d (+ %d min.)\n\nVolba:",
           zastavka, delt);
    scanf("%d", &volba);
    switch (volba) {
        case 1:
            vybrat_zastavku();
            cp_data();
            break;
        case 2:
            cestovny_poriadok();
            break;
        case 3:
            najblizsi_spoj();
            break;
        case 4:
            return 0;
            break;

    }
}

int main() {
    cp_data();
    return 0;
}