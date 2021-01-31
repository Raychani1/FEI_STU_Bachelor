# 3.
# Definujte funkciu, ktorej argumentom bude zoznam cisel. Funkcia vrati sucet tych cisel, ktore sa
# v zozname nachadzaju na poziciach s parnym indexom.

def parne_pozicie(t):
    sucet = 0
    for i in range(len(t)):
        if i % 2 == 0:
            sucet += t[i]
    return sucet


print(parne_pozicie([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
