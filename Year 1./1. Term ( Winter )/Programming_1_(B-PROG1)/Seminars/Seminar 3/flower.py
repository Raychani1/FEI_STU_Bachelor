import math
import turtle

t = turtle


def arc(r, angle):
    circum = 2 * math.pi * r
    arclen = circum * angle / 360
    m = int(arclen / 3) + 1
    steplen = arclen / m
    stepang = float(angle) / m
    for _ in range(m):
        t.fd(steplen)
        t.lt(stepang)


def stem(r2, angle2):
    circum = 2 * math.pi * r2
    arclen = circum * angle2 / 360
    m = int(arclen / 3) + 1
    steplen = arclen / m
    stepang = float(angle2) / m
    t.seth(0)
    t.seth(90 + (angle2) / (steplen) + 11)
    for _ in range(m):
        t.fd(steplen)
        t.rt(stepang)


def petal(r1, angle1):
    for _ in range(2):
        arc(r1, angle1)
        t.lt(180 - angle1)


def flower(n, r1, angle1):
    for _ in range(n):
        petal(r1, angle1)
        t.lt(360 / n)


def leaf(l, r3, angle3):
    circum = 2 * math.pi * r3
    arclen = circum * angle3 / 360
    m = int(arclen / 3) + 1
    steplen = arclen / m
    stepang = float(angle3) / m
    t.lt(l)
    for _ in range(2):
        arc(r3, angle3)
        print(t.pos())
        t.lt(180 - angle3)
    t.seth(0)
    t.lt(180 - l - angle3 + (steplen - stepang) * 2.52)
    for _ in range(2):
        arc(r3, angle3)
        print(t.pos())
        t.lt(180 - angle3)


def whole_flower(n, r1, angle1, r2, angle2, r3, angle3, l):
    leaf(l, r3, angle3)
    stem(r2, angle2)
    t.seth(0)
    flower(n, r1, angle1)
    t.done()


whole_flower(5, 75, 62, 100, 90, 100, 65, 20)
