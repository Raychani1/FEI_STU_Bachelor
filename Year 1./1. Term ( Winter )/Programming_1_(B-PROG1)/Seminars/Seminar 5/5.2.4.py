# 4.
# Definujte funkciu s parametrom n, ktora nacita n cisel z klavesnice a vrati druhe najvacsie
# nacitane cislo.

def second_gratest(n):
    numbers = []

    for _ in range(n):
        number = int(input())
        numbers.append(number)

    return sorted(numbers)[-2]


print(second_gratest(5))
