# 9.
# Definujte funkciu, ktora vypise prvych N členov aritmetickej postupnosti a_{i+1} = a_{i} + d
# na základe parametrov a_{0}, d a N.

def first_n_arithmetic_elements(a0, n, d):
    for _ in range(n):
        a0 += d
        print(a0)


first_n_arithmetic_elements(0, 10, 3)
