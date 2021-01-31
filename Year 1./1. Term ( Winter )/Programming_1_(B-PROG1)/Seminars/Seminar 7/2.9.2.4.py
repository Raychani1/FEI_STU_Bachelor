def uses_only(word, available):
    for letter in word:
        if letter not in available:
            return False
    return True


print(uses_only("alma", ["a", "l", "m"]))
