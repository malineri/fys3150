import numpy as np
import matplotlib.pyplot as plt


def poisson(x):
    u = 1 - (1-np.exp(-10))*x - np.exp(-10*x)
    return u


n = 100
x = np.linspace(0, 1, n + 1)
P = poisson(x)

plt.title("Plot of one-dimetional Poisson equation")
plt.plot(x, P)
plt.xlabel("x from 0 to 1")
plt.ylabel("The corresponding values u(x)")
plt.show()
