# Important Specific Cases

## 19Z205- C Programming

### TODOS
- [ ] Printing Memory allocated after malloc

### Format Specifiers
In C, format specifiers are used in `printf` and `scanf` functions to specify the type of data that is being printed or read. Here are some of the most commonly used format specifiers in C:

- `%d`: integer
- `%f`: floating-point number
- `%c`: character
- `%s`: string
- `%p`: pointer
- `%x`: hexadecimal integer
- `%o`: octal integer
- `%e` or `%E`: scientific notation (exponential format)
- `%u`: unsigned integer
- `%ld`: long integer
- `%lu`: unsigned long integer
- `%lld`: long long integer
- `%llu`: unsigned long long integer

These format specifiers can be combined with various flags and modifiers to control the formatting of the output. For example, you can use the `%-10s` format specifier to left-align a string with a width of 10 characters, or you can use the `%02d` format specifier to print an integer with leading zeros to a width of 2 digits.

It's important to use the correct format specifier for the type of data that you are printing or reading, to avoid errors and undefined behavior.

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

### ASCII Values and  Ranges

- WHITESPACE (32)
- NEWLINE (10)
- TAB (9)
- 0 (48)
- 9 (57)
- A (65)
- Z (90)
- a (97)
- z (122)

### Memory Address
In most modern computer architectures, memory addresses are represented as unsigned integers, which means that they cannot be negative.
However, in some older computer architectures, memory addresses were represented as signed integers, which means that they could be negative.

### Array Manipulation with Pointers
```c
#include <stdio.h>

int** print2d(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i][j] + 1; 
        }
        printf("\n");
    }

    return arr;
}

int main() {
    int rows = 3;
    int cols = 4;
    int newarray[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };
    int *newpointer[3];
    for (int i = 0; i < rows; i++) {
        newpointer[i] = newarray[i];
    }
    int **newarraypointer = newpointer;

    int **finalarray = print2d(newarraypointer, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            printf("%d ", finalarray[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```