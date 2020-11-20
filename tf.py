#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

tf.app.flags.DEFINE_float("a", 1, "ax^2+bx+c=0")
tf.app.flags.DEFINE_float("b", 1, "ax^2+bx+c=0")
tf.app.flags.DEFINE_float("c", 1, "ax^2+bx+c=0")

FLAGS = tf.app.flags.FLAGS
def main(_):
    a = FLAGS.a
    b = FLAGS.b
    c = FLAGS.c
    mid = -b/(2*a)
    x_range = 6
    x = np.linspace(mid - x_range,mid + x_range,600)
    y = [a*z*z+b*z+c for z in x]
    plt.figure(1)
    plt.title('f(x)')
    p1 = plt.plot(x,y1,label="$f(x) = %lf*x^2+%g*x+%g"%(a,b,c))
    plt.plot(x,y,label = label)
    plt.xlabel("x value")
    plt.ylabel("y value")
    plt.legend()
    plt.show()
if __name__ == "__main__":
    tf.app.run()
