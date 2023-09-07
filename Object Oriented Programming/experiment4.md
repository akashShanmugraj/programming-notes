<p>Experiment 4<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date: 14.09.2023</p>

<h1 align="center">Java Programs - II</h1>

### 1. Printing given pattren
**Aim: Write a program that uses a block of code as a target of a for loop and generate output as follows**

```java
// assume function is called as question1(20)
public static void question1(int targetnumber){
        for (int iterable = 0; iterable < 10; iterable++) {
            System.out.println("x: "+iterable);
            System.out.println("y: "+targetnumber);
            System.out.println("");
            targetnumber -= 2;
        }
    }
```
### Output
```
x: 0
y: 20

x: 1
y: 19

x: 2
y: 18

x: 3
y: 17

...

x: 9
y: 2
```
---
### 2. Area of circle with `double`s

**AIM: Write a java program that uses double variables to compute area of circle**

```java
// assume function is called as question2(12.0)
public static void question2(double radius){
        System.out.println("Area of circle: "+(Math.PI*Math.pow(radius, 2)));
    }
```
### Output
```
Area of circle: 452.16
```
---
### 3. Factorial of a number
**AIM: Write a Java program to compute factorial of a given number**

```java
// assume function is called as question3(7)
public static void question3(int targetnumber){
        long factorialnumber = 1;
        for (int iterable = 1; iterable <= targetnumber; iterable++) {
            factorialnumber *= iterable;
        }
        System.out.println("Factorial: "+factorialnumber);
    }
```
### Output
```
Factorial: 5040 
```
---
### 4. Leap Year
**AIM: Write a Java program to calculate if the given year is leap year or not.**

```java
// assume function is called as question4(2004) and question4(2023)
public static void question4(int targetyear){
    if (targetyear%4==0 && targetyear%100!=0 || targetyear%400==0){
        System.out.println("Leap year");
    } else {
        System.out.println("Not leap year");
    }
}
```
### Output
```
Leap year
Not leap year

```
---
### 5. Check if number is Odd / Even
**AIM: Write a Java program to find if the given number is a odd number or even number.**

```java
// assume function is called as question5(10) and question5(33)
public static void question5(int targetnumber){
    if (targetnumber%2==0){
        System.out.println("Even number");
    } else {
        System.out.println("Odd number");
    }
}
```
### Output
```
Even number
Odd number
```
---
### 6. For the given integer just print the sum of all even digits and odd digits separately.
**AIM: Write a Java program to calculate sum of all even number and odd numbers seperately, from 1 to some given number N**

```java
public static void question6(){
    int sourceinteger = 0;
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a positive integer: ");
    int targetnumber = scanner.nextInt();
    while (targetnumber > 0){
        sourceinteger += targetnumber;
        System.out.print("Enter a positive integer: ");
        targetnumber = scanner.nextInt();
    }
    System.out.println("Summation of all above numbers is "+sourceinteger);
}
```
### Output
```
Enter a positive integer: 2
Enter a positive integer: 4
Enter a positive integer: 1
Enter a positive integer: 6
Enter a positive integer: 8
Enter a positive integer: 2
Enter a positive integer: -2
Summation of all above numbers is 23
```
---
### 8. Palindrome Number
**AIM: Write a Java program to check palindrome number.**

```java
// assume function is called as question8(44) and question8(14)
public static void question8(int targetnumber){
    int sourceinteger = targetnumber;
    int reversedinteger = 0;
    while (targetnumber > 0){
        reversedinteger = reversedinteger*10 + targetnumber%10;
        targetnumber /= 10;
    }
    if (sourceinteger == reversedinteger){
        System.out.println("Palindrome");
    } else {
        System.out.println("Not palindrome");

    }
}
```
### Output
```
Palindrome
Not palindrome
```
---
## Result
Hence the given programs were executed sucessfully
