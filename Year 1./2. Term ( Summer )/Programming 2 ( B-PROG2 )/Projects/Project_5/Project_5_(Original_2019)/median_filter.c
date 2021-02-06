#include "median_filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// POPIS: Funkcia na nacitanie vstupneho signalu do pola 'input', ktore ma kapacitu 'n' prvkov.
// Hodnoty vstupneho signalu sa nacitaju zo standardneho vstupu (presmerovanim zo suboru).
// VSTUP:
//      * input - smernik na zaciatok pola, kde bude ulozeny vstupny signal
//      * n - dlzka pola 'input' (jeho max. kapacita)
// VYSTUP:
//      * funkcia vrati pocet realne nacitanych vzoriek (prvkov) vstupneho signalu
double input_signal[MAX_DATA_SIZE];
int loadData(double* input, int n)
{
    // TODO: nacitajte zo standardneho vstupu prvky vstupneho signalu
    // do pola 'input' a nakoniec vratte pocet nacitanych prvkov

    // Pre CMD

    int i = 0;
    double val;
    while (scanf("%lf", &val) != EOF)
    {
        input[i] = val;
        printf("%lf\n", input[i]);
        i++;
    }
    return i;

    // Pre Visual Studio

    /*
    FILE *myFile;
    myFile = fopen("signal.txt", "r");

    int i=0;
    double val;
    while (!feof(myFile))
    {
        fscanf(myFile,"%lf",&input[i]);
        printf("%lf\n", input[i]);
        i++;
    }

    return i;
    */
}
// POPIS: Funkcia, ktora aplikuje 1D medianovy filter na signal v poli 'input'.
// Prefiltruje sa 'k' prvkov vstupneho signalu. Na filtrovanie sa pouzije okno
// s velkostou 2*'w'+1. Vystupny prefiltrovany signal bude ulozeny v poli 'output'.
// VSTUP:
//      * input - smernik na zaciatok pola, kde bude ulozeny vstupny signal
//      * output - smernik na zaciatok pola, kde bude ulozeny vystupny prefiltrovany signal
//      * k - pocet prvkov vstupneho signalu, ktore treba prefiltrovat
//      * w - parameter pre vypocet velkosti filtrovacieho okna, velkost okna je urcena ako 2*'w'+1
// VYSTUP:
//      * funkcia nic nevracia
double median(double *data, int n);
// TODO: medianovym filtrom prefiltrujte vstupny signal v poli 'input' a
// ulozte ho do vystupneho pola 'output'. Prefiltruje sa 'k' prvkov z
// pola 'input'. Na filtrovanie sa pouzije okno o velkosti 2*'w'+1.
// DOLEZITE: na hladanie medianu pouzite vasu funkciu 'median' (pozri nizsie).
void filterData(double *input, double* output, int k, int w)
{
    int j = 0;
    double med_sig[MAX_DATA_SIZE];
    int l = (2 * w) + 1;

    for (j; j <=k-l; j++)
    {

        for (int i = 0; i < l; i++)
        {
            med_sig[i] = input[j+i];

        }

        for (int f = 0; f < w; f++)
        {
            output[f] = input[f];
        }

        output[j+w] = median(&med_sig, l);
        for (int f = (k -w); f < k; f++)
        {
            output[f] = input[f];
        }
    }
}
// POPIS: Funkcia, ktora najde a vrati median z prvkov pola 'data'.
// VSTUP:
//      * data - smernik na zaciatok pola, v ktorom hladame median
//      * n - dlzka pola 'data'
// VYSTUP:
//      * funkcia vrati median zo vsetkych 'n' prvkov pola 'data'
int compare(const void * a, const void * b)
{
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}
double median(double *data, int n)
{
    // TODO: najdite a vratte median pola 'data', ktore ma 'n' prvkov.
    /*
    printf("\n\nBefore sorting the list is: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }
    */
    qsort(data, n, sizeof(double), compare);
    /*printf("\n\nAfter sorting the list is: \n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
    }*/

    return data[(n - 1) / 2];
}
// POPIS: Funkcia, ktora vypise pole 'data'.
// VSTUP:
//      * data - smernik na zaciatok pola, ktore chceme vypisat
//      * n - dlzka pola 'data'
// VYSTUP:
//      * funkcia nic nevracia
void printData(double *data1, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.*lf\n",PRECISION, data1[i]);
    }
    // TODO: vypiste na standardny vystup vsetky prvky pola 'data'
    // s desatinnou presnostou, ktora je dana konstantou 'PRECISION'
    // (pozri subor median_filter.h). Prvky pola budu vypisane pod
    // seba (pouzite klasicku funkciu 'printf').
    // Priklad: (pre PRECISION=6)
    // 0.568912
    // 1.001241
    // 2.325014
    // 0.124683
    // ...
    // ... atd.
}