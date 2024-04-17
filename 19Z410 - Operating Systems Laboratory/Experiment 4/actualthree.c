#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 1000

int numbers[MAX_NUMBERS];
int num_count;

double average;
int minimum;
int maximum;

void *calculate_average(void *arg) {
    double sum = 0;
    for (int i = 0; i < num_count; i++) {
        sum += numbers[i];
    }
    average = sum / num_count;
    pthread_exit(NULL);
}

void *calculate_minimum(void *arg) {
    minimum = numbers[0];
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    pthread_exit(NULL);
}

void *calculate_maximum(void *arg) {
    maximum = numbers[0];
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number1> <number2> ... <numberN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc - 1 > MAX_NUMBERS) {
        fprintf(stderr, "Too many numbers. Maximum allowed is %d\n", MAX_NUMBERS);
        exit(EXIT_FAILURE);
    }

    num_count = argc - 1;
    for (int i = 0; i < num_count; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    pthread_t average_thread, minimum_thread, maximum_thread;

    pthread_create(&average_thread, NULL, calculate_average, NULL);
    pthread_create(&minimum_thread, NULL, calculate_minimum, NULL);
    pthread_create(&maximum_thread, NULL, calculate_maximum, NULL);

    pthread_join(average_thread, NULL);
    pthread_join(minimum_thread, NULL);
    pthread_join(maximum_thread, NULL);

    printf("The average value is %.2f\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

    return 0;
}
