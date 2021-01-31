# 13.2.
# Cislo a vacsie ako 2 je prvocislo, ak pre kazde cislo d z mnoziny {2, 3, … a-1} plati, ze
# a%d>0. Pomocou funkcie delitelnost definujte funkciu test_prvociselnosti, ktora pre argument a
# vrati hodnotu True, ak a je prvocislo, a hodnotu False, ak a nie je prvocislo. Mozete predpokladat, ze a>2.
# Pomocou funkcie test_prvociselnosti vypiste vsetky prvocisla vacsie ako 2 a mensie ako 50

def test_prvociselnosti(a):
    for i in range(2, a):
        if a % i == 0:
            return False
    return True


for i in range(2, 50):
    if test_prvociselnosti(i):
        print(i)
