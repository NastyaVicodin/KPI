from func_calc import *


def balcano_meth(a, b, eps):
    f_c = eps + 1
    x_c = (a + b) / 2
    f_l = fp1(a)
    f_r = fp1(b)
    while f_c >= eps:
        print(x_c)
        f_c = fp1(x_c)
        if f_l < 0 and f_c > 0:
            b = x_c
            f_r = f_c
            x_c = (a + x_c) / 2
        elif f_c < 0 and f_r > 0:
            a = x_c
            f_l = f_c
            x_c = (x_c + b) / 2
        else:
            print("Bad function")
            return
    print(x_c)
