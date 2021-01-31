# 5.
# Write a function called koch that takes a turtle and a length as parameters, and that uses the
# turtle to draw a Koch curve with the given length.
# Write a function called snowflake that draws three Koch curves to make the outline of a snowflake.

import turtle


def koch(t, n):
    if n < 10:
        t.fd(n)
        return
    m = n / 3
    koch(t, m)
    t.lt(60)
    koch(t, m)
    t.rt(120)
    koch(t, m)
    t.lt(60)
    koch(t, m)


def snowflake(t, n):
    for _ in range(3):
        koch(t, n)
        t.rt(120)


t = turtle.Turtle()

t.pu()
t.goto(-150, 90)
t.pd()
snowflake(t, 300)

turtle.mainloop()
