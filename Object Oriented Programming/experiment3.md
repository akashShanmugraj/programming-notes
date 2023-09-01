# Experiment 3
## Object Oriented Programming Laboratory
Submitted by Akash Shanmugaraj, 22z255, PSGCT

**1. Find greatest of Two numbers**
```java
public static void question1(int number1, int number2){
        if (number1 > number2){
            System.out.println("number1 > number2");
        } else {
            System.out.println("number1 < number 2");
        }
    }
```

**2. Prepare Grade sheet for a student**

```java
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

**3.Check whether the given number is positive, negative or zero**

```java
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
**4. Take the length (L) and breadth (B) of the rectangle as input and find its area**
```java
    public static int question4(int length, int breadth){
        int area = length * breadth;
        System.out.println(area);
        
        return area;
    }
```
**5. You have been given a number 'N'. Your task is to find the sum of all even numbers from 1 to N**

```java
public static void question5(int number){
        int sum = 0;
        for (int iterator = 0; iterator <= number; iterator++){
            sum += iterator;
        }
        System.out.println(sum);
    }
```
**6. For the given integer just print the sum of all even digits and odd digits separately.**
```java
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

**7. Write java program to print the pattern. [Nested for loop ]**

```java
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