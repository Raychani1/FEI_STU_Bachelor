# 12.
# Definujte funkciu pohyb_jazdca. Funkcia bude mat styri parametre: x1,y1,x2,y2. Kazdy z
# parametrov moze nadobudat hodnoty od 1 po 8. Funkcia vrati hodnotu True, ak sa sachovy jazdec
# dokaze na jeden tah dostat z pozicie (x1,y1) na sachovnici do pozicie (x2,y2). Inak vrati funkcia
# hodnotu False.

def pohyb_jazdca_v1(x1, y1, x2, y2):
    if abs(x1 - x2) == 2 and abs(y1 - y2) == 1:
        return True
    elif abs(x1 - x2) == 1 and abs(y1 - y2) == 2:
        return True
    else:
        return False


print(pohyb_jazdca_v1(1, 2, 3, 3))


##########################################

def pohyb_jazdca_v2(x1, y1, x2, y2):
    if (abs(x1 - x2) == 2 and abs(y1 - y2) == 1) or (abs(x1 - x2) == 1 and abs(y1 - y2) == 2):
        return True
    else:
        return False


print(pohyb_jazdca_v2(1, 1, 3, 3))
