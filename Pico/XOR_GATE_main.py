from machine import Pin
import time

# 7-segment pins
a = Pin(2, Pin.OUT)
b = Pin(3, Pin.OUT)
c = Pin(4, Pin.OUT)
d = Pin(5, Pin.OUT)
e = Pin(6, Pin.OUT)
f = Pin(7, Pin.OUT)
g = Pin(8, Pin.OUT)

# -------- Display Functions --------

def show0():
    a.value(0)
    b.value(0)
    c.value(0)
    d.value(0)
    e.value(0)
    f.value(0)
    g.value(1)

def show1():
    a.value(1)
    b.value(0)
    c.value(0)
    d.value(1)
    e.value(1)
    f.value(1)
    g.value(1)

# -------- Input combinations --------

inputs = [(0,0),(0,1),(1,0),(1,1)]

while True:

    for A, B in inputs:

        # MUX inputs
        I0 = B
        I1 = 1 - B   # complement of B

        # MUX equation
        Y = ((not A) and I0) or (A and I1)

        if Y:
            show1()
        else:
            show0()

        print("A =",A," B =",B," Output =",Y)

        time.sleep(2) 
