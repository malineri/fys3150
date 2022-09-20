import numpy as np
from scipy.linalg import solve
from flopth import flopth
import torchvision.models as models


A = np.array([[2, -1, 0, 0], [-1, 2, -1, 0], [0, -1, 2, -1], [0, 0, -1, 2]])


def f(i):
    f = 100*np.exp(-10*x)
    return f


x = np.linspace(0, 1, 6)
f = f(x)

h = 0.2

g1 = h**2*f[1] + 0
g2 = h**2*f[2]
g3 = h**2*f[3]
g4 = h**2*f[4] + 1

g = np.array([g1, g2, g3, g4])

v = solve(A, g)
print(v)



sum_flops = flopth(v, in_size=[[4], [4]])
print(sum_flops)
