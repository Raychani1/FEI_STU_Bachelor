# 7.
# Definujte funkciu s parametrom n, ktora vrati sucet 1**2+2**2+3**2+...+n**2
# (Vo funkcii pouzite for-cyklus.)

def squared_sum(n):
    s = 0
    for i in range(1, n + 1):
        s += i ** 2
    return s


print(squared_sum(4))
