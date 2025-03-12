from mpi4py import MPI
import numpy as np

N = 4

def matrix_multiply(A_part, B):
    num_rows = A_part.shape[0]
    C_part = np.zeros((num_rows, N), dtype=np.int64)

    for i in range(num_rows):
        for j in range(N):
            C_part[i, j] = np.dot(A_part[i], B[:, j])

    return C_part

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    rows_per_process = N // size
    remainder = N % size

    if rank < remainder:
        rows_per_process += 1

    if rank == 0:
        A = np.random.randint(0, 10, (N, N), dtype=np.int64)
        B = np.random.randint(0, 10, (N, N), dtype=np.int64)
        print("\nMatrix A:\n", A)
        print("\nMatrix B:\n", B)

        sendcounts = np.array([(N // size + (1 if i < remainder else 0)) * N for i in range(size)])
        displacements = np.zeros(size, dtype=int)
        displacements[1:] = np.cumsum(sendcounts[:-1])
    else:
        A = None
        B = np.empty((N, N), dtype=np.int64)
        sendcounts = None
        displacements = None

    comm.Bcast(B, root=0)

    A_part = np.empty((rows_per_process, N), dtype=np.int64)
    comm.Scatterv([A, sendcounts, displacements, MPI.INT64_T], A_part, root=0)

    C_part = matrix_multiply(A_part, B)

    if rank == 0:
        C = np.empty((N, N), dtype=np.int64)
    else:
        C = None

    comm.Gatherv(C_part, [C, sendcounts, displacements, MPI.INT64_T], root=0)

    if rank == 0:
        print("\nResult Matrix C:\n", C)

if __name__ == "__main__":
    main()
