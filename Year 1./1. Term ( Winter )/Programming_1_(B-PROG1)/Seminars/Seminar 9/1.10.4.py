# 1.
# Write a function called chop that takes a list, modifies it by removing the first and
# last elements, and returns None.

def chop(t):
    del t[0]
    del t[-1]
    return None


t = [1, 2, 3, 4]

print(t)
print(chop(t))
print(t)
