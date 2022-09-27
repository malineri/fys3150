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
eigenvalues[0] = np.linalg.det(A - np.eye(len(A))*x[0])
eigenvalues[1] = np.linalg.det(A - np.eye(len(A))*x[1])
eigenvalues[2] = np.linalg.det(A - np.eye(len(A))*x[2])
eigenvalues[3] = np.linalg.det(A - np.eye(len(A))*x[3])
eigenvalues[4] = np.linalg.det(A - np.eye(len(A))*x[4])
eigenvalues[5] = np.linalg.det(A - np.eye(len(A))*x[5])



#for i in range(0, N - 1, N):
#    eigenvalues[i] = np.linalg.det(A - np.eye(len(A))*x[i])



print(eigenvalues)
