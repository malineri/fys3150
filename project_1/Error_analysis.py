import numpy as np
import matplotlib.pyplot as plt


x, d2u_approx, d2u_exact = np.loadtxt("output.txt", usecols=(0,1,2), unpack=True)

# Compute numpy arrays with the absolute error, relative error, log10(relative error) and log10(absolute error)
abs_err = np.absolute(d2u_approx - d2u_exact)
rel_err = np.absolute(abs_err / d2u_exact)
log10_rel_err = np.log10(rel_err)
log10_abs_err = np.log10(abs_err)

# Array with log10(h)
log10_x = np.log10(x)




# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333

# Plot log10 absolute error vs x
plt.figure(figsize=(figwidth, figheight))
plt.plot(log10_x, log10_abs_err, '--', c="0.8", linewidth=1.5)
plt.plot(log10_x, log10_abs_err, '.', c="black", markersize=10)
plt.title("Log log plot of the absolute error for each x", fontsize=10)
plt.ylabel("log_10(absolute error)")
plt.xlabel("log10(x)")
plt.savefig("log10_abs_err_vs_x.pdf")

plt.show()

# Plot log10 relative error vs x
plt.figure(figsize=(figwidth, figheight))
plt.plot(log10_x, log10_rel_err, '--', c="0.8", linewidth=1.5)
plt.plot(log10_x, log10_rel_err, '.', c="black", markersize=10)
plt.title("Log log plot of the relative error for each x", fontsize=10)
plt.ylabel("log_10(Relative error)")
plt.xlabel("log_10(x)")
plt.savefig("log10_rel_err.pdf")



plt.show()
