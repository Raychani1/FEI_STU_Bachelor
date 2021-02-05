#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 150
#define MAX_NAME 20
#define MAX_ZAM 20
#define POZ 6

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else

#include <unistd.h>

#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

char *pozicie[POZ] = {"Web_developer", "App._tester", "Programmer", "Developer", "Java_developer", "C\\C++_developer"};

typedef struct {
    int den;
    int mesiac;
    int rok;
} Datum;

typedef struct {
    char meno[MAX_LEN];
    Datum d_narod;
} Osobne_udaje;

typedef struct {
    int id;
    char pozicia[MAX_LEN];
    double plat;
    Osobne_udaje udaje;
} Zamestnanec;

Zamestnanec genZamestnanca();

void genZamestnancov(Zamestnanec db[], int n);

void printZamestnanec(const Zamestnanec *z);

void printAll(Zamestnanec db[], int n);

int main() {
    srand((unsigned int) time(0));
    Zamestnanec db[MAX_ZAM];
    genZamestnancov(db, MAX_ZAM);
    char prikaz[MAX_LEN];
    char slovo[MAX_LEN];
    int offset = 0;
    int c = 0;
    printf("Prikaz: ");
    while (fgets(prikaz, MAX_LEN, stdin)) {

        offset = 0;
        sscanf(prikaz + offset, "%s", slovo);
        if (!strcmp(slovo, "exit")) { return 0; }
        if (!strcmp(slovo, "clear")) {
            CLEAR_SCREEN();
            printf("Prikaz: ");
            continue;
        }
        if (!strcmp(slovo, "show")) {
            offset += strlen(slovo);
            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                if (!strcmp(slovo, "all")) {
                    offset += strlen(slovo) + 1;
                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                        if (!strcmp(slovo, "where")) {
                            offset += strlen(slovo) + 1;
                            Zamestnanec db2[MAX_ZAM];
                            c = 0;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                if (!strcmp(slovo, "id")) {
                                    int id = 0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id == id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id <= id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id >= id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "plat")) {
                                    double plat = 0.0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat == plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat <= plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat >= plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "pozicia")) {
                                    char *poz = NULL;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) == 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) < 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) > 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "meno")) {
                                    char *meno = NULL;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) == 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) < 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) > 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "datum")) {
                                    int den_nar = 0, mes_nar = 0, rok_nar = 0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if ((db[i].udaje.d_narod.den == den_nar) &&
                                                                (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                (db[i].udaje.d_narod.rok == rok_nar)) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if (((db[i].udaje.d_narod.den < den_nar) &&
                                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.mesiac < mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.rok < rok_nar))) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if (((db[i].udaje.d_narod.den > den_nar) &&
                                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.mesiac > mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok >= rok_nar)) ||
                                                                ((db[i].udaje.d_narod.rok > rok_nar))) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                if (!strcmp(slovo, "sort")) {
                                    offset += strlen(slovo) + 1;
                                    Zamestnanec db3[MAX_ZAM];
                                    for (int i = 0; i < MAX_ZAM; i++) {
                                        db3[i] = db2[i];
                                    }
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "id")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (db3[i].id - db3[j].id < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "plat")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (db3[i].plat - db3[j].plat < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "meno")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (strcmp(db3[i].udaje.meno, db3[j].udaje.meno) < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "pozicia")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (strcmp(db3[i].pozicia, db3[j].pozicia) < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "datum")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (((db3[i].udaje.d_narod.rok == db3[j].udaje.d_narod.rok) &&
                                                         (db3[i].udaje.d_narod.mesiac == db3[j].udaje.d_narod.mesiac) &&
                                                         (db3[i].udaje.d_narod.den - db3[j].udaje.d_narod.den < 0)) ||
                                                        ((db3[i].udaje.d_narod.rok == db3[j].udaje.d_narod.rok) &&
                                                         (db3[i].udaje.d_narod.mesiac - db3[j].udaje.d_narod.mesiac <
                                                          0)) ||
                                                        (db3[i].udaje.d_narod.rok - db3[j].udaje.d_narod.rok < 0)) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    printAll(db3, c);
                                }
                            } else
                                printAll(db2, c);
                        }
                    } else
                        printAll(db, MAX_ZAM);
                } else {
                    int k = atoi(slovo);
                    offset += strlen(slovo) + 1;
                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                        if (!strcmp(slovo, "where")) {
                            offset += strlen(slovo) + 1;
                            Zamestnanec db2[MAX_ZAM];
                            int c = 0;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                if (!strcmp(slovo, "id")) {
                                    int id = 0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id == id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id <= id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                id = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].id >= id) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "plat")) {
                                    double plat = 0.0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat == plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat <= plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                plat = atoi(slovo);
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (db[i].plat >= plat) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "pozicia")) {
                                    char *poz = NULL;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) == 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) < 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                poz = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].pozicia, poz) > 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "meno")) {
                                    char *meno = NULL;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) == 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) < 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                meno = slovo;
                                                for (int i = 0; i < MAX_ZAM; i++) {
                                                    if (strcmp(db[i].udaje.meno, meno) > 0) {
                                                        db2[c] = db[i];
                                                        c++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if (!strcmp(slovo, "datum")) {
                                    int den_nar = 0, mes_nar = 0, rok_nar = 0;
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "=")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if ((db[i].udaje.d_narod.den == den_nar) &&
                                                                (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                (db[i].udaje.d_narod.rok == rok_nar)) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, "<")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if (((db[i].udaje.d_narod.den < den_nar) &&
                                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.mesiac < mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.rok < rok_nar))) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (!strcmp(slovo, ">")) {
                                            offset += strlen(slovo) + 1;
                                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                den_nar = atoi(slovo);
                                                offset += strlen(slovo) + 1;
                                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                    mes_nar = atoi(slovo);
                                                    offset += strlen(slovo) + 1;
                                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                                        rok_nar = atoi(slovo);
                                                        for (int i = 0; i < MAX_ZAM; i++) {
                                                            if (((db[i].udaje.d_narod.den > den_nar) &&
                                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                                ((db[i].udaje.d_narod.mesiac > mes_nar) &&
                                                                 (db[i].udaje.d_narod.rok >= rok_nar)) ||
                                                                ((db[i].udaje.d_narod.rok > rok_nar))) {
                                                                db2[c] = db[i];
                                                                c++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                if (!strcmp(slovo, "sort")) {
                                    offset += strlen(slovo) + 1;
                                    Zamestnanec db3[MAX_ZAM];
                                    for (int i = 0; i < MAX_ZAM; i++) {
                                        db3[i] = db2[i];
                                    }
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        if (!strcmp(slovo, "id")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (db3[i].id - db3[j].id < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "plat")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (db3[i].plat - db3[j].plat < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "meno")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (strcmp(db3[i].udaje.meno, db3[j].udaje.meno) < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "pozicia")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (strcmp(db3[i].pozicia, db3[j].pozicia) < 0) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        } else if (!strcmp(slovo, "datum")) {
                                            Zamestnanec tmp;
                                            for (int i = 0; i < c; i++) {
                                                for (int j = 0; j < c; j++) {
                                                    if (((db3[i].udaje.d_narod.rok == db3[j].udaje.d_narod.rok) &&
                                                         (db3[i].udaje.d_narod.mesiac == db3[j].udaje.d_narod.mesiac) &&
                                                         (db3[i].udaje.d_narod.den - db3[j].udaje.d_narod.den < 0)) ||
                                                        ((db3[i].udaje.d_narod.rok == db3[j].udaje.d_narod.rok) &&
                                                         (db3[i].udaje.d_narod.mesiac - db3[j].udaje.d_narod.mesiac <
                                                          0)) ||
                                                        (db3[i].udaje.d_narod.rok - db3[j].udaje.d_narod.rok < 0)) {
                                                        tmp = db3[i];
                                                        db3[i] = db3[j];
                                                        db3[j] = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    printAll(db3, k);
                                }
                            } else
                                printAll(db2, k);
                        }
                    } else
                        printAll(db, k);
                }
            }
        }
        printf("\nPrikaz: ");
    }
}

Zamestnanec genZamestnanca() {
    Zamestnanec z;
    z.id = rand() % 1000;
    z.plat = rand() % 2000 + 2000;
    strcpy(z.pozicia, pozicie[rand() % POZ]);
    int rand_len = rand() % MAX_NAME + 1;
    for (int i = 0; i < rand_len; i++) {
        z.udaje.meno[i] = rand() % ('z' - 'a') + 'a';
    }
    z.udaje.meno[rand_len] = '\0';
    z.udaje.d_narod.den = rand() % 31 + 1;
    z.udaje.d_narod.mesiac = rand() % 12 + 1;
    z.udaje.d_narod.rok = rand() % 31 + 1980;
    return z;
}

void genZamestnancov(Zamestnanec db[], int n) {
    for (int i = 0; i < n; i++) {
        db[i] = genZamestnanca();
    }
}

void printZamestnanec(const Zamestnanec *z) {
    int number = strlen(z->udaje.meno);
    int distance = 30 - number;
    printf("\t%d\t|\t %.2lf\t|\t%s\t\t|\t%s", z->id, z->plat, z->pozicia, z->udaje.meno);
    for (int i = 0; i < distance; i++) {
        printf(" ");
    }
    printf("|\t %d / %d\ / %d\n", z->udaje.d_narod.den, z->udaje.d_narod.mesiac, z->udaje.d_narod.rok);
}

void printAll(Zamestnanec db[], int n) {
    printf("\n\tID\t|\t Plat\t\t|\tPozicia\t\t\t|\tMeno");
    for (int i = 0; i < 26; i++) {
        printf(" ");
    }
    printf("|\tDatum narodenia\n--------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printZamestnanec(&db[i]);
    }
}