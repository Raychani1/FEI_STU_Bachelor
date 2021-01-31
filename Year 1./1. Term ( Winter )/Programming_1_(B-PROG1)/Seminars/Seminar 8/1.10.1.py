# 1.
# Write a function called nested_sum that takes a list of lists of integers and adds up
# the elements from all of the nested lists.

def nested_sum(t):
    print(sum(sum(t, [])))


nested_sum([[18, 2], [9], [4, 5, 6], [12, 18, 1230, 454]])
