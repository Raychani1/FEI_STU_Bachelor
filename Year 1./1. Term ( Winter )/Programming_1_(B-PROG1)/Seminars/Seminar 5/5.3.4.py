# 4.
# Write a function called gcd that takes parameters a and b and returns their greatest common divisor.

a = int(input("a= "))
b = int(input("b= "))


def gcd(a, b):
    a1 = a
    b1 = b
    r = a1 % b1
    while r != 0:
        a = b
        b = r
        r = a % b
    return b


print(gcd(a, b))
