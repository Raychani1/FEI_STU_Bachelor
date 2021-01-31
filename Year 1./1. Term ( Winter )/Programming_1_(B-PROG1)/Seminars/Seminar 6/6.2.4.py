# 4.
# Definujte funkciu, ktora bude nacitavat cisla z klavesnice, kym uzivatel nezada nulu. Po zadani
# nuly funkcia vrati poradove cislo najvacsieho nacitaneho cisla. Napriklad pre postupnost cisel -5,
# -4, -3, 0 funkcia vrati cislo 4, lebo najvacsie cislo (v tomto pripade je to cislo 0) bolo nacitane ako
# stvrte. Pre postupnost -5, 2, 8, 1, 0 zase funkcia vrati cislo 3.


def maxpoz():
    i = 1
    miesto = 1
    maximum = cislo = int(input())
    while True:
        if cislo == 0:
            break
        i += 1
        cislo = int(input())
        if cislo > maximum:
            miesto = i
            maximum = cislo

    return miesto


print(maxpoz())
