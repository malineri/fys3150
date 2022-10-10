import numpy as np




d = 2
a = 1
N = 6

x = np.zeros(N + 1)
l = np.zeros(N + 1)
for i in range(N + 1):
    x[i] = (np.pi*i)/(N + 1)
    l[i] = d + (2*a*np.cos(x[i]))

lamb = np.array(l[1:(N + 1)])
print(" ")
print("Eigenvalues:")
print(" ")
print(lamb)
print(" ")





#Vector 1
verdi1 = np.zeros(N + 1)
for i in range(N + 1):
    verdi1[i] = np.sin((i*np.pi)/(N + 1))

#Vector 2
verdi2 = np.zeros(N + 1)
for i in range(N + 1):
    verdi2[i] = np.sin((2*i*np.pi)/(N + 1))

#Vector 3
verdi3 = np.zeros(N + 1)
for i in range(N + 1):
    verdi3[i] = np.sin((3*i*np.pi)/(N + 1))

#Vector 4
verdi4 = np.zeros(N + 1)
for i in range(N + 1):
    verdi4[i] = np.sin((4*i*np.pi)/(N + 1))

#Vector 5
verdi5 = np.zeros(N + 1)
for i in range(N + 1):
    verdi5[i] = np.sin((5*i*np.pi)/(N + 1))

#Vector 6
verdi6 = np.zeros(N + 1)
for i in range(N + 1):
    verdi6[i] = np.sin((6*i*np.pi)/(N + 1))


vector = np.array([verdi1[1:(N + 1)], verdi2[1:(N + 1)], verdi3[1:(N + 1)], verdi4[1:(N + 1)], verdi5[1:(N + 1)], verdi6[1:(N + 1)]])



print(" ")
print("Eigenvector:")
print(" ")
print(vector)
print(" ")



"""
Terminal > python analytical_2.py

Eigenvalues:

[3.80193774 3.2469796  2.44504187 1.55495813 0.7530204  0.19806226]


Eigenvector:

[[ 0.43388374  0.78183148  0.97492791  0.97492791  0.78183148  0.43388374]
 [ 0.78183148  0.97492791  0.43388374 -0.43388374 -0.97492791 -0.78183148]
 [ 0.97492791  0.43388374 -0.78183148 -0.78183148  0.43388374  0.97492791]
 [ 0.97492791 -0.43388374 -0.78183148  0.78183148  0.43388374 -0.97492791]
 [ 0.78183148 -0.97492791  0.43388374  0.43388374 -0.97492791  0.78183148]
 [ 0.43388374 -0.78183148  0.97492791 -0.97492791  0.78183148 -0.43388374]]


"""
