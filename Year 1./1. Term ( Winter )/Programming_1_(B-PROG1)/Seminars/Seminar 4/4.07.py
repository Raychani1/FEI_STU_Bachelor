# 7.
# Definujte funkciu pohyb_veze. Funkcia bude mat styri parametre: x1,y1,x2,y2. Kazdy z
# parametrov moze nadobudat hodnoty od 1 po 8. Funkcia vrati hodnotu True, ak sa sachova veza
# dokaze na jeden tah dostat z pozicie (x1,y1) na sachovnici do pozicie (x2,y2). Inak vrati funkcia
# hodnotu False.

def pohyb_veze_v1(x1, y1, x2, y2):
    if y1 == y2:
        return True
    elif x1 == x2:
        return True
    else:
        return False


print(pohyb_veze_v1(1, 2, 2, 3))


#############################

def pohyb_veze_v2(x1, y1, x2, y2):
    if y1 == y2 or x1 == x2:
        return True
    else:
        return False


print(pohyb_veze_v2(1, 2, 2, 2))
