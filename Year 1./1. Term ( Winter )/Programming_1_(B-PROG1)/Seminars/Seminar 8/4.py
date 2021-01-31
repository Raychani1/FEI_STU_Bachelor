# 4.
# Definujte funkciu, ktorej argumentom bude zoznam cisel. Funkcia vrati pocet takych cisel v
# zozname, ktore su vacsie aj ako ich lavy a aj ako ich pravy sused.

def susedia(t):
    pocet = 0
    for i in range(1, len(t) - 1):
        if t[i] > t[i - 1] and t[i] > t[i + 1]:
            pocet += 1
    return pocet


print(susedia([1, 2, 0, 1, 0]))
