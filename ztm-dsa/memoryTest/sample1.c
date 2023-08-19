#include<stdio.h>


int main(){
    int x = 42;
    void *address = (void*) &x; // cast the address of x to a void* pointer

    printf("The address of x is %p\n", address);

    int sampleinput;
    printf("Enter a number: ");
    scanf("%d", &sampleinput);

    printf("Program EXIT with number %d\n", sampleinput);
}