import turtle

t = turtle


def polygon(length, n):
    for _ in range(n):
        t.fd(length)
        t.lt(360 / n)


polygon(100, 9)
