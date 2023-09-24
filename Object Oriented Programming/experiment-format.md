<p>Experiment 3<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date: 07.09.2023</p>

<h1 align="center">Basic Java Programs</h1>

### 1. Find greatest of two numbers
**Aim: Write a Java program to find the greatest of given two number**

```java
// assume function is called as question1(2,3) and question2(3,1)
public static void question1(int number1, int number2){
        if (number1 > number2){
            System.out.println("number1 > number2");
        } else {
            System.out.println("number1 < number 2");
        }
    }
```
### Output
```
    number1 > number2
    number1 < number2
```
---
### 2. Prepare Grade sheet for a student

**AIM: Write a java program to create a Grade Sheet system for one student**

```java
// assume function is called as question2(83) and question2(92)
public static void question2(int mark){
        if (mark > 90){
            System.out.println("GRADE A");
        } else if (mark > 80){
            System.out.println("GRADE B");
        } else if (mark > 70){
            System.out.println("GRADE C");
        } else if (mark > 60){
            System.out.println("GRADE D");
        } else{
            System.out.println("GRADE F");
        }
    
    }
```
### Output
```
    GRADE B
    GRADE A
```
---
### 3.Check whether the given number is positive, negative or zero
**AIM: Write a Java program to compare a given number for a positive / negative / zero magnitude**

```java
// assume function is called as question3(-1) and question3(0)
public static void question3(int number){
    if (number < 0){
        System.out.println("NEGATIVE");
    } else if (number == 0){
        System.out.println("ZERO");
    } else {
        System.out.println("POSITIVE");
    }
}
```
### Output
```
    NEGATIVE
    ZERO
```
---
### 4. Take the length (L) and breadth (B) of the rectangle as input and find its area
**AIM: Write a Java program to calculate length of a rectangle, with given dimensions, Length and Breadth**

```java
// assume function is called as question4(4,2)
public static int question4(int length, int breadth){
    int area = length * breadth;
    System.out.println(area);
    
    return area;
}
```
### Output
```
    8
```
---
### 5. You have been given a number 'N'. Your task is to find the sum of all even numbers from 1 to N
**AIM: Write a Java program to find sum of all number from 1 to some given number, N**

```java
// assume function is called as question5(10)
public static void question5(int number){
    int sum = 0;
    for (int iterator = 0; iterator <= number; iterator++){
        sum += iterator;
    }
    System.out.println(sum);
    }
```
### Output
```
    55
```
---
### 6. For the given integer just print the sum of all even digits and odd digits separately.
**AIM: Write a Java program to calculate sum of all even number and odd numbers seperately, from 1 to some given number N**

```java
// assume function is called as question6(5123)
public static void question6(int number){
    int sumofodd = 0;
    int sumofeven = 0;

    while (number > 0){
        int remainder = number % 10;
        if (remainder % 2 == 0){
            sumofeven += remainder;
        } else {
            sumofodd += remainder;
        }
        number = number / 10;
    }
    System.out.println("Sum of even digits: " + sumofeven);
    System.out.println("Sum of odd digits: " + sumofodd);
}
```
### Output
```
    Sum of even digits: 4
    Sum of odd digits: 7
```
---
### 7. Write java program to print the pattern. [Nested for loop ]
**AIM: Write a Java program to print a left indented triangle with asterisks (*)**

```java
// assume function is called as question6(4)
public static void question6(int limit){
    // print a pattern of stars 
    for (int i = 0; i < limit; i++){
        for (int j = 0; j < i; j++){
            System.out.print("*");
        }
        System.out.println();
    }
}
```
### Output
```
    *
    **
    ***
    ****
```
---
## Result
Hence the given programs were executed sucessfully
