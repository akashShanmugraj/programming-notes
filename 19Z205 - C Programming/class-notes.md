# 19Z205 - C Programming

Taught by **Dr Lovelyn Rose S, Associate Professor, PSG College of Technology**.
Notes drafted and maintained by Akash Shanmugaraj, PSGCT'26.

| Index (by topic)            |
|-------------------------------|
|[Switch Case](#switch-case)|
|[Terenary Operators](#terenary-operators)|
|[Logical and Bitwise Operators](#logical-and-bitwise-operators)|
|[String Functions](#string-functions)|
|[Pointers](#pointers)|
|[Functions](#functions)|
|[Recursion](#recursion)|
|[Structures](#struct)|
|[Storage Classes](#storage-classes)|
|[Dynamic Memory Allocation](#dynamic-memory-allocation)|

| Index (by date)            |
|--------------------------------|
| [21st March 2023](#21st-march-2023) |
| [28th March 2023](#28th-march-2023) |
| [29th March 2023](#29th-march-2023) |
| [18th April 2023](#18th-april-2023) |
| [25th April 2023](#25th-april-2023) |
| [26th April 2023](#26th-april-2023) |
| [28th April 2023](#28th-april-2023) |
| [29th April 2023](#29th-april-2023) |
| [2nd May 2023](#2nd-may-2023)    |
| [3rd May 2023](#3rd-may-2023)    |
| [20th May 2023](#20th-may-2023)   |
| [23rd May 2023](#23rd-may-2023)   |
| [24th May 2023](#24th-may-2023)   |
| [26th May 2023](#26th-may-2023)   |
| [29th May 2023](#29th-may-2023)   |
| [31st May 2023](#31st-may-2023)   |
| [16th June 2023](#16th-june-2023)   |

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

### _28th March 2023_

- Unary operations(++/--) can be of two types, _Prefix_ and _Postfix_.
- The prefix increment operator makes change in value before assigning it to the variable, while the postfix makes changes after assignment.
- For example,

  ```c
  int number1 = 10, number2 = 13;
  int prefixnumber, postfixnumber;
  prefixnumber = ++number1;
  postfixnumber = number2++;
  printf("Number on which number was prefixed was %d \n", prefixnumber);
  printf("Number on which number was postfixed was %d", postfixnumber);
  ```

  Output of the above program is,

  ```
  Number on which number was prefixed was 9
  Number on which number was postfixed was 13
  ```

- Above example for incrementation operator can also be applied for Decrementation operator.
- **Q: Write a program to print numbers in a pyramidal form**

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

### _29th March 2023_

1. The most optimized way to store signed integers is by using _2's Complement_
2. Positive numbers are stored as such and negative numbers are stored with a preceeding bit, called the **most-significant-bit (MSB)**
3. Below is an alternative way to use a for loop with _single-statement_

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

- Question1: Write a program to swap adjacent elements of an array

  ```c
  #include <stdio.h>
  void main()
  {
    int lengthOfArray = 5;
    int n[5] = {5, 6, 7, 8, 9};
    int average;
    int loopvariable;

    for (loopvariable = 0; loopvariable < lengthOfArray; loopvariable++)
    {
      // Looping to find elements on odd index (1,3,5)
      if (loopvariable % 2 == 1)
      {
        // and wapping the value at that nth index with (n-1)th index
        int value1 = n[loopvariable - 1];
        int value2 = n[loopvariable];
        int temporaryValue = value1;
        n[loopvariable - 1] = value2;
        n[loopvariable] = temporaryValue;
      }
    }

    // printing every element in the array for verification
    for (loopvariable = 0; loopvariable < lengthOfArray; loopvariable++)
    {
      printf("%d \n", n[loopvariable]);
    }
  }
  ```

### _18th April 2023_

- `sizeof` function gives the length of memory allocation of the given object. For example, 4 bytes for every integer, and 1 byte for every character.
-

- Q1: **Write a program to store 10 numbers in an array and find their average.**

  ```c
  #include <stdio.h>
  int main ()
  {

      int loopvariable1, num[100];
      for(loopvariable1=0; loopvariable1< 10; loopvariable1++){
          printf("Enter %dth number: ", loopvariable1+1);
          scanf("%d", &num[loopvariable1]);
      }
      int sum = 0;
      for (loopvariable1 = 0; loopvariable1 < 10; loopvariable1++){
          sum += num[loopvariable1];
      }
      printf("The sum is %d and the average is %f", sum, sum/(float) loopvariable1);

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
      for(int loopvariable1 = 1; loopvariable1 <= m; loopvariable1++){
          temp = arr[2*(loopvariable1-1) + 1];
          arr[2*(loopvariable1-1) + 1] = arr[2*(loopvariable1-1)];
          arr[2*(loopvariable1-1)] = temp;
      }
      for(int loopvariable1 = 0; loopvariable1 < len; loopvariable1++){
          printf("%d\t", arr[loopvariable1]);
      }

      return 0;
  }
  ```

- Q3: **Write a program to print multiplication table of any number from input.**
  ```c
  #include<stdio.h>
  void main(){
    int loopvariable1;
    printf("enter the value of loopvariable1:");
    scanf("%d",&loopvariable1);
    for(int j=1;j<=10;j++){
      if(j%5==0){
        continue;
      }
      printf("%d x %d = %d\n",j,loopvariable1,(j*loopvariable1));
    }
  }
  ```
- Q: Write a program to print memory addresses of numbers (from 1 to 5).

  ```c
    #include &lt;stdio.h&gt;
  int main() {
  int loopvariable1;
  for(loopvariable1=1;loopvariable1&lt;=5;loopvariable1++)
  {
  printf(&quot;%d&quot;,&amp;loopvariable1);
  }
  }
  ```

- Use the following format specifiers for its corresponding value

  | Format Specifier | Specialty   |
  | ---------------- | ----------- |
  | `%d`             | Decimal     |
  | `%o`             | Octal       |
  | `%x`             | Hexadecimal |

  Note: Similar formatting for binary is **not available**

- We can specify to retain or truncate number of decimal spaces, like the below code

  ```c
  #include <stdio.h>
  int main() {
  float x=35;
  printf("Decimal = %0.4f",x);
  }
  ```

  Above program retains 4 decimal places in the output

- Printing the array object directly only prints the memory location of the first element in that array.
- Printing an element out of array index limit, does not raise an exception, but prints some random value, called _grabage values_

### _25th April 2023_

- Q: Write a program to intialize a matrix (consider 3 x 2), fill every element by user prompt and find its sum.

```c
  #include <stdio.h>
int main()
{
  int ar[3][2];
  int loopvariable1, j;
  int sum = 0;
  for (loopvariable1 = 0; loopvariable1 < 3; loopvariable1++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &ar[loopvariable1][j]);
    }
  }
  for (loopvariable1 = 0; loopvariable1 < 3; loopvariable1++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("%d\t", ar[loopvariable1][j]);
    }
    printf("\n");
  }
  for (loopvariable1 = 0; loopvariable1 < 3; loopvariable1++)
  {
    for (j = 0; j < 2; j++)
    {
      sum = sum + ar[loopvariable1][j];
    }
  }
  printf("%d", sum);
```

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

### _26th April 2023_

- For any operations regarding Matrices, every induvidual element must be accessed seperately and

### _28th April 2023_

- Every string has a `\0` at its end, despite length constraints during declaration
- For scanning a string, `&` is not required to store its value in variable
- `scanf` will store the the string until whitespace. The rest is stored in the input buffer. For Example,

  ```c
  for (int iterable = 0; iterable <= n; iterable++) {
    scanf("%s", characterObject)
  }
  ```

  On inputting _Hello World_, scanf only takes _Hello_ and stores in `characterObject` while _World_ is stored in the input buffer.

- The function `fflush(stdin)` is used to clear all buffer.
- Consider the below program.

  ```c
  char characterObject[10];
  for (int iterable = 0; iterable <= 10; iterable++) {
    scanf("%s", characterObject);
  }
  ```

  If the input _Hello World_ is given in the `0th` Iteration, _Hello_ gets stored in the `characterObject` and _World_ moves on to the Input Buffer.

  Later in the second iteration, the program refuses an input and simply takes _World_ from the buffer and stores it in `characterObject`

  This process is repeated until availability of world in the Input Buffer

### _29th April 2023_
### Switch Case
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
      int loopvariable1=0;
      while(loopvariable1<3){
          gets(paragraph[loopvariable1]);
          printf("%s\n",paragraph[loopvariable1]);
          loopvariable1++;
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

### _3rd May 2023_

### **Terenary Operators**

- Terenary Operators in C are used as a quicker alternative to conditional statement
- We use the ternary operator in C to run one code when the condition is true and another code when the condition is false.
- Syntax of a Terenary Operator is as follows:
  ```c
  testCondition ? expression1 : expression 2;
  ```
- Q: Write a program to find the maximum of two given numbers using Terenary Operators

  ```c
  #include <stdio.h>
  int main() {
    int max;
    int number1 = 10;
    int number2 = 20;
    max = (number1 > number2) ? number1:number2;
    printf("%d\n", max);

  }
  ```

- Q: Write a program to find whether the given number is even or odd, using Terenary Operators.

  ```c
  #include <stdio.h>
  int main() {
    int max;
    char res;
    int number1 = 11;
    res = (number1 % 2) ? 'O':'E';
    printf("%c\n", res);

  }
  ```

- Q: Write a program to find the greatest number among three given numbers, using Terenary Operators.

  ```c
  #include <stdio.h>
  int main() {
    int max;
    int number1 = 10;
    int number2 = 20;
    int n3 = 5;
    max = number1 > number2 ? (number1 > n3 ? number1 : n3) : (number2 > n3 ? number2 : n3);
    printf("%d\n", max);

  }
  ```

### **Logical and Bitwise Operators**

- Logical AND in C uses following notation : `&&`

- Logical OR in C uses following notation : `||`

- The `&` (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.

- The `|` (bitwise OR) in C takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.

- The `^` (bitwise XOR) in C takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.

- The `<<` (left shift) in C takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift.

- The `>>` (right shift) in C takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift.

- Simply, left-shift for the expression `number1 << number2` will evaluvate `number1 * (2^number2)`

- Similarly, right-shift for the expression `number1 >> number2` will evaluvate `number1 / (2^number2)`

- The `~` (bitwise NOT) in C takes one number and inverts all bits of it.

**Specifications in `scanf`**

- There is a provision in C to allow or restrict certain set of characters in scanf, as a format specifer.

- In a `scanf` statement, use a format specifier like `%[values]` to allow all characters, or `%[^value]` to restrict all characters in/under `values`.

- Q: Write a program in C to scan for input , which allows only letters, both uppercase and lowercase.

  ```c
  #include <stdio.h>
  void main()
  {
    char x[10];
    scanf("%[a-zA-Z]", x);
    printf("%s", x);

  }

  ```

- Q: Write a program to scan for input until an arithmetic operator is found.

  ```c
  #include <stdio.h>
  void main()
  {
    char x[10];
    scanf("%[^+-*/%]", x);
    printf("%s", x);

  }
  ```

- Q: Write a program to scan for input until any number between 4 and 9 in found.

  ```c
  #include <stdio.h>
  void main()
  {
    char x[10];
    scanf("%[^9-4]", x);
    printf("%s", x);

  }
  ```

### String Functions

- String functions in C is made possible using `string.h` module.
- To get the length of a string, the `strlen()` function is used
  ```c
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%d", strlen(alphabet));
  ```
- Note that `sizeof` and `strlen` behaves differently, as `sizeof` also includes the `\0` character when counting.
  ```c
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%d", strlen(alphabet));   // 26
  printf("%d", sizeof(alphabet));   // 27
  ```
- `sizeof` will always return the memory size (in bytes), and not the actual string length

  ```c
  char alphabet[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%d", strlen(alphabet));   // 26
  printf("%d", sizeof(alphabet));   // 50
  ```

- `strcat()` function is used to concatenate two strings.

  ```c
  char str1[20] = "Hello ";
  char str2[] = "World!";

  // Concatenate str2 to str1 (result is stored in str1)
  strcat(str1, str2);

  // Print str1
  printf("%s", str1);
  ```

- `strcopy()` function is used to copy the value of one string to another.

  ```c
  char str1[20] = "Hello World!";
  char str2[20];

  // Copy str1 to str2
  strcpy(str2, str1);

  // Print str2
  printf("%s", str2);
  ```

- `strcomp()` function is used to compare two strings.

  ```c
  char str1[] = "Hello";
  char str2[] = "Hello";
  char str3[] = "Hi";

  // Compare str1 and str2, and print the result
  printf("%d\n", strcmp(str1, str2));  // Returns 0 (the strings are equal)

  // Compare str1 and str3, and print the result
  printf("%d\n", strcmp(str1, str3));  // Returns -4 (the strings are not equal)
  ```

  Homework:

- Swap two numbers without using a temporary variable.
- Find an element which occurs only once

### _20th May 2023_
### Pointers
reference: [dhakkshin's *Sem2_C* repository](https://github.com/Dhakkshin/sem2_C/blob/main/notes/pointers.md#200523)

- A Pointer basically stores the memory address of one variable in it

- It refers back to the memory address incase of a call and performs the requested operations

- Example Code:
  ```c
  #include <stdio.h>

  int main(void)
  {
      int number = 4;
      int *pointer = &number;
      printf("%i, %p\n", *pointer, pointer);
      //same as
      // printf("%i, %p\n", number, pointer);
  }
  ```
  
- Dereferencing is the process of accessing a memory address of the variable a pointer points to by adding an asterisk(*) infront of it, like the above example

- Pointer Arithmetic allows the pointer to access values in different memory address by performing arithmetic operations from its intial value

  ```c
  #include <stdio.h>

  int main(void)
  {
      int numberarray[] = {1,2,3,4};
      int *pointer = numberarray;

      printf("%i, %i\n",*pointer, *(pointer + 1));
  }
  ```
- Consider the following code:
  ```c
  #include <stdio.h>

  int main(void)
  {
      int number1[] = {1,2,3,4}, number2;
      int *pointer1 = number1;
      int *pointer2 = number2;

      printf("")

      // number1, number2, pointer1, pointer2
      // &number1, &number2, &pointer1, &pointer2
      // *pointer1, *pointer2
  }
  ```
  in the above code,
  |Memory Address|Value|
  | - | - |
  |number1, pointer1, pointer2, &number1, &number2, &pointer1, &pointer2|number2, *pointer1, *pointer2|

### _23rd May 2023_
### **Functions**

- The value passed in into a function call is called **argument** and variable in function declaration is called **parameter**

- Write a program with a function `isFactor()` which takes in two parameters and returns a boolean which is then used in a `main()` to print some final statements

  ```c
  #include <stdio.h>

  int isFactor(int a, int b)
  {
      if (a % b == 0)
      {
          return 1;
      }
      else
      {
          return 0;
      }
  }

  int main()
  {
      int a, b;
      printf("Enter two numbers: ");
      scanf("%d %d", &a, &b);
      if (isFactor(a, b))
      {
          printf("%d is a factor of %d\n", b, a);
      }
      else
      {
          printf("%d is not a factor of %d\n", b, a);
      }
      return 0;
  }

  ```

- Use the above function `isFactor()` for checking wheter a given number is a prime number or not

  ```c
  int isPrime(int a)
  {
      int loopvariable1;
      for (loopvariable1 = 2; loopvariable1 < a; loopvariable1++)
      {
          if (isFactor(a, loopvariable1) == 1)
          {
              return 0;
          }
      }
      return 1;
  }

  ```

- Use the above two functions `isFactor` and `isPrime` to create a new function `primerange` which prints prime numbers between two ranges

  ```c
  void primerange(int a, int b)
  {
      int loopvariable1;
      for (loopvariable1 = a; loopvariable1 <= b; loopvariable1++)
      {
          if (isPrime(loopvariable1) == 1)
          {
              printf("%d\n", loopvariable1);
          }
      }
  }

  int main()
  {
      int a, b;
      printf("Enter two numbers: ");
      scanf("%d %d", &a, &b);
      primerange(a, b);
      return 0;
  }
  ```

### _24th May 2023_

- When a function is called, all its local scope variables are created inthe memory. Once the function stops (return statement) the corresponding memory data is erased
- The `lifetime` of a variable refers to the duration for which the variable exists and holds a valid value in memory
- `push`, `pop`, `top` are functions that can be operated on a _stack_ datatype.
- Always, a virtual stack of functions are created. Here every element is called a **record/frame**.
- Every function call pushes that function object to the stack and every return statement pops that function object out of the stack 
- The `return` statement can contain an expression, which will be evaluvated and returned

### Recursion
- Every recursion algorithm must have a _base-case_ (condition for terminating recursion) and a _recursion-case_ (condition on what to do after recursion)
- Absence of a _base-case_ would lead to an infinte loop

- Write a program to compute the factorial of a number recursively
  ```c
  #include <stdio.h>

  int factorial(int n){
      if (n == 1){
          return 1;
      }
      else{
          return n * factorial(n-1);
      }
  }

  int main()
  {
      int n;
      printf("Enter a number: ");
      scanf("%d", &n);
      printf("The factorial of %d is %d", n, factorial(n));
      return 0;
  }
  ```

- A typical tracing for a recursion program (here factorial) should look like 
  ```
  main() {
    factorial(5) {
      line 4
      call factorial(4)
      factorial(4) {
        line 4
        call factorial(3)
        factorial(3) {
          line 4
          call factorial(2)
          factorial(2) {
            line 4
            call factorial(1)
            factorial(1) {
              line 1
              line 2
              return 1
            }
            2 * factorial(1)
            2 * 1
            return 2
          }
          3 * factorial(2)
          3 * 2
          return 6
        }
        4 * factorial(3)
        4 * 6
        return 24
      }
      5 * factorial(4)
      5 * 24
      return 120
    }
    main function ends
    return 0
  }
  ```

Homework:
- Write a program to compute fibonacci series recursively
  ```c
  
  #include <stdio.h>

  int fib(int n)
  {
      if (n == 0 || n == 1)
          return n;
      else
          return fib(n - 1) + fib(n - 2);
  }

  int main()
  {
      int n;
      printf("Enter the number of terms: ");
      scanf("%d", &n);
      printf("The fibonacci series is: ");
      for (int loopvariable1 = 0; loopvariable1 < n; loopvariable1++)
      {
          printf("%d ", fib(loopvariable1));
      }
      printf("\n");
      return 0;
  }
  ```

### _26th May 2023_
### `struct`
- A `struct` is a user-defined data type that allows to group  multiple variables of different types into a single unit

- It provides a way to represent a collection of data elements as a single entity

- General Syntax of a `struct` is as follows:
  ```c
  struct structureName {
   dataType member1;
   dataType member2;
   // ... additional members
  };
  ```
- Structs can be initiallized in two ways. 
  ```c
  struct Person person1;
  strcpy(person1.name, "John Doe");
  person1.age = 25;
  person1.height = 175.5;
  ```
  or
  ```c
  struct Person person2 = {"Jane Smith", 30, 162.3};

  ```
### _29th May 2023_

- String Assignment cannot happen like `str1 = str2`. Every index of the string(s) must be iterated and assigned

- `int number` is a _definition_ and `extern int i` is a _declaration_. 

- A declaration **does not** take up memory space.

- One can quickly assign properties of a struct by using below syntax:
  ```c
  struct employee e = {name="<employee-name>",id= 1001}
  ```
- One way of accessing a _structure member_ is via a period (**.**)
- Q: Write a program to copy a string from one variable to another variable
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main()
  {
      char str1[20] = "Hello World";
      char str2[20];

      int loopvariable1 = 0;
      while(str1[loopvariable1] != '\0')
      {
          str2[loopvariable1] = str1[loopvariable1];
          loopvariable1++;
      }
      str2[loopvariable1] = '\0';
      printf("%s", str2);
      return 0;
  }
  ```
- Q: Write a program to define an `employee` struct, assign its properties and print it in main function
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  struct employee
  {
      char name[20];
      int id;
  };

  int main()
  {
      struct employee e;
      printf("Enter the name of the employee: ");
      scanf("%s", e.name);
      printf("Enter the id of the employee: ");
      scanf("%d", &e.id);
      printf("The name of the employee is %s and his id is %d\n", e.name, e.id);
      return 0;
  }
  ```
Some alternatives of above program is
  ```c
  #include <stdio.h>

  struct employees
  {
      char name[100];
      int id;
  };

  int main(void)
  {
  struct employees e[3] = {{.name = "joerogan", 
  id = 1}, {.name = "morgan", .id = 2}, {.name = 
  "freeman", .id = 3}};

  }
  ```
- Create a structure `person` with `name`, `height`, `marks(6)` and `age`. Get input for 3 persons and average marks for each person.
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct person
  {
      char name[20];
      int height;
      int marks[6];
      int age;
      float average;
  };

  int main(void) {
      struct person personstructure[3];
      int loopvariable1;
      float highestAverage = 0;
      struct person highestAveragePerson;

      for (loopvariable1 = 0; loopvariable1 < 3; loopvariable1++) {
          printf("Enter name: ");
          scanf("%s", personstructure[loopvariable1].name);
          printf("Enter height: ");
          scanf("%d", &personstructure[loopvariable1].height);
          printf("Enter age: ");
          scanf("%d", &personstructure[loopvariable1].age);
          printf("Enter marks: ");
          scanf("%d %d %d %d %d %d", &personstructure[loopvariable1].marks[0], &personstructure[loopvariable1].marks[1], &personstructure[loopvariable1].marks[2], &personstructure[loopvariable1].marks[3], &personstructure[loopvariable1].marks[4], &personstructure[loopvariable1].marks[5]);
          personstructure[loopvariable1].average = (personstructure[loopvariable1].marks[0] + personstructure[loopvariable1].marks[1] + personstructure[loopvariable1].marks[2] + personstructure[loopvariable1].marks[3] + personstructure[loopvariable1].marks[4] + personstructure[loopvariable1].marks[5]) / 6.0;
          printf("Average: %.2f\n", personstructure[loopvariable1].average);
          if (personstructure[loopvariable1].average > highestAverage) {
              highestAverage = personstructure[loopvariable1].average;
              highestAveragePerson = personstructure[loopvariable1];
          }
      }
  }
  ```
- Q:Create a similar program like above, which computes the person with maximum average by passing the array of structures to a function.

  ```c
    #include <stdio.h>

  struct person
  {
      char name[100];
      float height;
      int age;
      float marks[6];
      float avg;
  };

  float avg(struct person avgstruct);
  struct person maxAvg(struct person avgstruct[], int length);

  int main(void)
  {
      struct person personstructure[3];

      for (int loopvariable1 = 0; loopvariable1 < 3; loopvariable1++)
      {
          printf("Person %d\nEnter the name: ", loopvariable1 + 1);
          fgets(personstructure[loopvariable1].name, 100, stdin);

          printf("Enter Height: ");
          scanf("%f", &personstructure[loopvariable1].height);

          printf("Enter Age: ");
          scanf("%d", &personstructure[loopvariable1].age);

          for (int loopvariable2 = 0; loopvariable2 < 6; loopvariable2++)
          {
              printf("Enter mark %d: ", loopvariable2 + 1);
              scanf("%f", &personstructure[loopvariable1].marks[loopvariable2]);
          }
          
          personstructure[loopvariable1].avg = avg(personstructure[loopvariable1]);
      }

      printf("\n");
      struct person maxRecord = maxAvg(personstructure, 3);
      printf("Person with maximum average is %s", maxRecord.name);   
  }

  float avg(struct person avgstruct)
  {
      float avg = 0;
      for (int loopvariable1 = 1; loopvariable1 < 6; loopvariable1++)
      {
          avg += avgstruct.marks[loopvariable1];
      }
      avg /= (float) 6;
      return avg;
  }

  struct person maxAvg(struct person avgstruct[], int length)
  {
      struct person maximum = avgstruct[0];
      for (int loopvariable1 = 0; loopvariable1 < length; loopvariable1 ++)
      {
          if (maximum.avg < avgstruct[loopvariable1].avg)
          {
              maximum = avgstruct[loopvariable1];
          }
      }

      return maximum;
  }
  ```
### _31st May 2023_
### **Storage Classes**
- There are totally four types of variables, 
  
  1. `auto`(global)
  2. `static`
  3. `register`
  4. `local`

- Variables that are more frequently used are explcitly declared to be stored in registry than RAM for faster access
- The keyword `register` is used
- Static Variables:
  - **Scope**: Static variables have either file scope (if defined outside of any function) or block scope (if defined inside a function). File scope means the variable is accessible from any function within the same source file. Block scope restricts the variable's visibility to the block where it is defined.
  - **Lifetime**: Static variables have a lifetime that extends throughout the execution of the program. They are created when the program starts and retain their values between function calls. If declared inside a function, they are initialized only once.

- Global Variables:

  - **Scope**: Global variables have file scope, meaning they can be accessed from any function within the same source file. Additionally, global variables can be accessed by other source files if they are declared with the "extern" keyword.
  - **Lifetime**: Global variables have a lifetime that extends throughout the execution of the program. They are created when the program starts and retain their values until the program terminates.

- Local Variables:

  - **Scope**: Local variables are declared within a block or function and have block scope. They are accessible only within the block where they are defined.
  - **Lifetime**: Local variables have a lifetime that depends on their storage class. Automatic (non-static) local variables are created when the block is entered and destroyed when it is exited.Static local variables have a lifetime that extends throughout the execution of the program, similar to static variables.

- Register Variables:

  - **Scope**: Register variables have block scope and are accessible only within the block where they are defined.
  - **Lifetime**: Register variables have a lifetime that is similar to automatic (non-static) local variables. They are created when the block is entered and destroyed when it is exited. However, the "register" keyword is often ignored by modern compilers, and the variables may be stored in memory instead of registers.


### _16th June 2023_
### **Dynamic Memory Allocation**
- Dynamic memory allocation in C allows the program to request memory from the system at runtime. 
- The standard library functions `malloc`, `calloc`, and `realloc` are used to allocate memory dynamically. 
- The `free` function is used to release the allocated memory when it is no longer needed.

- `malloc`:
   - Allocates a block of memory of the specified size in bytes.
   - The allocated memory block contains garbage values. You need to manually initialize the memory before using it.
   - Example:
     ```c
     int* ptr = (int*)malloc(5 * sizeof(int));
     ```

- `calloc`:
   - Allocates a block of memory for an array of elements, initializing all bytes to zero.
   - The allocated memory block is initialized to zero.
   - Example:
     ```c
     int* ptr = (int*)calloc(5, sizeof(int));
     ```

- `realloc`:
   - Resizes the memory block pointed to by `ptr` to the specified size.
   - If the new size is larger than the old size, the additional bytes are uninitialized. If the new size is smaller, the data may be truncated.
   - Example:
     ```c
     int* ptr = (int*)malloc(5 * sizeof(int));
     // Reallocate to a larger size
     ptr = (int*)realloc(ptr, 10 * sizeof(int));
     ```

In summary, `malloc` allocates memory without initializing it, `calloc` allocates memory and initializes all bytes to zero, `realloc` resizes an existing memory block, preserving the old data (if possible) and potentially extending or truncating the block.

- Write a program to allocate memory for int array of size 10 and write and read using pointer arithmetic.
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main()
  {
      int *pointer = malloc(sizeof(int) * 10);

      for (int loopvariable1 = 0; loopvariable1 < 10; loopvariable1++)
      {
          *(pointer + loopvariable1) = loopvariable1 + 1;
      }

      for (int loopvariable1 = 0; loopvariable1 < 10; loopvariable1++)
      {
          printf("%d\n", *(pointer + loopvariable1));
      }

      free(pointer);
  }
  ```
- Rewrite the above function to use the `calloc()` function 
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main(void)
  {
      int *pointer = calloc(10, sizeof(int));

      for (int loopvariable1 = 0; loopvariable1 < 10; loopvariable1++)
      {
          *(pointer + loopvariable1) = loopvariable1 + 1;
      }

      for (int loopvariable1 = 0; loopvariable1 < 10; loopvariable1++)
      {
          printf("%d\n", *(pointer + loopvariable1));
      }

      free(pointer);    
  }```

- Using `realloc()` to increase the size returns a pointer to a new larger chunk of memory. Existing values are being copied to a new memory address whislt the old memory address is discarded.
- Similarly, using `realloc()` for decrease the size returns original pointer with reduced size and values outside are discarded.
- Write a program that takes a sentence as input, dynamically allocates memory for that sentence and counts number of words in that sentence.
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <conio.h>

  int main(void)
  {
      printf("Enter a sentence:\n");

      int size = 1, words = 0;
      char *memoryPointer = malloc(sizeof(char));
      do
      {
          *(memoryPointer + size - 1) = getch();
          if (*(memoryPointer + size - 1) == ' ')
          {
              words += 1;
          }
          size += 1;
          memoryPointer = realloc(memoryPointer, sizeof(char) * size);
      }
      while (*(memoryPointer + size - 2) != '.');

      *(memoryPointer + size - 1) = '\0';

      printf("\nEnterned sentence is:\n%s\nIt has %i words", memoryPointer, words + 1);

      free(memoryPointer);
  }
  ```

### _21st June 2023_
Define a `struct` "name of the unit", "no of units" and "cost of one unit". Use this struct to calculate the total number of the units, from a array of `struct`(s)

```c
#include <stdio.h>

struct unit
{
    char name[20];
    int no_of_units;
    float cost_of_one_unit;
};

int main()
{
    struct unit shampoo;
    struct unit soap;
    struct unit toothpaste;

    int totalunits;
    totalunits = shampoo.no_of_units + soap.no_of_units + toothpaste.no_of_units;
    printf("Total number of units are %d", totalunits);
}
```