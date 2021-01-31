# 11.
# Definujte funkciu pohyb_damy. Funkcia bude mat styri parametre: x1,y1,x2,y2. Kazdy z
# parametrov moze nadobudat hodnoty od 1 po 8. Funkcia vrati hodnotu True, ak sa sachova dama
# dokaze na jeden tah dostat z pozicie (x1,y1) na sachovnici do pozicie (x2,y2). Inak vrati funkcia
# hodnotu False.

def pohyb_damy_v1(x1, y1, x2, y2):
    if y1 == y2:
        return True
    elif x1 == x2:
        return True
    elif y2 - x2 == y1 - x1:
        return True
    elif y2 + x2 == y1 + x1:
        return True
    else:
        return False


print(pohyb_damy_v1(1, 2, 1, 1))


#######################################

def pohyb_damy_v2(x1, y1, x2, y2):
    if y1 == y2 or x1 == x2 or y2 - x2 == y1 - x1 or y2 + x2 == y1 + x1:
        return True
    else:
        return False


print(pohyb_damy_v2(1, 2, 1, 1))
