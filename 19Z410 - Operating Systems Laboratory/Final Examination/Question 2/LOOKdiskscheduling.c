#include <stdio.h>
#include <stdlib.h>

// Function to sort the array of requests in ascending order
void sortRequests(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to find the next nearest request from the current head position
int findNextNearest(int arr[], int n, int head, int direction) {
    int i;
    int nextNearest = -1; // Initialize to -1 if no request is found in the current direction

    // Iterate through the array based on the direction
    if (direction == 1) {
        // Moving towards higher track numbers
        for (i = 0; i < n; i++) {
            if (arr[i] >= head) {
                nextNearest = arr[i];
                break;
            }
        }
    } else {
        // Moving towards lower track numbers
        for (i = n-1; i >= 0; i--) {
            if (arr[i] <= head) {
                nextNearest = arr[i];
                break;
            }
        }
    }

    return nextNearest;
}

// Function to calculate total seek time
int calculateSeekTime(int arr[], int n, int initialHead) {
    int i, head = initialHead;
    int totalSeekTime = 0;
    int direction = 1; // Initial direction: moving towards higher track numbers

    // Sort the array of requests
    sortRequests(arr, n);

    // Service requests until all requests are processed
    while (1) {
        int nextNearest = findNextNearest(arr, n, head, direction);

        if (nextNearest == -1) {
            // No more requests in the current direction, change direction
            direction = 1 - direction;
            continue;
        }

        // Calculate seek time and update head position
        totalSeekTime += abs(nextNearest - head);
        head = nextNearest;
        printf("Serviced request at track %d\n", head);

        // Remove serviced request from array (not necessary for LOOK algorithm)

        // Check if all requests are serviced
        int allServiced = 1;
        for (i = 0; i < n; i++) {
            if (arr[i] != -1) {
                allServiced = 0;
                break;
            }
        }

        if (allServiced) break;
    }

    return totalSeekTime;
}

int main() {
    int initialHead = 50;
    int requests[] = {10, 22, 20, 40, 35, 60, 80, 90};
    int n = sizeof(requests) / sizeof(requests[0]);

    int totalSeekTime = calculateSeekTime(requests, n, initialHead);
    printf("Total seek time: %d\n", totalSeekTime);

    return 0;
}
