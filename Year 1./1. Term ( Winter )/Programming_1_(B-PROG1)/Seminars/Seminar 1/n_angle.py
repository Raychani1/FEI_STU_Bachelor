import turtle


def n_angle(n):
    for _ in range(n):
        turtle.forward(80)
        turtle.left(360 / n)
    turtle.done()


n_angle(4)
