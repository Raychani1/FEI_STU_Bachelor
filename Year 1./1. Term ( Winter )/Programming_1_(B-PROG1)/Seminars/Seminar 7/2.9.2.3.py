def avoids(word, forbidden):
    for letter in word:
        if letter in forbidden:
            return False
    return True


print(avoids("alma", ["e", "b", "l"]))
