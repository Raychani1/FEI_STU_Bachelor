# 4.
# Definujte funkciu minimum_troch, ktora bude mat tri parametre (cisla a,b,c), a ktora vrati
# minimum z tychto troch cisel.

def minimum_troch(a, b, c):
    if (a < b) and (a < c):
        return a
    elif (b < a) and (b < c):
        return b
    elif (c < a) and (c < b):
        return c


def minimum_troch_input_v1():
    a = int(input("a= "))
    b = int(input("b= "))
    c = int(input("c= "))
    print(minimum_troch(a, b, c))


minimum_troch_input_v1()


################################################

def minimum_troch_v2(a, b, c):
    return min(a, b, c)


def minimum_troch_input_v2():
    a = int(input("a= "))
    b = int(input("b= "))
    c = int(input("c= "))
    print(minimum_troch_v2(a, b, c))


minimum_troch_input_v2()
