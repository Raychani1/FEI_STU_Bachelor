import turtle

t = turtle
t.speed(10)
t.arc = t.circle


def petal(r1, angle1):
    t.pencolor("red")
    t.fillcolor("red")
    for i in range(2):
        t.arc(r1, angle1)
        t.lt(180 - angle1)


def flower(n, r1, angle1):
    for _ in range(n):
        petal(r1, angle1)
        t.lt(360 / n)


def stem(r2, angle2):
    t.pensize(3)
    t.pencolor("green")
    t.circle(r2, angle2)


def leaf(r3, angle3):
    t.pensize(1)
    t.pencolor("darkgreen")
    t.fillcolor("darkgreen")
    for _ in range(2):
        t.circle(r3, angle3)
        t.lt(180 - angle3)


def whole_flower(n, r1, angle1, r2, angle2, r3, angle3):
    t.begin_fill()
    flower(n, r1, angle1)
    t.end_fill()
    t.rt(135)
    stem(r2, angle2)
    t.seth(0)
    t.begin_fill()
    for _ in range(2):
        leaf(r3, angle3)
        t.lt(90)
    t.end_fill()
    t.done()


whole_flower(7, 100, 60, 200, 75, 150, 80)
