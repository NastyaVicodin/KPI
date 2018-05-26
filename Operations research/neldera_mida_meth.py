from math import sqrt


def f(x1):
    a = 3
    b = 5
    c = 4
    return a * (x1[0] - b)**2 + (x1[1] - c)**2


def get_fgl(x1, x2, x3, f1, f2, f3):
    if f1 >= f2 and f1 >= f3:
        if f2 >= f3:
            return x1, x2, x3, f1, f2, f3
        else:
            return x1, x3, x2, f1, f3, f2
    elif f2 >= f1 and f2 >= f3:
        if f1 >= f3:
            return x2, x1, x3, f2, f1, f3
        else:
            return x2, x3, x1, f2, f3, f1
    elif f3 >= f1 and f3 >= f2:
        if f1 >= f2:
            return x3, x1, x2, f3, f1, f2
        else:
            return x3, x2, x1, f3, f2, f1


def check_end(xh, xg, xl, eps):
    xgl = []
    xgl.append(0)
    xgl.append(1)
    xgl[0] = (xg[0] + xl[0]) / 2
    xgl[1] = (xg[1] + xl[1]) / 2
    x_cen = xh[0] + 2 * abs(xh[0] - xgl[0]) / 3
    y_cen = xh[1] + 2 * abs(xh[1] - xgl[1]) / 3
    if sqrt((xh[0] - x_cen)**2 + (xh[1] - y_cen)**2) + \
        sqrt((xg[0] - x_cen) ** 2 + (xg[1] - y_cen) ** 2) + \
        sqrt((xl[0] - x_cen) ** 2 + (xl[1] - y_cen) ** 2) < eps:
        return 1
    return 0


xh = [8, 7]
xg = [10, 9]
xl = [8, 9]
xc = [0, 0]
xr = [0, 0]
x_e = [0, 0]
tmp = [0, 0]
xs = [0, 0]

alpha = 1
betta = 0.5
gamma = 2
eps = 3

fh = f(xh)
fg = f(xg)
fl = f(xl)

while True:
    (xh, xg, xl, fh, fg, fl) = get_fgl(xh, xg, xl, fh, fg, fl)
    print(xh, xg, xl)
    xc[0] = (xl[0] + xg[0]) / 2
    xc[1] = (xl[1] + xg[1]) / 2
    xr = [(1 + alpha) * xc[0] - alpha * xh[0], (1 + alpha) * xc[1] - alpha * xh[1]].copy()
    fr = f(xr)
    if fr < fl:
        x_e = [(1 - gamma) * xc[0] + gamma * xr[0], (1 - gamma) * xc[1] + gamma * xr[1]].copy()
        fe = f(x_e)
        if fe < fr:
            xh = x_e
            fh = fe
        else:
            xh = xr
            fh = fr
    elif fl <= fr < fg:
        xh = xr
        fh = fr
    elif fg <= fr:
        if fr < fh:
            tmp = xr
            xr = xh
            xh = tmp
            ftmp = fr
            fr = fh
            fh = ftmp
        xs = [betta * xh[0] + (1 - betta) * xc[0], betta * xh[1] + (1 - betta) * xc[1]].copy()
        fs = f(xs)
        if fs < fh:
            xh = xs.copy()
            fh = fs
        else:
            xh = [xl[0] + (xh[0] - xl[0]) / 2, xl[1] + (xh[1] - xl[1]) / 2].copy()
            fh = f(xh)
            xg = [xl[0] + (xg[0] - xl[0]) / 2, xl[1] + (xg[1] - xl[1]) / 2].copy()
            fg = f(xg)
    if check_end(xh, xg, xl, eps) == 1:
        break