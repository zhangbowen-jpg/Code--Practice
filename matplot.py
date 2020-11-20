#!/usr/bin/env python
# coding=utf-8
import numpy as np
import matplotlib.pyplot as plt

plt.figure(1)

x = np.linspace(-3,3,600)
y1 = [-2*(z+1)**2+4*(z+1)-6 for z in x]

plt.title('f(x)')
p1 = plt.plot(x,y1,label="$-2*(x+1)^2+4*(x+1)-6")
plt.xlabel('x value')
plt.ylabel('y value')
plt.legend()
plt.show()
