# 10.
# Definujte funkciu, ktora vypise prvych N členov geometrickej postupnosti a_{i+1} = a_{i} *r
# na základe parametrov a_{0}, r a N.

def first_n_geometric_elements(a0, r, n):
    for i in range(n):
        print(a0 * r ** i)


first_n_geometric_elements(1, 2, 10)
