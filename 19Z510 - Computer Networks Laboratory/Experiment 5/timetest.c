#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables to store start and current times
    time_t start_time, current_time;

    // Get the start time
    start_time = time(NULL);

    // Loop until 5 seconds have passed
    while (1) {
        // Get the current time
        current_time = time(NULL);

        // Check if 5 seconds have passed
        if (difftime(current_time, start_time) >= 5.0) {
            printf("5 seconds have passed.\n");
            break;
        }
    }

    return 0;
}