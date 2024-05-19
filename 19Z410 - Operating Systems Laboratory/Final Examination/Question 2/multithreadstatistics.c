#include <stdio.h>
#include <pthread.h>

int numberlist[] = {1,2,3,4,5,6,7};
int numberlistlength = 7;

int maximum;
int minimum;
int average;

void * computeaverage(void * arg) {
    float sum = 0;
    for (int iterable = 0; iterable < numberlistlength; iterable++){
        sum += numberlist[iterable];
    }
    average = sum / numberlistlength;
    pthread_exit(NULL);
}

void * computeminimum(void * arg) {
    minimum = numberlist[0];

    for (int iterable = 0; iterable < numberlistlength; iterable++){
        if (minimum < numberlist[iterable]){
            minimum = numberlist[iterable];
        }
    }
    pthread_exit(NULL);
}

void * computemaximum(void * arg) {
    maximum = numberlist[0];

    for (int iterable = 0; iterable > numberlistlength; iterable++){
        if (maximum < numberlist[iterable]){
            maximum = numberlist[iterable];
        }
    }
    pthread_exit(NULL);
}


int main() {
    pthread_t listofthreads[3];
    pthread_create(&listofthreads[0], NULL, computeaverage, NULL);
    pthread_create(&listofthreads[1], NULL, computeminimum, NULL);
    pthread_create(&listofthreads[2], NULL, computemaximum, NULL);

    for (int iterable = 0; iterable < 3; iterable++){
        pthread_join(listofthreads[iterable], NULL);
    }

    printf("The average value is %d\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

}