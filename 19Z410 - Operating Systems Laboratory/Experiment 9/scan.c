#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define DISK_SIZE 200

void SCAN(int arr[], int head, char* direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[SIZE], right[SIZE];
    int left_count = 0, right_count = 0;

    printf("Seek Sequence is\n");

    // Appending end values which have to be visited
    // before reversing the direction
    if (*direction == 'l') {
        left[left_count++] = 0;
    } else if (*direction == 'r') {
        right[right_count++] = DISK_SIZE - 1;
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head) {
            left[left_count++] = arr[i];
        } else if (arr[i] > head) {
            right[right_count++] = arr[i];
        }
    }

    // Sorting left and right arrays
    for (int i = 0; i < left_count - 1; i++) {
        for (int j = i + 1; j < left_count; j++) {
            if (left[j] < left[i]) {
                int temp = left[j];
                left[j] = left[i];
                left[i] = temp;
            }
        }
    }

    for (int i = 0; i < right_count - 1; i++) {
        for (int j = i + 1; j < right_count; j++) {
            if (right[j] < right[i]) {
                int temp = right[j];
                right[j] = right[i];
                right[i] = temp;
            }
        }
    }

    // Run the while loop two times.
    // One by one scanning right
    // and left of the head
    int run = 2;
    while (run--) {
        if (*direction == 'l') {
            for (int i = left_count - 1; i >= 0; i--) {
                cur_track = left[i];

                // Appending current track to seek sequence
                printf("%d\n", cur_track);

                // Calculate absolute distance
                distance = abs(cur_track - head);

                // Increase the total count
                seek_count += distance;

                // Accessed track is now the new head
                head = cur_track;
            }
            *direction = 'r';
        } else if (*direction == 'r') {
            for (int i = 0; i < right_count; i++) {
                cur_track = right[i];

                // Appending current track to seek sequence
                printf("%d\n", cur_track);

                // Calculate absolute distance
                distance = abs(cur_track - head);

                // Increase the total count
                seek_count += distance;

                // Accessed track is now the new head
                head = cur_track;
            }
            *direction = 'l';
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
}

// Driver code
int main() {
    // Request array
    int arr[SIZE] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    char direction = 'l';

    SCAN(arr, head, &direction);

    return 0;
}
