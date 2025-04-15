#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int data;

    MPI_Init(&argc, &argv);               // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get current process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get total number of processes

    // ---------- Broadcast Example ----------
    if (rank == 0) {
        data = 1234;
        printf("Process %d broadcasting data: %d\n", rank, data);
    }

    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received broadcasted data: %d\n", rank, data);

    // ---------- Point-to-Point Example ----------
    if (rank == 0) {
        int sendData = 999;
        MPI_Send(&sendData, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent point-to-point data: %d to Process 1\n", rank, sendData);
    } else if (rank == 1) {
        int recvData;
        MPI_Recv(&recvData, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received point-to-point data: %d from Process 0\n", rank, recvData);
    }

    MPI_Finalize(); // Clean up
    return 0;
}
