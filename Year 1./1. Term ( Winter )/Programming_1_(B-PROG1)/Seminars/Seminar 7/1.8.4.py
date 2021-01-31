# Write a function which checks whether a string contains any lowercase letters.

def any_lowercase(ret):
    for znak in ret:
        if znak.islower():
            return True
    return False


print(any_lowercase("MMMa"))
