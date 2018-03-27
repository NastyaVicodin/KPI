from sven_meth import *
from dich_meth import *
from gold_sect import *
from dsk_powel import *
from newton_meth import *
from balcano_meth import *
from secant_meth import *


x = []
i = 0
x.append(2.2)
delta = 0.1
eps = 0.2
print("***********")
print("Sven method")
(x_left, x_centre, x_right, func_left, func_centre, func_right, length) = sven_meth(x, i, delta)
print("****************")
print("Dichotomy method")
dich_meth(x_left, x_centre, x_right, func_centre, length, eps)
print("**************")
print("Golden section")
gold_sect(x_left, x_right, length, eps)
eps = 0.01
print("****************")
print("DSK-Powel method")
dsk_powel(x_left, x_centre, x_right, func_left, func_centre, func_right, eps)
i = 0;
x_n = []
x_n.append(0.1)
print("*************")
print("Newton method")
newton_meth(x_n, i, eps)
print("*************")
print("Balcano method")
a = 0.1
b = 3
balcano_meth(a, b, eps)
print("*************")
print("Secant method")
secant_meth(a, b, eps)