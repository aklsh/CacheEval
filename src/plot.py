#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

figNum = 0
plotsDir = 'fig/'

def plotBlockSize():
    with open('data/data_1.txt', 'r') as f:
        lines = f.readlines()
        x1 = [(1+x) for x in range(len(lines))]
        y1 = np.array([int(line.split()[0]) for line in lines])
    with open('data/data_32.txt', 'r') as f:
        lines = f.readlines()
        x2 = [(1+x) for x in range(len(lines))]
        y2 = np.array([int(line.split()[0]) for line in lines])
    with open('data/data_16.txt', 'r') as f:
        lines = f.readlines()
        x3 = [(1+x) for x in range(len(lines))]
        y3 = np.array([int(line.split()[0]) for line in lines])
    with open('data/data_64.txt', 'r') as f:
        lines = f.readlines()
        x4 = [(1+x) for x in range(len(lines))]
        y4 = np.array([int(line.split()[0]) for line in lines])
    plt.figure()
    plt.title("Block size calculation")
    plt.grid()
    plt.yticks([])
    plt.ylabel(r"Latency $\to$")
    plt.xlabel(r"No. of memory accesses $\to$")
    plt.plot(x1[:64],y1[:64],label='stride = 1B')
    plt.plot(x3[:64],y3[:64],label='stride = 16B')
    plt.plot(x2[:64],y2[:64],label='stride = 32B')
    plt.plot(x4[:64],y4[:64],label='stride = 64B')
    plt.legend()
    plt.savefig(plotsDir+'blockSize.png')
    plt.savefig(plotsDir+'blockSize.pdf')
    plt.savefig(plotsDir+'blockSize.svg')

    plt.figure()
    plt.title("Block size calculation")
    plt.grid()
    plt.yticks([])
    plt.ylabel(r"Latency $\to$")
    plt.xlabel(r"Byte number accessed $\to$")
    plt.plot(x1,y1)
    plt.savefig(plotsDir+'blockSize_1B.png')
    plt.savefig(plotsDir+'blockSize_1B.pdf')
    plt.savefig(plotsDir+'blockSize_1B.svg')


if __name__ == "__main__":
    plotBlockSize()
