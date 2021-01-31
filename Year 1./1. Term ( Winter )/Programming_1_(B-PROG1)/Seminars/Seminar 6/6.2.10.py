def mysqrt(x, a):
    epsilon = 0.000000001
    while True:
        y = (x + a / x) / 2
        if abs(y - x) < epsilon:
            break
        x = y
    return x


print(mysqrt(1.5, 2))
