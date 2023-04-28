# Class Notes

### *28th March 2023*
- Unary operations(++/--) can be of two types, *Prefix* and *Postfix*. 
- The prefix increment operator makes change in value before assigning it to the variable, while the postfix makes changes after assignment.
- For example,
  ```c
  int number1 = 10, number2 = 13;
  int prefixnumber, postfixnumber;
  prefixnumber = ++number1;
  postfixnumber = number2++;
  ```
- TODO:Output
- Above example for incrementation operator can also be applied for Decrementation operator.
- Q: Write a program to print numbers in a pyramidal form
```c
#include <stdio.h>

int main()
{
    int numberLimit, spaces;
    int loopVariable1, loopVariable2, spaceVariable;
    printf("Enter the value for numberLimit: ");
    scanf("%d", &numberLimit);
    for(loopVariable1 = 1; loopVariable1 <= numberLimit; loopVariable1++){
        for(spaceVariable=0; spaceVariable < numberLimit - loopVariable1;spaceVariable++){
            printf("  ");
        }
        for(int loopVariable2 = 1; loopVariable2 <= loopVariable1; loopVariable2++){
            printf(" %d", loopVariable2);
        }
        for(int loopVariable2 = loopVariable1 - 1; loopVariable2 > 0; loopVariable2--){
            printf(" %d", loopVariable2);
        }
        printf("\n");
    }
}
```

### *29th March 2023*

1. The most optimized way to store signed integers is by using *2's Complement*
2. Positive numbers are stored as such and negative numbers are stored with a preceeding bit, called the **most-significant-bit (MSB)**
3. Below is an alternative way to use a for loop with *single-statement*
    ```c
    #include <stdio.h>

    int main() {
        int a = 10;
        for (a=1;a<=10;a++)
        printf("%d\n", a);
        }

    ``` 
4. Consider below program.
    ```c
    #include <stdio.h>

    int main() {
        int a;
        for (a=1;a<=10;a++)
        printf("%d\n", a);
        printf("%d\n", a*2);
    }
    ```
    Output of the above program is,
    ```c
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    22
    ```

### *28th April 2023*
  - Every string has a `\0` at its end, despite length constraints during declaration
  - For scanning a string, `&` is not required to store its value in variable
  - `scanf` will store the the string until whitespace. The rest is stored in the input buffer. For Example,
    ```c
    for (int iterable = 0; iterable <= n; iterable++) {
      scanf("%s", characterObject)
    }
    ```
    On inputting *Hello World*, scanf only takes *Hello* and stores in `characterObject` while *World* is stored in the input buffer.

  - The function `fflush(stdin)` is used to clear all buffer.
  - Consider the below program.
    ```c
    char characterObject[10];
    for (int iterable = 0; iterable <= 10; iterable++) {
      scanf("%s", characterObject);
    }
    ```
    If the input *Hello World* is given in the `0th` Iteration, *Hello* gets stored in the `characterObject` and *World* moves on to the Input Buffer. 
    
    Later in the second iteration, the program refuses an input and simply takes *World* from the buffer and stores it in `characterObject`

    This process is repeated until availability of world in the Input Buffer
