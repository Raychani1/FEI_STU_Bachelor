# 8.
# Definujte funkciu rovnaka_farba. Funkcia bude mat styri parametre: x1,y1,x2,y2. Kazdy z
# parametrov moze nadobudat hodnoty od 1 po 8. Funkcia vrati hodnotu True, ak pozicia (x1,y1) na
# sachovnici ma rovnaku farbu ako pozicia (x2,y2). Inak vrati funkcia hodnotu False.

def rovnaka_farba(x1, y1, x2, y2):
    if (x2 + y2 + x1 + y1) % 2 == 0:
        return True
    else:
        return False


print(rovnaka_farba(1, 1, 2, 2))
