# 1.
# Vytvorte interaktivnu verziu funkcie z prikladu 3 z Cvicenia 2.:
# Definujte funkciu s parametrom n, ktora vypise cisla od 1 po n.

def from_1_to_n(n):
    for i in range(1, n + 1):
        print(i)


def from_1_to_n_with_input_v1():
    n = int(input("n = "))
    from_1_to_n(n)


#######################################

def from_1_to_n_with_input_v2():
    n = int(input("n = "))
    for i in range(1, n + 1):
        print(i)
