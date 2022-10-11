import numpy as np
import matplotlib.pyplot as plt


#pretend we have already the values from the jacobi rotation model.
#We have the number of iterations i, and the size of the matrix N.
#guessing random numbers;

N = np.array([10, 20, 50, 100, 500, 1000])
i = np.array([100, 1000, 3000, 15000, 50000, 1000000])

#We see that the numbers become very large, this may slow the program down.
#For real numbers this may even be heavier than this simple guess.


plt.title("Number of iterations for different sized NxN matrices")
plt.plot(N, i)
plt.xlabel("N")
plt.ylabel("iterations")
plt.savefig("IN.pdf")
plt.show()
