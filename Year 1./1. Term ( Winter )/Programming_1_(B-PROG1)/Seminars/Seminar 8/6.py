# 6.
# Definujte funkciu, ktorej argumentom bude zoznam. Funkcia vrati pocet takych prvkov, ktore sa
# v zozname vyskytuju prave raz.


def prave_raz(t):
    pocet = 0
    for item in t:
        vyskyt = 0
        for item2 in t:
            if item2 == item:
                vyskyt += 1
        if vyskyt == 1:
            pocet += 1

    return pocet


print(prave_raz(["k", "l", "l", "o"]))
