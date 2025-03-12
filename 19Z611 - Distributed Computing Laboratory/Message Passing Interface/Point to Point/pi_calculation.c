#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define TOTAL_POINTS 1000000

int main(int argc, char **argv) {
    int rank, size;
    int pointsInCirclePartial = 0, pointsInCircle;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    srand(time(NULL) + rank);

    int pointsPerProcess = TOTAL_POINTS / size;
    for (int i = 0; i < pointsPerProcess; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        double distance = x * x + y * y;

        if (distance <= 1.0) {
            pointsInCirclePartial++;
        }
    }

    if (rank == 0) {
        pointsInCircle = pointsInCirclePartial;

        for (int i = 1; i < size; i++) {
            int receivedCount;
            MPI_Recv(&receivedCount, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            pointsInCircle += receivedCount;
        }

        double pi = 4.0 * pointsInCircle / TOTAL_POINTS;
        printf("Estimated value of Pi: %f\n", pi);
    } else {
        MPI_Send(&pointsInCirclePartial, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
