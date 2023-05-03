# 19Z205 - C Programming
Taught by **Dr Lovelyn Rose S, Associate Professor, PSG College of Technology**.
Notes drafted and maintained by Akash Shanmugaraj, PSGCT'26.

### _21st March 2023_

- C is a general purpose programming language created by Dennis Ritchie

- It is a compiled language and strongly typed

- Header files have the file extension `.h` and used to _include_ external functions and classes.

- For the above purpose, `include` keyword is used. This keyword is also known as a _directive_

- C maintains _one-to-one correspodence_ between format specifiers and variables

- The file `stdio.h` is found in the _/bin/mingw/include_ folder of that SDK installed, **mingw64**

- The process of installation adds the directory of mingw64 into the **Global Environmental Variables** of the Operating System. When the compiler (gcc) is called, which is also located in that directory, easily references the dependencies in _/include_ folder.

- Q1: **Write a program to print _Hello World_ onto the console**
  ```c
  # include <stdio.h>
  int main() {
  printf("Hello, World\n");
  return 0;
  }
  ```
- Q2: **Write a program to print a number onto the console**
  ```c
   # include <stdio.h>
   int main() {
   int number = 122;
   printf("%d", number);
   return 0
   }
  ```
- Q3: **Write a program to print a number with text onto the console**
  ```c
    # include <stdio.h>
    int main() {
    int number = 112;
    printf("Number initialized was %d", number);
    return 0
    }
  ```


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

### _18th April 2023_

- Q1: **Write a program to store 10 numbers in an array and find their average.**

  ```c
  #include <stdio.h>
  int main ()
  {

      int i, num[100];
      for(i=0; i< 10; i++){
          printf("Enter %dth number: ", i+1);
          scanf("%d", &num[i]);
      }
      int sum = 0;
      for (i = 0; i < 10; i++){
          sum += num[i];
      }
      printf("The sum is %d and the average is %f", sum, sum/(float) i);

      return 0;
  }
  ```

- Q2: **Write a program to swap adjacent elements of an array.**

  ```c
  #include <stdio.h>
  int main ()
  {
      int temp, arr[] = {1,2,3,4,5,6};
      int len = sizeof(arr)/sizeof(arr[0]);
      int m = len/2;
      for(int i = 1; i <= m; i++){
          temp = arr[2*(i-1) + 1];
          arr[2*(i-1) + 1] = arr[2*(i-1)];
          arr[2*(i-1)] = temp;
      }
      for(int i = 0; i < len; i++){
          printf("%d\t", arr[i]);
      }

      return 0;
  }
  ```

- Q3: **Write a program to print multiplication table of any number from input.**
  ```c
  #include<stdio.h>
  void main(){
    int i;
    printf("enter the value of i:");
    scanf("%d",&i);
    for(int j=1;j<=10;j++){
      if(j%5==0){
        continue;
      }
      printf("%d x %d = %d\n",j,i,(j*i));
    }
  }
  ```


### _25th April 2023_

- Q: Write a program to check whether a given matrix is stored in **Row Major Order** or **Column Major Order**

```c
#include <stdio.h>
void main()
{
  int rowLength = 3;
  int columnLength = 2;
  int myArray[3][2] = {{3, 4}, {5, 6}, {7, 8}};
  for (int rowloopvar = 0; rowloopvar < rowLength; rowloopvar++)
  {
    for (int columnloopvar = 0; columnloopvar < columnLength; columnloopvar++)
    {
      if (&myArray[rowloopvar][columnloopvar] - &myArray[rowloopvar][columnloopvar + 1] == 4)
      {
        printf("Row Major order followed");
      }
      else if (&myArray[rowloopvar][columnloopvar] - &myArray[rowloopvar + 1][columnloopvar] == 4)
      {
        printf("Column Major order followed");
      }
    }
  }
}
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

### _29th April 2023_

- In C, the `switch` statement provides a way to perform different actions based on different values of a single variable.

- General Syntax of `switch` statement is as follows
  ```c
  switch(expression) {
    case constant1:
        // statements to execute if expression == constant1
        break;
    case constant2:
        // statements to execute if expression == constant2
        break;
    .
    .
    .
    case constantN:
        // statements to execute if expression == constantN
        break;
    default:
        // statements to execute if none of the above cases is true
        break;
  }
  ```
- Q1: **Write a program in C to get a string input until a period (".")**

  ```c
  #include <stdio.h>

  int main() {
      char c;

      printf("Enter some text (end with a period): ");

      do {
          c = getchar();
          putchar(c);
      } while (c != '.');

      printf("\n");

      return 0;
  }
  ```

### _2nd May 2023_
- The `default` keyword is used in the `switch-case` if given variable does not match any `case`.
- Q: Write a program to _recursively_ calculate sum, product, different and quotient of two numbers, in the form of a _menu-driven_ calculator
  ```c
  #include<stdio.h>
  void main(){
    int a,b;
    char option;
    printf("This program calculates following functions :/\n1.addtion\n2.subract\n3.multiply\n4.divide\nEnter 'E' for quitting the program");
    do{
       scanf("%c",&option);
       switch(option){
        case '1':
           printf("enter the two numbers with space:");
           scanf("%d%d",&a,&b);
           printf("%d\n>>",a+b);
           break;
        case '2':
           printf("enter the two numbers with space:");
           scanf("%d%d",&a,&b);
           printf("%d\n>>",a-b);
           break;
        case '3':
           printf("enter the two numbers with space:");
           scanf("%d%d",&a,&b);
           printf("%d\n>>",a*b);
           break;
        case '4':
           printf("enter the two numbers with space:");
           scanf("%d%d",&a,&b);
           printf("%d\n>>",(float)a/b);
           break;   
        case 'E':
           printf("you pressed end");
           break;  
        default: 
           printf("you pressed !--");
           break;
       }
    }while(option!='E');
  }
    ```
- Arrays can also be used to store strings. For example, `char var` stores only one character, `char var[10]` stores a string with length _10_ and `char var[3][10]` can store 3 strings, each of maximum of 10 characters

- Q: Write a program to get character as input using `scanf`.

  ```c
  #include<stdio.h>
  void main(){
      char a,x;
      scanf("%c",&a);
      x=getchar();
  }
  ```
- Q: Write a program to tnput character without spaces using `scanf` and `gets`.
  ```c
  #include<stdio.h>
  void main(){
      char x[10];
      scanf("%s",x);
      gets(x);
  }
  ```
- Q: Write a program to get one input of a string with spaces.

  ```c
  #include<stdio.h>
  void main(){
      char a[10];
      gets(a);
  }
  ```
- Q: Write a program to get paragraph as an input.

  ```c
  #include<stdio.h>
  void main(){
      char a[100];
      gets(a);
      printf("%s",a);
  }
  ```
- Q: Write a program to get multiple paragraphs as input.

  ```c
  #include<Stdio.h>
  void main(){
      char paragraph[3][100];
      int i=0;
      while(i<3){
          gets(paragraph[i]);
          printf("%s\n",paragraph[i]);
          i++; 
      }
  }
  ```
- Q: Write a program to get input until d is pressed.
  ```c
  #include<stdio.h>
  void main(){
      char a;
      do{
          a=getchar;
          printf("%c",a);
      }while(a!='d');
  }
  ```
#### **Extra Question**
- Q. Given a matrix of 0's and 1's find the largest sub matrix containing all ones

