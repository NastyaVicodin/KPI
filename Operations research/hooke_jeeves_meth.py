from math import sqrt

def f(x1, x2):
    a = 2
    b = 3
    return (x1 - a)**2 + b * x2**2

def eps_x_check(x1_old, x2_old, x1, x2, eps_x):
    if sqrt((x1_old - x1)**2 + (x2_old - x2)**2) / sqrt(x1_old**2 + x2_old**2) < eps_x:
        return 1
    return 0


def eps_func_check(f_current, f_new, eps_func):
    if abs((f_new - f_current) / f_new) < eps_func:
        return 1
    return 0


def new_x1(x1, x2, dx1, dx2, f_current):
    while True:

        f1 = f(x1 - dx1, x2)
        f2 = f(x1 + dx1, x2)
        if f1 <= f2:
            f_new = f1
            x1_new = x1 - dx1
        else:
            f_new = f2
            x1_new = x1 + dx1
        if f_current <= f_new:
            return x1, f_current, dx1, dx2
        else:
            return x1_new, f_new, dx1, dx2


def new_x2(x1, x2, dx1, dx2, f_current):
    while True:
        f1 = f(x1, x2 - dx2)
        f2 = f(x1, x2 + dx2)
        if f1 <= f2:
            f_new = f1
            x2_new = x2 - dx2
        else:
            f_new = f2
            x2_new = x2 + dx2
        if f_current <= f_new:
            return x2, f_current, dx1, dx2
        else:
            return x2_new, f_new, dx1, dx2


a = 2
b = 3
i = 0
x1 = []
x2 = []
x1.append(i)
x2.append(i)
x1[i] = 2 * a
x2[i] = 3 * a
f_current = f(x1[i], x2[i])
dx1 = 0.6
dx2 = 0.8
alpha = 2
eps_x = 0.2
eps_func = 0.2
x1_work = x1[i]
x2_work = x2[i]
f_work = f(x1_work, x2_work)
while True:
    x1.append(i + 1)
    x2.append(i + 1)
    (x1[i + 1], f_new, dx1, dx2) = new_x1(x1_work, x2_work, dx1, dx2, f_work)
    (x2[i + 1], f_new, dx1, dx2) = new_x2(x1[i + 1], x2_work, dx1, dx2, f_new)
    f_current = f(x1[i], x2[i])
    print('x[', i + 1, ']: (', x1[i + 1], ';', x2[i + 1], ')', sep='')
    if f_current > f_new and eps_x_check(x1[i], x2[i], x1[i + 1], x2[i + 1], eps_x) == 1\
            and eps_func_check(f_current, f_new, eps_func) == 1:
        break
    if f_current <= f_new:
        dx1 /= alpha
        dx2 /= alpha
        i -= 1
        f_current = f(x1[i], x2[i])
        x1_work = x1[i]
        x2_work = x2[i]
        f_work = f_current
    else:
        x1_work = 2 * x1[i + 1] - x1[i]
        x2_work = 2 * x2[i + 1] - x2[i]
        f_work = f(x1_work, x2_work)
        i += 1


print('MIN x: (', x1[i], ';', x2[i], ')', sep='')
