# 6.
# Definujte funkciu, ktora bude nacitavat cisla z klavesnice, kym uzivatel nezada nulu. Po zadani
# nuly funkcia vrati kolko z nacitanych cisel je rovnych najvacsiemu nacitanemu cislu. Napriklad pre
# postupnost cisel 2,8,3,8,0 funkcia vrati cislo 2. Otestujte vasu funkciu pre postupnost
# 2,2,2,2,8,1,8,1,8,0

def funkcia():
    maxi = int(input())
    pocet_max = 1
    if maxi == 0:
        return 1
    while True:
        cislo = int(input())
        if cislo == maxi:
            pocet_max += 1
        if cislo > maxi:
            maxi = cislo
            pocet_max = 1

        if cislo == 0:
            break
    return pocet_max


print(funkcia())
