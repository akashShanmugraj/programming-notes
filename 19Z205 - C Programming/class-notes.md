# 19Z205 - C Programming

Taught by **Dr Lovelyn Rose S, Associate Professor, PSG College of Technology**.
Notes drafted and maintained by Akash Shanmugaraj, PSGCT'26.

### **DISCLAIMER**
_Note that the below file might not cover the entire course outcome (1&2) with absence of **specifics** in some introductory functions and arrays_

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

- Printing a variable with an ampersand, like `&variableName`, with an integer format specifier will print the memory address of the variable stored in the RAM.
- `continue` statement skips the remaining statements inside the loop
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
- Q: Write a program to print memory addresses of numbers (from 1 to 5).

  ```c
    #include &lt;stdio.h&gt;
  int main() {
  int i;
  for(i=1;i&lt;=5;i++)
  {
  printf(&quot;%d&quot;,&amp;i);
  }
  }
  ```

- Use the following format specifiers for its corresponding value

  | Format Specifier | Specialty   |
  | ---------------- | ----------- |
  | `%d`             | Decimal     |
  | `%o`             | Octal       |
  | `%x`             | Hexadecimal |

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
  int i, j;
  int sum = 0;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &ar[i][j]);
    }
  }
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("%d\t", ar[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 2; j++)
    {
      sum = sum + ar[i][j];
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

### _3rd June 2023_

**Terenary Operators**

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
    int n1 = 10;
    int n2 = 20;
    max = (n1 > n2) ? n1:n2;
    printf("%d\n", max);

  }
  ```

- Q: Write a program to find whether the given number is even or odd, using Terenary Operators.

  ```c
  #include <stdio.h>
  int main() {
    int max;
    char res;
    int n1 = 11;
    res = (n1 % 2) ? 'O':'E';
    printf("%c\n", res);

  }
  ```

- Q: Write a program to find the greatest number among three given numbers, using Terenary Operators.

  ```c
  #include <stdio.h>
  int main() {
    int max;
    int n1 = 10;
    int n2 = 20;
    int n3 = 5;
    max = n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3);
    printf("%d\n", max);

  }
  ```

**Logical and Bitwise Operators**

- Logical AND in C uses following notation : `&&`

- Logical OR in C uses following notation : `||`

- The `&` (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.

- The `|` (bitwise OR) in C takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.

- The `^` (bitwise XOR) in C takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.

- The `<<` (left shift) in C takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift.

- The `>>` (right shift) in C takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift.

- Simply, left-shift for the expression `n1 << n2` will evaluvate `n1 * (2^n2)`

- Similarly, right-shift for the expression `n1 >> n2` will evaluvate `n1 / (2^n2)`

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

  **String Functions**

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
- Write a program to swap two numbers without a temporary variable
  ```c
  #include <stdio.h>

  int main() {
      int a, b;
      printf("Enter two numbers: ");
      scanf("%d %d", &a, &b);

      // Swapping without using a temporary variable
      a = a + b;
      b = a - b;
      a = a - b;

      printf("After swapping, a = %d and b = %d", a, b);
      return 0;
  }
  ```
 
### _23rd May 2023_

- The value passed in into a function call is called **argument** and variable in function declaration is called **parameter**

- While structuring a function which takes in an array, it is always a best practice to also pass the array's size also

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
      int i;
      for (i = 2; i < a; i++)
      {
          if (isFactor(a, i) == 1)
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
      int i;
      for (i = a; i <= b; i++)
      {
          if (isPrime(i) == 1)
          {
              printf("%d\n", i);
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
