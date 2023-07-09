# Final Assignment Presentation
### _turned in by *Akash Shanmugaraj*_


_Write a recursive function to calculate the power of a given number (x^n), where both x and n are integers_
```c
#include <stdio.h>

float power(int x, int n){
    if (n == 0){
        return 1;
    }
    if (n < 0){
        return 1 / power(x, -n);
    }
    return x * power(x, n - 1);
}

int main(){
    int x, n;
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("%d^%d = %f\n", x, n, power(x, n));
    return 0;
}
```



_Implement a function that accepts a string and returns a dynamically allocated array of characters containing the unique characters in the string, sorted in ascending order._
```c
#include <stdio.h>

char *getUniqueChars(char *string){
    int i = 0, j = 0, k = 0;
    char *uniqueChars = (char *)malloc(sizeof(char) * 100);
    while (string[i] != '\0'){
        j = 0;
        while (uniqueChars[j] != '\0'){
            if (uniqueChars[j] == string[i]){
                break;
            }
            j++;
        }
        if (uniqueChars[j] == '\0'){
            uniqueChars[k] = string[i];
            k++;
        }
        i++;
    }
    uniqueChars[k] = '\0';
    return uniqueChars;
}

int main(){
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    char *uniqueChars = getUniqueChars(string);
    printf("Unique characters in the string are: %s\n", uniqueChars);
    return 0;
}
```

_Transpose the Given array_

```c
#include<stdio.h>

int tranpose(int a[3][3]){
    int transposearray[3][3];
    int rowcounter = 0, columncounter = 0;
    
    for (int i = 2; i > -1; i--){
        columncounter = 0;
        for (int j = 2; j > -1; j--)
        {
            transposearray[rowcounter][columncounter] = a[i][j];
            columncounter++;
        }
        rowcounter++;
    }
    printf("The transpose of the matrix is: ");    
    for (int i = 0; i < 3; i++){
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transposearray[i][j]);
        }
    }
    printf("\n");
    return 1;
}

int main(){
    // 2D array input
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    tranpose(a);
}
```

_5. Tower of Hanoi_
```c
#include <stdio.h>

int towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return 0;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    return 0;
}


int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
```

_7. Write a function that accepts a pointer to a string and removes all the vowels from the string, modifying it in-place._
```c
#include <stdio.h>
#include <string.h>

void vowelremove(char *string){
    int iterable1 = 0, iterable2 = 0;
    while (string[iterable1] != '\0'){
        if (string[iterable1] != 'a' && string[iterable1] != 'e' && string[iterable1] != 'iterable1' && string[iterable1] != 'o' && string[iterable1] != 'u'){
            string[iterable2] = string[iterable1];
            iterable2++;
        }
        iterable1++;
    }
    string[iterable2] = '\0';
}

int main(){
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    vowelremove(string);
    printf("The string without vowels is: %s", string);
}
```
rotate 9

```c
#include<stdio.h>

int main(){

    int originalarray[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int dim = 4;
    int tempvar;

    // Rotate the array
    for(int i = 0; i < dim/2; i++){
        // printf("i = %i\n", i);
        for (int j = i; j < dim-i-1; j++){
            tempvar = originalarray[i][j];
            printf("tempvar at %i,%i = %i\n", i, j, tempvar);
            originalarray[i][j] = originalarray[dim-j-1][i];
            printf("from %i,%i to %i,%i\n", dim-j-1, i, i, j);
            originalarray[dim-j-1][i] = originalarray[dim-i-1][dim-j-1];
            printf("from %i,%i to %i,%i\n", dim-i-1, dim-j-1, dim-j-1, i);
            originalarray[dim-i-1][dim-j-1] = originalarray[j][dim-i-1];
            printf("from %i,%i to %i,%i\n", j, dim-i-1, dim-i-1, dim-j-1);
            originalarray[j][dim-i-1] = tempvar;
            printf("from temp to %i,%i\n", j, dim-i-1);
        printf("\n");
        }
    }

    // Print the rotated array
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf("%2i ", originalarray[i][j]);
        }
        printf("\n");
    }
}
```

_10. Create a function that accepts a pointer to a 2D array of floating-point numbers and calculates the average value of each column, storing the results in a dynamically allocated 1D array. The function should return a pointer to the resulting array._

```c
#include <stdio.h>
#include <stdlib.h>

float * columnAverage(float (*arr)[3], int rowLength, int columnLength)
{
    float * averagelist = malloc(columnLength * sizeof(float));
    
    for (int j = 0; j < columnLength; j++)
    {
        averagelist[j] = 0;
        
        for (int i = 0; i < rowLength; i++)
        {
            printf("At %d (i),%d (j): %f\n", i, j, arr[i][j]);
            averagelist[j] += arr[i][j];
        }
        averagelist[j] /= rowLength;
        printf("Obtained Column Average: %f\n", averagelist[j]);
    }
    return averagelist;
}

int main(void)
{
    float arr[3][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8 ,9.9}};

    float * final = columnAverage(arr, 3, 3);
    printf("Final Array: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%f ", final[i]);
    }
    printf("\n");

}

```