# 1.
# Definujte funkciu s parametrom n, ktora vrati sucet 1+2+3+...+n. Vo funkcii pouzite rekurziu!

def sum_recursive(n):
    if n == 0:
        return 0
    else:
        result = n + sum_recursive(n - 1)

    return result


print(sum_recursive(992))  # max 992
