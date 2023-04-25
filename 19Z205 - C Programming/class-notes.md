# Class Notes

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
