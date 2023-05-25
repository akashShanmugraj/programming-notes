# 19Z205 - C Programming 
## Problem Sheet 2
#### *Akash Shanmugaraj on 25nd May 2023*

1. **Trace the following code and determine the output. The code demonstrates a recursive function in C.
Also determine what the program does.**
```c
#include &lt;stdio.h&gt;
int recursiveTest(int n) {
if (n == 0) {
return 0;
} else {
return n + recursiveTest(n - 1);
}
}

int main() {
int num = 5;
int result = recursiveTest(num);
printf(&quot;Result of %d is: %d\n&quot;, num, result);
return 0;
}
```

Answer:
```
main() {
    line 1 - num = 5
    line 2 - call recursiveTest(5)
    recursiveTest(5){
        line 3
        line 4 - call recursiveTest(4)
        recursiveTest(4) {
            line 3
            line 4 - call recursiveTest(3)
            recursiveTest(3) {
                line 3
                line 4 - call recursiveTest(2)
                recursiveTest(2) {
                    line 3
                    line 4 - call recursiveTest(1)
                    recursiveTest(1) {
                        line 3
                        line 4 - call recursiveTest(0)
                        recursiveTest(0) {
                            line 1
                            line 2
                            return 0
                        }
                        line 4
                        return 1 + 0
                        return 1
                    }
                    line 4
                    return 2 + 1
                    return 3   
                }
                line 4
                return 3 + 3
                return 6
            }
            line 4
            return 4 + 6
            return 10 
        }
        line 4
        return 5 + 10
        return 15
    }
    main function ends
    return 0
}
```

2. **Write a C function named sort that takes a 1D integer array as input and sorts the array elements in
ascending order. The function should modify the original array passed as an argument. Implement the
function and provide a sample usage.**

```c
#include <stdio.h>

void sort(int elementArray[], int size){
    int tempVariable;
    for(int loopVariable1 = 0; loopVariable1 < size; loopVariable1++){
        for(int loopVariable2 = loopVariable1+1; loopVariable2 < size; loopVariable2++){
            if(elementArray[loopVariable1] > elementArray[loopVariable2]){
                tempVariable = elementArray[loopVariable1];
                elementArray[loopVariable1] = elementArray[loopVariable2];
                elementArray[loopVariable2] = tempVariable; 
            }
        }
    }
}

int main(){
    int numberArray[5] = {5, 1, 1, 2, 8};
    sort(numberArray, 5);
    for(int loopVariable1 = 0; loopVariable1 < 5; loopVariable1++){
        printf("%d ", numberArray[loopVariable1]);
    }
    return 0;
}
```

3. Write a program in C to perform the following operations on arrays of strings:
    - Find the length of the shortest string.
    - Find the length of the longest string.
    -  Calculate the average length of all the strings.
    - Count the number of strings with a length greater than a given threshold.

```c
int findShortestString(char arr[][100], int n){
    int loopVariable1, length, minimum = 100;

    for (loopVariable1 = 0; loopVariable1 < n; loopVariable1++)
    {
        length = strlen(arr[loopVariable1]);
        if (length < minimum)
        {
            minimum = length;
        }
    }

    return minimum;
}

int findLongestString()
{
    char str[5][20];
    int loopVariable1, length, maximum = 0;

    printf("Enter 5 strings:\n");
    for (loopVariable1 = 0; loopVariable1 < 5; loopVariable1++)
    {
        scanf("%s", str[loopVariable1]);
    }

    for (loopVariable1 = 0; loopVariable1 < 5; loopVariable1++)
    {
        length = strlen(str[loopVariable1]);
        if (length > maximum)
        {
            maximum = length;
        }
    }

    printf("Length of longest string is %d", maximum);

    return maximum;
}

float findAverageLength()
{
    char str[5][20];
    int loopVariable1, length, sum = 0;

    printf("Enter 5 strings:\n");
    for (loopVariable1 = 0; loopVariable1 < 5; loopVariable1++)
    {
        scanf("%s", str[loopVariable1]);
    }

    for (loopVariable1 = 0; loopVariable1 < 5; loopVariable1++)
    {
        length = strlen(str[loopVariable1]);
        sum += length;
    }

    printf("Average length of strings is %f", (float) sum / 5);

    return (float) sum/5;
}

int countStringsAboveThreshold(char arr[][100], int n, int threshold)
{
    int loopVariable1, length, count = 0;

    for (loopVariable1 = 0; loopVariable1 < n; loopVariable1++)
    {
        length = strlen(arr[loopVariable1]);
        if (length > threshold)
        {
            count++;
        }
    }

    printf("Number of strings with length greater than %d is %d", threshold, count);

    return count;
}
```
