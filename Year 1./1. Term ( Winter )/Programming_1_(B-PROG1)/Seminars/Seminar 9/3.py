# 3.
# Definujte funkciu, s nasledovnymi vlastnostami. Argumentom funkcie bude zoznam t. Prvky
# zoznamu t budu zoznamy obsahujuce dve cisla. Nech [a, b] je prvok zoznamu t. Zoznam [a,b] bude
# reprezentovat otvoreny interval od cisla a po cislo b (budeme predpokladat, ze v kazdom z
# vnutornych zoznamov je cislo na 0-tom indexe mensie ako cislo na 1-vom indexe). To znamena, ze
# zoznam t budeme chapat, ako zoznam intervalov. Funkcia vrati hodnotu True, ak je spolocny
# prienik vsetkych intervalov v zozname t neprazdny. Inak vrati funkcia hodnotu False.

def prienik_dvoch(t1, t2):
    if t2[0] <= t1[0] <= t2[1] <= t1[1]:
        return [t1[0], t2[1]]
    elif t2[0] <= t1[0] and t1[1] <= t2[1]:
        return [t1[0], t1[1]]
    elif t1[0] <= t2[0] <= t1[1] and t2[1] <= t1[1]:
        return [t2[0], t2[1]]
    elif t1[0] <= t2[0] <= t1[1] <= t2[1]:
        return [t2[0], t1[1]]
    else:
        return []


def prienik(t):
    prvy_interval = t[0]
    for i in range(1, len(t)):
        prvy_interval = prienik_dvoch(prvy_interval, t[i])
        if not prvy_interval:
            return False
    return True


t = [[1, 10], [2, 12]]
t1 = [[1, 2], [3, 4]]
t2 = [[1, 10], [1, 11], [3, 12], [4, 13], [5, 15], [6, 16], [7, 17]]


print(prienik(t2))
