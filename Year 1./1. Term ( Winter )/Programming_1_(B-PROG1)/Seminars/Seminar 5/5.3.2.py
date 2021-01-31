# 2.
# Write a function called is_palindrome that takes a string argument and returns True if it
# is a palindrome and False otherwise.

def first(word):
    return word[0]


def last(word):
    return word[-1]


def middle(word):
    return word[1:-1]


def is_palindrome_v1(word):
    if len(word) <= 1:
        return True
    if first(word) != last(word):
        return False
    return is_palindrome_v1(middle(word))


print(is_palindrome_v1('allen'))
print(is_palindrome_v1('bob'))
print(is_palindrome_v1('otto'))
print(is_palindrome_v1('redivider'))


def is_palindrome_v2(word):
    if len(word) <= 1:
        return True
    if word[0] != word[-1]:
        return False
    else:
        return is_palindrome_v2(word[1:-1])


print(is_palindrome_v2(input()))
