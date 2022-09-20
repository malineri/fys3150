import numpy as np
from scipy.linalg import solve
from flopth import flopth
import torchvision.models as models


A = np.array([[2, -1, 0, 0], [-1, 2, -1, 0], [0, -1, 2, -1], [0, 0, -1, 2]])

def f(i):
    f = 100*np.exp(-10*i)
    return f

n = 6
x = np.linspace(0, 1, n)
f = f(x)

h = 0.2

g1 = h**2*f[1] + 0
g2 = h**2*f[2]
g3 = h**2*f[3]
g4 = h**2*f[4] + 1

g = np.array([g1, g2, g3, g4])

s = solve(A, g)
v = np.array([0, s[0], s[1], s[2], s[3], 0])

res = "\n".join("{} {}".format(x, y) for x, y in zip(x, v))
#print(res)




#Changing number of steps n from n=6 to n = 10, 100, 1000, ...

def function(i):
    f = 100*np.exp(-10*i)
    return f

#change up n here:
n = 100
h = (1 - 0)/n
print(h)

x_2 = np.linspace(0, 1, n + 1)
func = function(x_2)


g = np.zeros(n + 1)
for i in range(n + 1):
    g[i] = func[i]*h**2


g[n] = h**2*func[n] + 1
print(g)


b = np.zeros(n + 1)
c = np.zeros(n + 1)

b[1] = 1
c[1] = g[1]

for i in range(2, n - 1, n):
    b[i] = 2 - (-1/(b[i - 1]))*(-1)
    c[i] = g[i] - (-1/(b[i - 1]))*c[i - 1]



#Finding v:
v = np.zeros(n + 1)
for i in range(0, n - 1, n):
    v[i + 1] = v[i]*b[i] - c[i]


v[n] = g[n]/b[n]





res = "\n".join("{} {}".format(x, y) for x, y in zip(x_2, v))
print(res)



#sum_flops = flopth(v, in_size=[[4], [4]])
#print(sum_flops)
