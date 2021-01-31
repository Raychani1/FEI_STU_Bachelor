# 3.
# Definujte funkciu s parametrom n, ktora vrati najvacsie prirodzene cislo x take, ze 2
# x je mensie ako n. Priklad: pre n=10 funkcia vrati cislo 3. Skuste ulohu vyriesit bez pouzitia operacie **.


def funkcia2x(n):
    x = 0
    mocnina = 1
    while mocnina < n:
        x = x + 1
        mocnina = 2 * mocnina
    return x - 1


print(funkcia2x(1025))
