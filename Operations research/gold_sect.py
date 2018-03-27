from func_calc import *

def gold_sect(x_left, x_right, length, eps):
    while length > eps:
        old_l = x_left
        old_r = x_right
        x1 = x_left + 0.382 * length
        x2 = x_left + 0.618 * length
        f_x1 = f(x1)
        f_x2 = f(x2)
        if (f_x1 <= f_x2):
            x_centre = x1
            f_centre = f_x1
            x_right = x2
            func_right = f_x2
        else:
            x_centre = x2
            f_centre = f_x2
            x_left = x1
            func_left = f_x1
        length = abs(x_right - x_left)
    if (x_right > x_left):
        print("Interval: [", old_l, ", ", old_r, "]", sep='')
    else:
        print("Interval: [", old_r, ", ", old_l, "]", sep='')
