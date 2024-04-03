#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_primes(void *arg)
{
    int targetnumber = *((int *)arg);
    for (int iterable1 = 2; iterable1 <= targetnumber; iterable1++)
    {
        int isprimeboolean = 1;
        for (int iterable2 = 2; iterable2 * iterable2 <= iterable1; iterable2++)
        {
            if (iterable1 % iterable2 == 0)
            {
                isprimeboolean = 0;
                break;
            }
        }
        if (isprimeboolean)
            printf("%d ", iterable1);
    }
    printf("\targetnumber");
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\targetnumber", argv[0]);
        exit(EXIT_FAILURE);
    }
    int targetnumber = atoi(argv[1]);
    pthread_t tid;
    pthread_create(&tid, NULL, print_primes, &targetnumber);
    pthread_join(tid, NULL);
    return 0;
}