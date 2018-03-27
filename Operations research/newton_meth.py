from func_calc import *

def newton_meth(x, i, eps):
    f_pr1 = eps + 1
    while abs(f_pr1) >= eps:
        print("x[", i, "]", x[i])
        f_pr1 = fp1(x[i])
        f_pr2 = fp2(x[i])
        i += 1
        x.append(i)
        x[i] = x[i - 1] - f_pr1 / f_pr2
