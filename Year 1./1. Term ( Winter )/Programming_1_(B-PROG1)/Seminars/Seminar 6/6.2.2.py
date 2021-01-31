# 2.
# Definujte funkciu s parametrom n, ktora vypise vsetky stvorce mensie ako cislo n. (Prirodzene
# cislo nazyvame stvorcom, ak je druhou mocninou nejakeho prirodzeneho cisla. Napriklad cisla
# 0,1,4,9,16 su stvorce. Priklad: pre argument n=10 funkcia vypise cisla 0,1,4,9.)

def smacn(n):
    c = 0
    stvor = c * c

    while stvor < n:
        stvor = c * c
        if stvor > n:
            break
        print(stvor)
        c = c + 1


smacn(400)
