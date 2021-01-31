# 5.
# Definujte funkciu, ktorej argumentom bude zoznam. Funkcia vrati pocet roznych prvkov v zozname.

def rozne(t):
    s = []
    for item in t:
        if item not in s:
            s.append(item)
    return len(s)


print(rozne([...]))
