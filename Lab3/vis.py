import matplotlib.pyplot as plt 
import numpy as np
import math

x = []
y = []
i = -1
counter = 0
while i <= 1:
    x.append(i)
    y.append(2*math.sin(i))
    i+=0.2

plt.scatter(x, y, marker='d', label='(x, 2*sin(x)) data points')

coef = "1.36366e-07 2 -3.06655e-06 -0.333338 3.85036e-05 0.0166888 -0.000150838 -0.000431355 0.000221828 2.24153e-05 -0.000106325"
coef = [float(i) for i in coef.split()]

y_pred = []
for xi in x:
    yi_pred = 0
    for i in range(len(coef)):
        yi_pred += coef[i]*(xi**i)
    y_pred.append(yi_pred)

plt.plot(x, y_pred, '-k', label='estimated value of 2*sin(x) using polynomial interpolation')
plt.title("Polynomial 2*sin(x) interpolation, calculated with LU decompositon")
plt.legend()
plt.savefig("result.png")
plt.show()

