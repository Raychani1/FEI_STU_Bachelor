# 3.
# Definujte funkciu s parametrom n, ktora nacita n cisel z klavesnice a vrati najmensie nacitane
# cislo. Otestujte vasu funkciu pre pripad, ze nacitane cisla su 8, 2, -1000, 1.

def minimal(n):
    minim = int(input("Cislo: "))
    for _ in range(n - 1):
        x = int(input("Cislo: "))
        if x < minim:
            minim = x
    return minim


print(minimal(4))
