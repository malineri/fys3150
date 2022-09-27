from scipy.sparse import coo_matrix
import numpy as np
#program used from https://primer-computational-mathematics.github.io/book/c_mathematics/linear_algebra/5_Linear_Algebra_in_Python.html

N = 6
a, b, c = [1]*(N - 1), [-2]*N, [1]*(N - 1)

A = np.diag(a, -1) + np.diag(b, 0) + np.diag(c, 1)
#print(A)

x, V = np.linalg.eig(A)
assert np.allclose(V @ np.diag(x), A @ V)

print(x)



eigenvalues = np.zeros(N)



for i in range(0, N, 1):
    eigenvalues[i] = np.linalg.det(A - np.eye(len(A))*x[i])



print(eigenvalues)
