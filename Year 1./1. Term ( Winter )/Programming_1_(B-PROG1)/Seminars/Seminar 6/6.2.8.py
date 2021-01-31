# 8.
# Fibonacciho postupnost je dana nasledovne:
# a0=1
# a1=1
# ai=a(i−1)+a(i−2)
# Definujte funkciu s parametrom n, ktora vrati n-te cislo z Fibonacciho postupnosti. Poznamka: v
# tomto priklade nemusite pouzit while cyklus, staci pouzit for cyklus.

def fib_funkcia(n):
    pred_pred_cislo = 1
    pred_cislo = 1
    if n == 0 or n == 1:
        return 1
    for i in range(n - 1):
        cislo = pred_cislo + pred_pred_cislo
        pred_pred_cislo = pred_cislo
        pred_cislo = cislo
    return cislo


print(fib_funkcia(99999))
