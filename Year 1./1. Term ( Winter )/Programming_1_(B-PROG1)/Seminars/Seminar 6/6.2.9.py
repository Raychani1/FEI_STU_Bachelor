# 9.
# Definujte funkciu s parametrom x, ktora vrati index cisla x vo Fibonacciho postupnosti. To
# znamena, ze funkcia vrati i take, ze ai=x . Ak sa cislo x nenachadza vo Fibonacciho postupnosti,
# funkcia vrati cislo -1.

def fibonacci(n):
    pred_pred_cislo = 1
    pred_cislo = 1
    if n == 0 or n == 1:
        return 1
    for i in range(n - 1):
        cislo = pred_cislo + pred_pred_cislo
        pred_pred_cislo = pred_cislo
        pred_cislo = cislo
    return cislo


def funkcia(x):
    i = 0
    while True:
        if fibonacci(i) == x:
            return i
        if fibonacci(i) > x:
            return -1
        i += 1


print(funkcia(8))
