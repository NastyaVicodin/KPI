from func_calc import *


def new_x(x, pow, delta):
    return x + delta * 2**pow


def sven_meth(x, i, delta):
    neg_delta = f(x[i] - delta)
    pos_delta = f(x[i] + delta)
    func_val = f(x[i])
    if neg_delta <= func_val <= pos_delta:
        delta *= -1
        func_val_new = neg_delta
    elif neg_delta >= func_val and func_val <= pos_delta:
        int_start = x[i] - delta
        int_end = x[i] + delta
        print("Interval: [", int_start, ", ", int_end, "]", sep='')
        exit()
    elif neg_delta <= func_val and func_val >= pos_delta:
        print("Function is not unimodal")
        exit()
    else:
        func_val_new = pos_delta
    x.append(i)
    x[i + 1] = new_x(x[i], i, delta)
    i = 1
    while func_val > func_val_new:
        func_val = func_val_new
        i += 1
        x.append(i)
        x[i] = new_x(x[i - 1], i - 1, delta)
        func_val_new = f(x[i])
    x_centre = (x[i] + x[i - 1]) / 2
    func_centre = f(x_centre)
    if func_centre > func_val:
        x_right = x_centre
        func_right = func_centre
        x_left = x[i - 2]
        func_left = f(x_left)
        x_centre = x[i - 1]
        func_centre = func_val
    else:
        x_right = x[i]
        func_right = func_val_new
        x_left = x[i - 1]
        func_left = func_val
    length = abs(x_right - x_left)
    if (x_right > x_left):
        print("Interval: [", x_left, ", ", x_right, "]", sep='')
    else:
        print("Interval: [", x_right, ", ", x_left, "]", sep='')
        tmp = x_right
        x_right = x_left
        x_left = tmp
        tmp = func_right
        func_right = func_left
        func_left = tmp
    return x_left, x_centre, x_right, func_left, func_centre, func_right, length
