# 2.
# Definujte funkciu s parametrom n, ktora nacita n cisel z klavesnice a vrati sucet nacitanych cisel

def sum_of_n(n):
    s = 0
    for _ in range(n):
        x = int(input("Cislo: "))
        s += x

    return s


print(sum_of_n(3))
