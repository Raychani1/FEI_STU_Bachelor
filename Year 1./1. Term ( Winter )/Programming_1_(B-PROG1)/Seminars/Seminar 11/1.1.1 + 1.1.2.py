# 1
# Poduloha 1.1:
# Definujte funkciu F1 s nasledujúcimi vlastnosťami. F1 má jeden
# parameter: zoznam tvaru, ako je popísané vyššie. F1 vráti slovník,
# ktorého kľúče budú známky 'A' až 'FX', a ktorého hodnoty budú
# počty, koľkokrát sa daný kľúč nachádza v zozname.
# Poduloha 1.2:
# Definujte funkciu F2 s nasledujúcimi vlastnosťami. F2 má jeden
# parameter: slovník d (predpokladáme, že hodnoty v slovníku sú
# čísla). F2 vykreslí histogram prislúchajúci k slovníku. Napríklad
# pre slovník d=F1(L), ktorý dostaneme po aplikovaní funkcie F1 z
# Podulohy 1.1 na zoznam L, nám funkcia F2 vypíše:
# A:*
# B:**
# C:*
# D:
# E:*
# FX:*****

l = ["B", "FX", "FX", "E", "A", "FX", "B", "FX", "C", "FX", "A", "D", "E", "FX"]
d = {"A": 0, "B": 0, "C": 0, "D": 0, "E": 0, "FX": 0}


def funkcia_F1(l):
    for c in l:
        d[c] += 1
    return d


def funkcia_F2(d):
    funkcia_F1(l)
    for key in sorted(d):
        print(key, ":", d[key] * "*")


funkcia_F2(d)
