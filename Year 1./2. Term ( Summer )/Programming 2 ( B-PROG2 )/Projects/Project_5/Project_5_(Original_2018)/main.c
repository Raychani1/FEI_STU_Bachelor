#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "median_filter.h"

void main()
{
    double input_signal[MAX_DATA_SIZE];
    double output_signal[MAX_DATA_SIZE];
    int w =5;
    int x= loadData(&input_signal, MAX_DATA_SIZE);
    filterData(&input_signal,&output_signal, x,w);
    printData(output_signal, x);
}