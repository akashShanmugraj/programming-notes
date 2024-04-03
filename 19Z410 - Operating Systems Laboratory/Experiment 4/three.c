#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numberslist[] = {90, 81, 78, 95, 79, 72, 85};
int numberscount = 7;
double averagevalue;
int maximumvalue;
int minimumvalue;

void *computeaverage(void *arg)
{
    int sum = 0;
    for (int iterable1 = 0; iterable1 < numberscount; iterable1++)
        sum += numberslist[iterable1];
    averagevalue = (double)sum / numberscount;
    pthread_exit(NULL);
}
void *computemaximum(void *arg)
{
    maximumvalue = numberslist[0];
    for (int iterable1 = 1; iterable1 < numberscount; iterable1++)
    {
        if (numberslist[iterable1] > maximumvalue)
            maximumvalue = numberslist[iterable1];
    }
    pthread_exit(NULL);
}
void *computeminimum(void *arg)
{
    minimumvalue = numberslist[0];
    for (int iterable1 = 1; iterable1 < numberscount; iterable1++)
    {
        if (numberslist[iterable1] < minimumvalue)
            minimumvalue = numberslist[iterable1];
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, computeaverage, NULL);
    pthread_create(&tid2, NULL, computemaximum, NULL);
    pthread_create(&tid3, NULL, computeminimum, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    printf("The averagevalue value is %.2lf\n", averagevalue);
    printf("The minimumvalue value is %d\n", minimumvalue);
    printf("The maximumvalue value is %d\n", maximumvalue);
    return 0;
}