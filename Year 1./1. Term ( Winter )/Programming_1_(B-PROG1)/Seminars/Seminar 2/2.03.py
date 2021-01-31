# 3.
# Definujte funkciu s parametrom n, ktora vypise cisla od 1 po n. (Vo funkcii pouzite for-cyklus)

def from_1_to_n_v1(n):
    for i in range(n):
        print(i + 1)


from_1_to_n_v1(9)


##############################

def from_1_to_n_v2(n):
    for i in range(1, n + 1):
        print(i)


from_1_to_n_v2(9)
