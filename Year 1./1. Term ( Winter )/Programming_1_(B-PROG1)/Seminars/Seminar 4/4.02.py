# 2.
# Definujte funkciu test_parity s parametrom n, ktora vrati hodnotu True, ak je n parne cislo, a
# ktora vrati hodnotu False, ak je n neparne. (pouzite operator %)


def test_parity_v1(n):
    if n % 2 == 0:
        return True
    return False


def number_input():
    n = int(input("n = "))
    print(test_parity_v1(n))


# number_input()

##################################################

n = int(input("n = "))


def test_parity_v2(n):
    return n % 2 == 0


print(test_parity_v2(n))
