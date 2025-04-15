from mpi4py import MPI
import numpy as np

N = 4

def matmul(apart, b):
    asize = apart.shape[0]
    cpart = np.zeros((asize, N), dtype=np.int64)
    
    for i in range(asize):
        for j in range(N):
            cpart[i,j] = np.dot(apart[i], b[:, j])
    
    return cpart

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    
    rowsperprocess = N // size
    remainder = N % size
    
    if rank < remainder:
        rowsperprocess += 1
    
    if rank == 0:
        A = np.random.randint(0, 10, (N, N), dtype=np.int64)
        B = np.random.randint(0, 10, (N, N), dtype=np.int64)
        print(A)
        print(B)
        sendCount = np.zeros(size, dtype=int)
        displacement = np.zeros(size, dtype=int)
        
        for i in range(size):
            if i < remainder:
                sendCount[i] = (rowsperprocess + 1) * N
            else:
                sendCount[i] = (rowsperprocess) * N
        
        displacement[1:] = np.cumsum(sendCount[:-1])
    else:
        A = None
        B = np.empty((N,N), dtype=np.int64)
        sendCount = None
        displacement = None
    
    comm.bcast(B, root=0)
    
    apart = np.empty((rowsperprocess, N), dtype=np.int64)
    comm.Scatterv([A, sendCount, displacement, MPI.INT64_T], apart, root=0)
    
    cpart = matmul(apart, B)
    if rank == 0:
        C = np.empty((N,N), dtype=np.int64)
    else:
        C = None
    
    comm.Gatherv(cpart, [C, sendCount, displacement, MPI.INT64_T], root=0)
    
    if rank == 0:
        print(C)

if __name__ == "__main__":
    main()