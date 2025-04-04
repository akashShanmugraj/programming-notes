from mpi4py import MPI
import numpy as np
import sys
import random
import time

def calcpi(pointperprocess, rank):
    localcount = 0
    random.seed(time.time() + rank)

    for i in range(pointperprocess):
        x, y = random.random(), random.random()
        
        if x**2 + y**2 <= 1:
            localcount += 1
        
    return localcount

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    
    numsamples = None
    if rank == 0:
        if len(sys.argv) != 2:
            print("Usage: python bcast.py <number_of_samples>")
            sys.exit(1)
        numsamples = int(sys.argv[1])
        
        # Send numsamples to all other processes
        for i in range(1, size):
            comm.send(numsamples, dest=i, tag=0)
    else:
        # Receive numsamples from the root process
        numsamples = comm.recv(source=0, tag=0)
    
    pointsperprocess = numsamples // size
    remainder = numsamples % size
    
    if rank < remainder:
        pointsperprocess += 1
    
    localcount = calcpi(pointsperprocess, rank)
    globalcount = comm.reduce(localcount, op=MPI.SUM, root=0)
    
    if rank == 0:
        piestimate = (4 * globalcount) / numsamples
        print(f"Estimated Pi value: {piestimate}")
    
if __name__ == "__main__":
    main()