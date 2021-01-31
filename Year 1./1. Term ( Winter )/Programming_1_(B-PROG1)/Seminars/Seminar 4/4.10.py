# 10.
# Definujte funkciu pohyb_strelca. Funkcia bude mat styri parametre: x1,y1,x2,y2. Kazdy z
# parametrov moze nadobudat hodnoty od 1 po 8. Funkcia vrati hodnotu True, ak sa sachovy strelec
# dokaze na jeden tah dostat z pozicie (x1,y1) na sachovnici do pozicie (x2,y2). Inak vrati funkcia
# hodnotu False.

def pohyb_strelca_v1(x1, y1, x2, y2):
    if y2 - x2 == y1 - x1:
        return True
    if y2 + x2 == y1 + x1:
        return True
    else:
        return False


print(pohyb_strelca_v1(1, 2, 1, 2))


###################################

def pohyb_strelca_v2(x1, y1, x2, y2):
    if y2 - x2 == y1 - x1 or y2 + x2 == y1 + x1:
        return True
    else:
        return False


print(pohyb_strelca_v2(1, 2, 1, 2))
