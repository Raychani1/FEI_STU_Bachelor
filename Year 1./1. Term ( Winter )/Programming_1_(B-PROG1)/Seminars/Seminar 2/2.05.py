# 5.
# Definujte funkciu s parametrom n, ktora vypise prvych n parnych cisel (zacinajuc dvojkou).
# Urobte to bez pouzitia podmienok (if-ov)

def first_n_even_numbers_v1(n):
    for i in range(n):
        print((i + 1) * 2)


first_n_even_numbers_v1(10)


##########################

def first_n_even_numbers_v2(n):
    for i in range(1, n + 1):
        print(i * 2)


first_n_even_numbers_v2(10)
