# 1.
# Definujte funkciu s parametrom n, ktora nacita n cisel z klavesnice a vrati pocet nacitanych cisel,
# ktore boli delitelne cislom 5.

def n_5_div(n):
    p = 0
    for _ in range(n):
        x = int(input("Zadajte cislo: "))
        if x % 5 == 0:
            p += 1
    return p


print(n_5_div(6))
