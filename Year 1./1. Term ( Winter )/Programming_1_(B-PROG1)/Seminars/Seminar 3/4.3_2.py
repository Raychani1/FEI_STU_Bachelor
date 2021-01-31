import turtle

t = turtle


def square(length):
    for _ in range(4):
        t.fd(length)
        t.lt(90)


square(100)
