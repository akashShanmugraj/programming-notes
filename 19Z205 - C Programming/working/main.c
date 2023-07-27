#include<stdio.h>

// int function1() {
//     int number = 10;
//     int *numberpointer = &number;
//     printf("number ADDRESS = %ls\n", &number);
//     printf("number = %d\n", number);
//     printf("numberpointer ADDRESS = %ls\n", numberpointer);
//     printf("numberpointer = %d\n", *(numberpointer));
// }

// int function2() {
//     int numberarray[10] = {1,2,3,4,5,6,7,8,9};
//     int *numberarraypointer = &numberarray;
//     for (int i = 0; i < 10; i++){
//         printf("from numberarray = %d\n", numberarray[i]);
//         printf("from numberarraypointer = %d\n", *(numberarraypointer + i));
//     }
// }
// a function that takes an int ** array and prints all elements
int samplepointerfunction(int **numberarraypointer, int size){
    printf("numberarraypointer = %d\n", *numberarraypointer);
    printf("ADD (%ld : %d , %ld : %d) \n", numberarraypointer, *(numberarraypointer), numberarraypointer + 1, *(numberarraypointer + 1));

    printf("In samplepointerfunction \n");
    for (int i = 0; i < size; i++){
        printf("from numberarraypointer= %d\n", *(numberarraypointer + i));
    }
}

// int samplepointerfunction(int *numberarraypointer, int size){
//     printf("numberarraypointer = %d\n", *numberarraypointer);
//     printf("ADD (%ld : %d , %ld : %d) \n", numberarraypointer, *(numberarraypointer), numberarraypointer + 1, *(numberarraypointer + 1));

//     printf("In samplepointerfunction \n");
//     for (int i = 0; i < size; i++){
//         printf("from numberarraypointer= %d\n", *(numberarraypointer + i));
//     }
// }



int main(){
    int samplearray[4][3] = {{1,2,3},{4,5,6},{7,8,9}, {10,11,12}};
    int* samplearraypointer = samplearray;
    int** samplearraypointer2 = &samplearraypointer;
    // print all elements from samplearraypointer2
}   
// int function3() {
//     int samplearray[3] = {1,2,3};
//     int offset = 1;
//     int *samplearraypointer = samplearray;
//     printf("samplepointerfunction() [CALL]\n");
//     samplepointerfunction(samplearraypointer, 3);
//     printf("\n\n");
//     printf("samplefunction() WITH OFFSET %d [CALL]\n", offset);
//     samplefunction(samplearray + offset, 3 - offset);
// } 


