# 13.1.
# Definujte funkciu delitelnost, ktora pre argumenty a a d vrati hodnotu True, ak a%d==0, a
# hodnotu False, ak a%d>0.
# Pomocou funkcie delitelnost vypiste vsetky delitele cisla 12. (Delitele cisla 12 su 1, 2, 3, 4, 6, 12.)

def delitelnost_v1(a, d):
    if a % d == 0:
        return True
    else:
        return False


for i in range(1, 100):
    if delitelnost_v1(12, i):
        print(i)


#########################################

def delitelnost_v2(a, d):
    return a % d == 0


for i in range(1, 100):
    if delitelnost_v2(12, i):
        print(i)
