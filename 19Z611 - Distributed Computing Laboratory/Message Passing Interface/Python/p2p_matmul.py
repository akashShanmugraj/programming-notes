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
        A = np.random.randint(0, 2, (N, N), dtype=np.int64)
        B = np.random.randint(0, 2, (N, N), dtype=np.int64)
        print("\nMatrix A:\n", A)
        print("\nMatrix B:\n", B)

        for i in range(1, size):
            comm.Send([B, MPI.INT64_T], dest=i, tag=0)

        start_row = 0
        for i in range(size):
            rows_to_send = N // size + (1 if i < remainder else 0)
            if i == 0:
                A_part = A[start_row:start_row + rows_to_send, :]
            else:
                comm.Send([A[start_row:start_row + rows_to_send, :], MPI.INT64_T], dest=i, tag=1)
            start_row += rows_to_send
    else:
        B = np.empty((N, N), dtype=np.int64)
        comm.Recv([B, MPI.INT64_T], source=0, tag=0)

        A_part = np.empty((rows_per_process, N), dtype=np.int64)
        comm.Recv([A_part, MPI.INT64_T], source=0, tag=1)

    C_part = matrix_multiply(A_part, B)

    if rank == 0:
        C = np.empty((N, N), dtype=np.int64)
        start_row = 0
        C[start_row:start_row + rows_per_process, :] = C_part
        start_row += rows_per_process

        for i in range(1, size):
            rows_to_receive = N // size + (1 if i < remainder else 0)
            comm.Recv([C[start_row:start_row + rows_to_receive, :], MPI.INT64_T], source=i, tag=2)
            start_row += rows_to_receive
    else:
        comm.Send([C_part, MPI.INT64_T], dest=0, tag=2)

    if rank == 0:
        print("\nResult Matrix C:\n", C)

if __name__ == "__main__":
    main()