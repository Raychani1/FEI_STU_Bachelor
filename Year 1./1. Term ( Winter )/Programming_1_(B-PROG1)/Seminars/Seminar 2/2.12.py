# 12.
# Vytvorte program, ktorý názorne demonštruje, že geometricky rad konverguje
# pre r v absolútnej hodnote menšej ako 1 ku a_{0}/(1-r).

def geometric(a0, r, n):
    s = 0
    for _ in range(n):
        s += a0 * (r ** i)
        print(s)


for i in range(150):
    geometric(0.5, 0.5, i)
