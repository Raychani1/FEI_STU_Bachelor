# 3.
# A number, a, is a power of b if it is divisible by b and a/b is a power of b. Write a
# function called is_power that takes parameters a and b and returns True if a is a power of b.

def power(a, b):
    if a == 1:
        return True
    if a % b > 0:
        return False
    return power(a / b, b)


print(power(10, 2))
