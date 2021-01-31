# 3.
# Definujte funkciu minimum_dvoch, ktora bude mat dva parametre (cisla a,b), a ktora vrati
# minimum z tychto dvoch cisel.

def minimum_dvoch(a, b):
    if a < b:
        return a
    else:
        return b


def minimum_dvoch_input():
    a = int(input("a= "))
    b = int(input("b= "))
    print(minimum_dvoch(a, b))


# abint()

#############################################

a = int(input("a= "))
b = int(input("b= "))


def minimum_dvoch_v2(a, b):
    return min(a, b)


print(minimum_dvoch_v2(a, b))
