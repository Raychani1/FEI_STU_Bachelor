# 4.
# Definujte funkciu s parametrom n, ktora vypise prvych n cisel vacsich ako 100. (Pre n=3 funkcia vypise cisla 101,102 a 103.)

def from_100_v1(n):
    for i in range(n):
        print(i + 101)


from_100_v1(3)


###########################

def from_100_v2(n):
    for i in range(101, n + 101):
        print(i)


from_100_v2(3)
