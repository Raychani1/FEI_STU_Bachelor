# 2.
# Write a function called cumsum that takes a list of numbers and returns the cumulative
# sum; that is, a new list where the ith element is the sum of the first i + 1 elements from the
# original list.

def cumsum(t):
    r = []
    for i in range(len(t)):
        r.append(sum(t[0:i + 1]))
    return r


print(cumsum([2, 4, 10]))
