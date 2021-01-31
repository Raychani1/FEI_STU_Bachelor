# 1.
# Definujte funkciu s parametrom n, ktora nacita n cisel z klavesnice a vrati tretie najvacsie
# nacitane cislo

def max3(n):
    numbers = []

    for _ in range(n):
        number = int(input())
        numbers.append(number)

    return sorted(numbers)[-3]


print(max3(5))
