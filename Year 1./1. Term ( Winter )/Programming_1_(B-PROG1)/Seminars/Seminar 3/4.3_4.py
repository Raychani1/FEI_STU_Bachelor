import math
import turtle

t = turtle


def polygon(length, n):
    for _ in range(n):
        t.fd(length)
        t.lt(360 / n)


def circle(r):
    circumference = 2 * math.pi * r
    n = 50
    length = circumference / n
    polygon(length, n)


circle(80)
