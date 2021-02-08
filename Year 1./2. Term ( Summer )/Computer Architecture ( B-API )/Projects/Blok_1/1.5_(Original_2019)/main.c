#include<stdio.h>
#include <string.h>

int main() {
    char hexa[] = ":10010000214601360121470136007EFE09D21901XX"; //40
    //char hexa[] = ":100010000C9445000C9445000C9445000C944500xx"; //4C
    //char hexa[] = ":100020000C9445000C9445000C9445000C944500xx"; //3C
    //char hexa[] = ":100030000C9445000C9445000C9445000C944500xx"; //2C
    //char hexa[] = ":100040000C9445000C9445000C9445000C944500xx"; //1C
    //char hexa[] = ":100000000C942A000C9445000C9445000C944500xx"; //77

    int length = strlen(hexa);
    int checksum = 0;
    int cislo = 0;
    int cislo1 = 0;
    int cislo2 = 0;
    for (int i = 1; i < length - 2; i += 2) {
        switch (hexa[i]) {
            case '0':
                cislo1 = 0;
                break;
            case '1':
                cislo1 = 1;
                break;
            case '2':
                cislo1 = 2;
                break;
            case '3':
                cislo1 = 3;
                break;
            case '4':
                cislo1 = 4;
                break;
            case '5':
                cislo1 = 5;
                break;
            case '6':
                cislo1 = 6;
                break;
            case '7':
                cislo1 = 7;
                break;
            case '8':
                cislo1 = 8;
                break;
            case '9':
                cislo1 = 9;
                break;
            case 'A':
                cislo1 = 10;
                break;
            case 'B':
                cislo1 = 11;
                break;
            case 'C':
                cislo1 = 12;
                break;
            case 'D':
                cislo1 = 13;
                break;
            case 'E':
                cislo1 = 14;
                break;
            case 'F':
                cislo1 = 15;
                break;
        }

        switch (hexa[i + 1]) {
            case '0':
                cislo2 = 0;
                break;
            case '1':
                cislo2 = 1;
                break;
            case '2':
                cislo2 = 2;
                break;
            case '3':
                cislo2 = 3;
                break;
            case '4':
                cislo2 = 4;
                break;
            case '5':
                cislo2 = 5;
                break;
            case '6':
                cislo2 = 6;
                break;
            case '7':
                cislo2 = 7;
                break;
            case '8':
                cislo2 = 8;
                break;
            case '9':
                cislo2 = 9;
                break;
            case 'A':
                cislo2 = 10;
                break;
            case 'B':
                cislo2 = 11;
                break;
            case 'C':
                cislo2 = 12;
                break;
            case 'D':
                cislo2 = 13;
                break;
            case 'E':
                cislo2 = 14;
                break;
            case 'F':
                cislo2 = 15;
                break;
        }
        checksum += cislo1 * 16 + cislo2;
    }
    checksum = 256 - checksum % 256;

    printf("CHECKSUM: %X \n", checksum);

    return 0;
}