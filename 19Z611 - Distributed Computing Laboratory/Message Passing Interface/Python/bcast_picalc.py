from mpi4py import MPI
import sys
import numpy as np
import time
import random

def calcpi(pointsperprocess, rank):
    localcount = 0
    random.seed(time.time() + rank)
    
    for i in range(pointsperprocess):
        x, y = random.random(), random.random()
        
        if x**2 + y**2 <= 1:
            localcount += 1
        
    return localcount

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    
    numsamples = 0
    
    if rank == 0:
        numsamples = sys.argv[1]
    
    numsamples = comm.bcast(numsamples, root=0);
    
    pointsperprocess = numsamples // size
    remainder = pointsperprocess % size
    
    if rank < remainder:
        pointsperprocess += 1
    
    localcount = calcpi(pointsperprocess, rank)
    globalcount = comm.reduce(localcount, op=MPI.SUM, root=0);
    
    if rank == 0:
        pi = 4 * globalcount / numsamples
        print(pi)

if __name__ == "__main__":
    main()