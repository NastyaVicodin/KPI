from func_calc import *


def dich_meth(x_left, x_centre, x_right, func_centre, length, eps):
    while length > eps:
        x_oldl = x_left
        x_oldr = x_right
        x_lc = (x_left + x_centre) / 2
        func_lc = f(x_lc)
        x_cr = (x_centre + x_right) / 2
        func_cr = f(x_cr)
        min_x = min(func_lc, func_centre, func_cr)
        if func_lc == min_x:
            x_right = x_centre
            x_centre = x_lc
            func_centre = func_lc
        elif func_centre == min_x:
            x_right = x_cr
            x_left = x_lc
        else:
            x_left = x_centre
            x_centre = x_cr
            func_centre = func_cr
        length = abs(x_right - x_left)
    if (x_right > x_left):
        print("Interval: [", x_oldl, ", ", x_oldr, "]", sep='')
    else:
        print("Interval: [", x_oldr, ", ", x_oldl, "]", sep='')
