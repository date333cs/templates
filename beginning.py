# -*- coding: utf-8 -*-
import math
import random
import matplotlib.pyplot as plt

random.seed(20161108)

def make_matrix(a, b, fill=0.0):
    m = []
    for i in range(a):
        m.append([fill]*b)
    return m

class ASM:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.W = make_matrix(self.n, self.n)
        self.x = [0]*self.n
        self.p = make_matrix(self.m, self.n, 0)

    def generate_memories(self):
        for j in range(self.m):
	    for i in range(self.n):
		if ( random.random() < 0.5 ):
                    self.p[j][i] = -1
                else:
                    self.p[j][i] = 1

def demo():

    n = 1000
    m = 80

    asm = ASM(n, m) # create a network. n: number of neurons.
    asm.generate_memories()

    

if __name__ == '__main__':

    demo()
    

