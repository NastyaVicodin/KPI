from func_calc import *


def dsk_powel(x_left, x_centre, x_right, func_left, func_centre, func_right, eps):
    f_razn = eps + 1
    x_razn = eps + 1
    while f_razn >= eps or x_razn >= eps:
        a1 = (func_centre - func_left) / (x_centre - x_left)
        a2 = ((func_right - func_left) / (x_right - x_left) - (func_centre - func_left) / (x_centre - x_left)) / (x_right - x_centre)
        x_zvezd = ((x_left + x_centre) / 2) - (a1 / (2 * a2))
        f_zv = f(x_zvezd)
        f_razn = abs(func_centre - f_zv)
        x_razn = abs(x_centre - x_zvezd)
        print("x1 = ", x_left)
        print("x2 = ", x_centre)
        print("x3 = ", x_right)
        print("x_zv = ", x_zvezd)
        print("_________________")
        if x_zvezd <= x_centre:
            x_right = x_centre
            func_right = func_centre
            x_centre = x_zvezd
            func_centre = f_zv
        else:
            x_left = x_centre
            func_left = func_centre
            x_centre = x_zvezd
            func_centre = f_zv
