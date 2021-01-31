# Write a one-line version of is_palindrome from Exercise 6.3.#

def is_palindrome(ret):
    return ret == ret[::-1]


print(is_palindrome("mama"))
