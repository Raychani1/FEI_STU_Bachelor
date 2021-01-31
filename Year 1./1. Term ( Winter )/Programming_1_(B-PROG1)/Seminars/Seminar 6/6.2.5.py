# 5.
# Definujte funkciu, ktora bude nacitavat cisla z klavesnice, kym uzivatel nezada nulu. Po zadani
# nuly funkcia vrati pocet kolkokrat sa stalo, ze nacitane cislo bolo vacsie ako cislo nacitane pred
# nim. Napriklad pre postupnost cisel 1,8,9,2,4,-1,0 funkcia vrati cislo 4, pretoze 8>1, 9>8, 4>2 a 0>-1.


def vacsie():
    i = 0
    aktualne = int(input())
    predosle = aktualne

    while True:
        aktualne = int(input())

        if aktualne > predosle:
            i += 1

        predosle = aktualne
        if aktualne == 0:
            break

    return i


print(vacsie())
