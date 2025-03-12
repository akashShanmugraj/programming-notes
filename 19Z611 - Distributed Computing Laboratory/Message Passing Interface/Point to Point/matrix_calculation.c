#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void fill_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 16;
        }
    }
}

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_process = N / size;
    int local_A[rows_per_process][N], local_C[rows_per_process][N];

    srand(time(NULL) + rank);

    if (rank == 0) {
        fill_matrix(A);
        fill_matrix(B);
        printf("Matrix A:\n");
        print_matrix(A);
        printf("Matrix B:\n");
        print_matrix(B);

        for (int i = 1; i < size; i++) {
            MPI_Send(B, N * N, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(A + (i * rows_per_process), rows_per_process * N, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
    }

    MPI_Recv(B, N * N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(local_A, rows_per_process * N, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    for (int i = 0; i < rows_per_process; i++) {
        for (int j = 0; j < N; j++) {
            local_C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                local_C[i][j] += local_A[i][k] * B[k][j];
            }
        }
    }

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            MPI_Recv(C + (i * rows_per_process), rows_per_process * N, MPI_INT, i, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        
        printf("Result Matrix C:\n");
        print_matrix(C);
    } else {
        MPI_Send(local_C, rows_per_process * N, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
