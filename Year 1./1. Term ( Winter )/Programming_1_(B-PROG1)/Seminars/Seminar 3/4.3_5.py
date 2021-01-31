import math
import turtle

t = turtle


def arc(r, angle):
    circumference = 2 * math.pi * r
    arclen = circumference * angle / 360
    n = int(arclen / 3) + 1
    steplen = arclen / n
    stepang = float(angle) / n
    for _ in range(n):
        t.fd(steplen)
        t.lt(stepang)


arc(100, 90)
