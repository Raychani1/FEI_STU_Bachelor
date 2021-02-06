#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000
#define MAX_LEN 150
#define MAX_NAME 20

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


typedef struct {
    int pocet;
    char **pole;
} Riadky;
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

void printZamestnanec(const Zamestnanec *z);

void printAll(Zamestnanec db[], int n);

int nElements = 0;

int main() {
    int initialSize = 2;
    int size = initialSize;
    Zamestnanec *db;
    int r, j = 0;
    db = (Zamestnanec *) calloc(initialSize, sizeof(Zamestnanec));

    FILE *fp;
    char str[MAXCHAR];
    fp = fopen("database.txt", "r");

    while (!feof(fp)) {
        fgets(str, MAXCHAR, fp);
        nElements++;
        char *pch = NULL;
        int i = 0;
        pch = strtok(str, " ");

        while (pch != NULL) {
            if (nElements == size) {
                size += 1;
                db = (Zamestnanec *) realloc(db, size * sizeof(Zamestnanec));
            }
            switch (i) {
                case 0:
                    db[j].id = atoi(pch);
                    break;
                case 1:
                    db[j].plat = atoi(pch);
                    break;
                case 2:
                    strcpy(db[j].pozicia, pch);
                    break;
                case 3:
                    strcpy(db[j].udaje.meno, pch);
                    break;
                case 4:
                    db[j].udaje.d_narod.den = atoi(pch);
                    break;
                case 5:
                    db[j].udaje.d_narod.mesiac = atoi(pch);
                    break;
                case 6:
                    db[j].udaje.d_narod.rok = atoi(pch);
                    j++;
                    break;
            }
            i++;
            pch = strtok(NULL, " ");
        }
    }
    fclose(fp);
    //
    srand((unsigned int) time(0));
    int poc_zam = nElements - 1;
    printAll(db, poc_zam);
    char prikaz[MAX_LEN];
    char slovo[MAX_LEN];
    int offset = 0;
    int c = 0;
    printf("Prikaz: ");
    while (fgets(prikaz, MAX_LEN, stdin)) {

        /*fp = fopen("database.txt", "r+");
        fputs(db[0].id, fp);
        /*for (int d = 0; d < poc_zam; d++) {
            fputs(db[d].id, fp);
            fputs((int)db[d].plat, fp);
            fputs(db[d].pozicia, fp);
            fputs(db[d].udaje.meno, fp);
            fputs(db[d].udaje.d_narod.den, fp);
            fputs(db[d].udaje.d_narod.mesiac, fp);
            fputs(db[d].udaje.d_narod.rok, fp);
            fputs("\n", fp);
        }
        fclose(fp);*/
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
                            Zamestnanec *db2;
                            db2 = (Zamestnanec *) calloc(poc_zam, sizeof(Zamestnanec *));
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                    Zamestnanec *db3;
                                    db3 = (Zamestnanec *) calloc(poc_zam, sizeof(Zamestnanec *));
                                    for (int i = 0; i < poc_zam; i++) {
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
                        printAll(db, poc_zam);
                } else {
                    int k = atoi(slovo);
                    offset += strlen(slovo) + 1;
                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                        if (!strcmp(slovo, "where")) {
                            offset += strlen(slovo) + 1;
                            Zamestnanec *db2;
                            db2 = (Zamestnanec *) calloc(poc_zam, sizeof(Zamestnanec *));
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                                        for (int i = 0; i < poc_zam; i++) {
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
                                    Zamestnanec *db3;
                                    db3 = (Zamestnanec *) calloc(poc_zam, sizeof(Zamestnanec *));
                                    for (int i = 0; i < poc_zam; i++) {
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
        if (!strcmp(slovo, "insert")) {
            offset += strlen(slovo);
            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                db[poc_zam].id = atoi(slovo);
                offset += strlen(slovo) + 1;
                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                    db[poc_zam].plat = atoi(slovo);
                    offset += strlen(slovo) + 1;
                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                        char pozicia[MAX_LEN];
                        strcpy(db[poc_zam].pozicia, slovo);
                        offset += strlen(slovo) + 1;
                        if (sscanf(prikaz + offset, "%s", slovo) == 1) {

                            strcpy(db[poc_zam].udaje.meno, slovo);
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                db[poc_zam].udaje.d_narod.den = atoi(slovo);
                                offset += strlen(slovo) + 1;
                                if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                    db[poc_zam].udaje.d_narod.mesiac = atoi(slovo);
                                    offset += strlen(slovo) + 1;
                                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                        db[poc_zam].udaje.d_narod.rok = atoi(slovo);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            poc_zam++;
            db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
        }
        if (!strcmp(slovo, "delete")) {
            offset += strlen(slovo);
            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                if (!strcmp(slovo, "id")) {
                    int id = 0;
                    offset += strlen(slovo) + 1;
                    if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                        if (!strcmp(slovo, "=")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                id = atoi(slovo);
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].id == id) {

                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, "<")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                id = atoi(slovo);
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].id <= id) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, ">")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                id = atoi(slovo);
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].id >= id) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
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
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].plat == plat) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, "<")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                plat = atoi(slovo);
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].plat <= plat) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, ">")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                plat = atoi(slovo);
                                for (int i = 0; i < poc_zam; i++) {
                                    if (db[i].plat >= plat) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
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
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].pozicia, poz) == 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, "<")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                poz = slovo;
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].pozicia, poz) < 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, ">")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                poz = slovo;
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].pozicia, poz) > 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
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
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].udaje.meno, meno) == 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, "<")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                meno = slovo;
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].udaje.meno, meno) < 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
                                    }
                                }
                            }
                        }
                        if (!strcmp(slovo, ">")) {
                            offset += strlen(slovo) + 1;
                            if (sscanf(prikaz + offset, "%s", slovo) == 1) {
                                meno = slovo;
                                for (int i = 0; i < poc_zam; i++) {
                                    if (strcmp(db[i].udaje.meno, meno) > 0) {
                                        for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                        poc_zam--;
                                        db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                        i = 0;
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
                                        for (int i = 0; i < poc_zam; i++) {
                                            if ((db[i].udaje.d_narod.den == den_nar) &&
                                                (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                (db[i].udaje.d_narod.rok == rok_nar)) {
                                                for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                                poc_zam--;
                                                db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                                i = 0;
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
                                        for (int i = 0; i < poc_zam; i++) {
                                            if (((db[i].udaje.d_narod.den < den_nar) &&
                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                ((db[i].udaje.d_narod.mesiac < mes_nar) &&
                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                ((db[i].udaje.d_narod.rok < rok_nar))) {
                                                for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                                poc_zam--;
                                                db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                                i = 0;
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
                                        for (int i = 0; i < poc_zam; i++) {
                                            if (((db[i].udaje.d_narod.den > den_nar) &&
                                                 (db[i].udaje.d_narod.mesiac == mes_nar) &&
                                                 (db[i].udaje.d_narod.rok == rok_nar)) ||
                                                ((db[i].udaje.d_narod.mesiac > mes_nar) &&
                                                 (db[i].udaje.d_narod.rok >= rok_nar)) ||
                                                ((db[i].udaje.d_narod.rok > rok_nar))) {
                                                for (int j = i; j < poc_zam; j++) { db[j] = db[j + 1]; }

                                                poc_zam--;
                                                db = (Zamestnanec *) realloc(db, poc_zam * sizeof(Zamestnanec *));
                                                i = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
        printf("\nPrikaz: ");
    }
}

void printZamestnanec(const Zamestnanec *z) {
    int number = strlen(z->udaje.meno);
    int job_number = strlen(z->pozicia);
    int job_distance = 24 - job_number;
    int distance = 30 - number;
    printf("\t%d\t|\t %.2lf\t|\t%s", z->id, z->plat, z->pozicia);
    for (int j = 0; j < job_distance; j++) {
        printf(" ");
    }
    printf("|\t%s", z->udaje.meno);
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
    printf("|\tDatum narodenia\n---------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printZamestnanec(&db[i]);
    }
}