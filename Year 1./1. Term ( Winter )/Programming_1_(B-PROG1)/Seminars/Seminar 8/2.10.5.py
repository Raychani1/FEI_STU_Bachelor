# 5.
# Write a function called is_sorted that takes a list as a parameter and returns True
# if the list is sorted in ascending order and False otherwise.

def is_sorted(t):
    for i in range(len(t)):
        if t[i] <= t[i + 1]:
            return True
        else:
            return False


print(is_sorted([8, 9, 10, 11, 12]))
