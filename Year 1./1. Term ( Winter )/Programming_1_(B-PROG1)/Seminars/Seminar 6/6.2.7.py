# 7.
# Definujte funkciu, ktora bude nacitavat cisla z klavesnice, kym uzivatel nezada nulu. Po zadani
# nuly funkcia vrati dlzku najdlhsej podpostupnosti po sebe iducich rovnakych cisel z postupnosti
# nacitanych cisel. Napriklad pre postupnost cisel 2,2,3,3,3,3,1,3,3,0 funkcia vrati cislo 4.


def grater():
    i = 1
    longest = 0
    actual = int(input())
    last = actual

    while True:
        actual = int(input())

        if actual == last:
            i += 1
        else:
            if longest < i:
                longest = i
            i = 1
        last = actual
        if actual == 0:
            break

    return longest


print(grater())
