# 5.
# Definujte funkciu menu, ktora vyzve uzivatela, aby zadal vstup z klavesnice, v pripade, ze vstup
# je znak s, funkcia vykresli stvorec pomocou turtle, v pripade, ze vstup je znak t, funkcia vykresli
# trojuholnik pomocou turtle, inak funkcia vypise 'Zadali ste neplatny vstup.'

import turtle


def menu1():
    vstup = input("Zadajte vstup: ")
    if vstup == 's':
        for _ in range(4):
            turtle.fd(100)
            turtle.lt(90)
    elif vstup == 't':
        for _ in range(3):
            turtle.fd(100)
            turtle.lt(120)
    else:
        print("Zadali ste neplatny vstup")


menu1()


#############################################

def s():
    for _ in range(4):
        turtle.fd(100)
        turtle.lt(90)


def t():
    for _ in range(3):
        turtle.fd(100)
        turtle.lt(120)


def menu2():
    vstup = input("Zadajte vstup: ")
    if vstup == 's':
        s()
    elif vstup == 't':
        t()
    else:
        print("Zadali ste neplatny vstup")


menu2()
