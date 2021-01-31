# 1.
# Definujte funkciu, ktora bude nacitavat cisla z klavesnice, kym uzivatel nezada zaporne cislo
# alebo nulu. Po zadani zaporneho cisla alebo nuly funkcia vrati sucet kladnych nacitanych cisel.
# Otestujte funkciu pre postupnost vstupov 1,5,-5.

def zapnulsuc():
    s = 0

    while True:
        n = int(input())
        if n <= 0:
            break
        s += n
    return s


print(zapnulsuc())
