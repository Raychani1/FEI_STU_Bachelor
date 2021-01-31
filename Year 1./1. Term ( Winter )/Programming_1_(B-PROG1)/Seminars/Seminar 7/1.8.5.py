# Write a function called rotate_word that takes a string and an integer as parameters, and returns
# a new string that contains the letters from the original string rotated by the given amount.

def rotate_word(ret, n):
    ret2 = " "
    for znak in ret:
        poz2 = 97 + ((ord(znak) - 97 + n) % 26)
        znak2 = chr(poz2)
        ret2 += znak2
    return ret2


print(rotate_word("xyz", 1))
