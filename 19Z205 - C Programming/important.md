# Important Specific Cases

## 19Z205- C Programming

### Arguments and Parameters

Arguments are the values that are **passed** to a function when it is called. Parameters are the variables that are used to **receive the arguments** passed to a function.

### `scanf` and `gets`

`scanf` reads a string until it encounters a whitespace character. `gets` reads a string until it encounters a newline character. `scanf` is used to read formatted input from the standard input stream, while `gets` is used to read a line of text from the standard input stream.

### `scanf` and `getchar`

`scanf` reads a string until it encounters a whitespace character. `getchar` reads a single character from the standard input stream. `scanf` is used to read formatted input from the standard input stream, while `getchar` is used to read a single character from the standard input stream.

### Sorting a 2D Array

```c
// sort a string list in alphabetical order

#include <stdio.h>
#include <string.h>
int main()
{
    char stringlist[6][5] = {"Bass", "Ass", "Green", "Mine", "Cat", "Zoo"};
    char temp[5];
    int i, j, k;

    int count = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                count++;
                printf("Comparing ");
                printf("A : stringlist[%d][%d] = %c and ", i, k, stringlist[i][k]);
                printf("B : stringlist[%d][%d] = %c\n", j, k, stringlist[j][k]);
                if (stringlist[i][k] > stringlist[j][k])
                {
                    printf("A > B\n");
                    printf("Swapping %s and %s\n", stringlist[i], stringlist[j]);
                    strcpy(temp, stringlist[i]);
                    strcpy(stringlist[i], stringlist[j]);
                    strcpy(stringlist[j], temp);
                    break;
                }
                else if (stringlist[i][k] < stringlist[j][k])
                {
                    printf("A < B\n");
                    break;
                }
            }
        }
    }

    printf("The sorted string list is:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", stringlist[i]);
    }

    printf("Total counts = %d\n", count);
}
```

### Difference between `malloc` and `calloc`:

Both `malloc` and `calloc` are used to dynamically allocate memory in C, but there is a difference between them.

`malloc` is used to allocate a block of memory of a specified size. It takes one argument, which is the number of bytes to allocate. The memory block is not initialized, so it may contain garbage values.

`calloc` is used to allocate a block of memory of a specified size and initialize it to zero. It takes two arguments, which are the number of elements to allocate and the size of each element in bytes.

Here's an example:

```c
int *arr1 = (int *)`malloc`(5 * sizeof(int)); // allocate 5 integers
int *arr2 = (int *)`calloc`(5, sizeof(int)); // allocate and initialize 5 integers to 0
```

In the above example, arr1 contains garbage values, while arr2 contains 0s.

### Dynamically Allocating a 2 Dimensional Array

```c
int main() {
    int rows = 3, cols = 4;
    int **arr = (int **)malloc(rows*sizeof(int *)); 
    for (int i = 0; i < rows; i++){
        arr[i] = (int *)malloc(cols*sizeof(int));
    }
}
```

### Returns of function `feof`

The function `feof` takes in the file pointer and returns **1 if EOF is reached** and **0 if EOF is not Reached**

### Returns of function `getc`

`getc` returns the ASCII value of the character that was read. Type conversion from numeric ASCII to char and reverse can be easily done with the format specifier `%c
` and `%d`

### ASCII Value ranges

- 0 (48)
- 9 (57)
- A (65)
- Z (90)
- a (97)
- z (122)
