# 11.
# Definujte funkciu, ktora vypise prvych N členov geometrickeho radu, kde i-ty
# člen radu predstavuje súčet prvých i členov geometrickej postupnosti.

def first_n_geometric_elements_with_sum(a0, r, n):
    s = 0
    for i in range(n):
        s += a0 * (r ** i)
        print(s)


first_n_geometric_elements_with_sum(1, 2, 10)
