# 13.3.
# Upravte funkciu test_prvociselnosti tak, aby funkcia vratila hodnotu True aj v pripade, ze a=2.
# Pomocou upravenej funkcie test_prvociselnosti vypiste vsetky prvocisla mensie ako 50. (cislo 2 je
# najmensie prvocislo)


def test_prvociselnosti(a):
    if a == 2:
        return True
    for num in range(2, a):
        if a % num == 0:
            return False
    return True


for i in range(2, 50):
    if test_prvociselnosti(i):
        print(i)
