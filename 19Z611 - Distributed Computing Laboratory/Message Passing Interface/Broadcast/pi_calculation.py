from mpi4py import MPI
import numpy as np
import sys
import random
import time

def calculate_pi(points_per_process, rank):
    local_count = 0
    random.seed(time.time() + rank)

    for _ in range(points_per_process):
        x, y = random.random(), random.random()
        if x**2 + y**2 <= 1:
            local_count += 1

    return local_count

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    num_samples = None
    if rank == 0:
        if len(sys.argv) != 2:
            print(f"Usage: python {sys.argv[0]} <number_of_samples>")
            sys.exit(1)
        num_samples = int(sys.argv[1])

    num_samples = comm.bcast(num_samples, root=0)

    points_per_process = num_samples // size
    remainder = num_samples % size

    if rank < remainder:
        points_per_process += 1

    local_count = calculate_pi(points_per_process, rank)
    global_count = comm.reduce(local_count, op=MPI.SUM, root=0)

    if rank == 0:
        pi_estimate = 4.0 * global_count / num_samples
        print(f"Estimated value of Pi: {pi_estimate}")

if __name__ == "__main__":
    main()
