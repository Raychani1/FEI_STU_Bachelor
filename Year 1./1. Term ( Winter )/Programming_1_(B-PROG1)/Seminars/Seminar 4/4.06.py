# 6.
# Definujte funkciu pocet_rovnakych, ktora bude mat tri parametre (cisla a,b,c). Funkcia vrati cislo
# 3, ak su vsetky tri cisla a,b,c rovnake, vrati cislo 2 ak su dve z cisel a,b,c rovnake a tretie cislo je
# ine, a vrati cislo 0, ak su vsetky tri cisla rozne.


def pocet_rovnakych_v1(a, b, c):
    s = 0
    poc1 = 0
    if (a == b) or (a == c):
        poc1 = s + 1
    if (b == a) or (b == c):
        poc1 = poc1 + 1
    if (c == a) or (c == b):
        poc1 = poc1 + 1
    if (a != b) and (a != c) and (b != a) and (b != c) and (c != a) and (b != c):
        poc1 = 0
    return poc1


def pocet_rovnakych_with_input():
    a = int(input("a= "))
    b = int(input("b= "))
    c = int(input("c= "))
    print(pocet_rovnakych_v1(a, b, c))


pocet_rovnakych_with_input()

##############################################

a = int(input("a="))
b = int(input("b="))
c = int(input("c="))


def pocet_rovnakych_v2(a, b, c):
    poc = 0
    if a == b or a == c:
        poc += 1
    if b == a or b == c:
        poc += 1
    if c == b or c == a:
        poc += 1

    return poc


print(pocet_rovnakych_v2(a, b, c))
