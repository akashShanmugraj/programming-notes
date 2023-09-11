<p>Experiment 5<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date: 08.09.2023</p>

<h1 align="center">Java Programs - III</h1>

### 1. Sum of all elements in the array
**Aim: Write a Java program that computes sum of all elements in the array**

```java
public static void question1() {
    int[] array = { 1, 2, 3, 4, 5 };
    int sum = 0;
    
    for (int iterator = 0; iterator < array.length; iterator++) {
        sum += array[iterator];
    }
    
    System.out.println(sum);
}
```
### Output
```
15
```
---
### 2. Sum of Maximum and Minimum elements

**AIM: Write a java program to display the sum of maximum and minimum values in the given array**

```java
public static void question2() {
    
    int[] array = { 1, 2, 3, 4, 5 };
    int maxofarray;
    int minofarray;

    maxofarray = array[0];
    minofarray = array[0];
    
    for (int iterator = 0; iterator < array.length; iterator++) {
        if (array[iterator] > maxofarray) {
            maxofarray = array[iterator];
        }
        if (array[iterator] < minofarray) {
            minofarray = array[iterator];
        }
    }

    System.out.println(maxofarray + minofarray);
}

```
### Output
```
6
```
---
### 3. Find missing element
**AIM: Write a Java program to find the missing element in the range from 1 to N+1 without sorting the array**

```java
// assume function is called as question3(new int[] { 1, 2, 4, 5 }, 5);
public static void question3(int[] numberarray, int number) {
    
    int generalsummation = 0, sumofarray = 0;
    
    for (int iterator = 1; iterator <= number; iterator++) {
        generalsummation += iterator;
    }
    
    for (int iterator = 0; iterator < numberarray.length; iterator++) {
        sumofarray += numberarray[iterator];
    }
    
    System.out.println(generalsummation - sumofarray);
}

```
### Output
```
3 
```
---
### 4. Element with highest frequency
**AIM: Write a Java program to find the element which has highest frequency (maximum repetiton)**

```java
public static void question4() {
    int[] array;
    Scanner scanner = new Scanner(System.in);
    
    System.out.print("Enter the number of elements in the array: ");
    int numberofelements = scanner.nextInt();
    array = new int[numberofelements];
    System.out.println("Enter the elements of the array (line-by-line): ");
    
    for (int iterator = 0; iterator < numberofelements; iterator++) {
        array[iterator] = scanner.nextInt();
    }
    
    int maxoccurringelement = array[0];
    int maxoccurringelementcount = 0;
    
    for (int iterator = 0; iterator < numberofelements; iterator++) {
        int count = 0;
        for (int iterator2 = 0; iterator2 < numberofelements; iterator2++) {
            if (array[iterator] == array[iterator2]) {
                count++;
            }
        }
        if (count > maxoccurringelementcount) {
            maxoccurringelementcount = count;
            maxoccurringelement = array[iterator];
        }
    }
    
    System.out.println("The maximum occurring element is " + maxoccurringelement + " and it occurs "
            + maxoccurringelementcount + " times.");
}

```
### Output
```
Enter the number of elements in the array: 4
Enter the elements of the array (line-by-line): 
1
2
2
3
The maximum occurring element is 2 and it occurs 2 times.
```
---
### 5. Element Insertion
**AIM: Write a Java program to insert an element in the array**

```java
// assume function is called as question5(new int[] { 1, 2, 3, 4, 5 }, 6, 2)
public static void question5(int[] array, int element, int position) {
    
    int[] newarray = new int[array.length + 1];
    
    for (int iterator = 0; iterator < position; iterator++) {
        newarray[iterator] = array[iterator];
    }
    
    newarray[position] = element;
    
    for (int iterator = position + 1; iterator < newarray.length; iterator++) {
        newarray[iterator] = array[iterator - 1];
    }
    
    for (int iterator = 0; iterator < newarray.length; iterator++) {
        System.out.print(newarray[iterator]);
        System.out.print(" ");
    }
    
    System.out.println();
}

```
### Output
```
1 2 6 3 4 5
```
---
### 6. Sum of two Matrices
**AIM: Write a Java program to calculate sum of two given matrices**

```java
// assume function is called as question6(new int[][] { { 1, 2, 3 }, { 4, 5, 6 } }, new int[][] { { 1, 2, 3 }, { 4, 5, 6 } });
public static void question6(int[][] matrix1, int[][] matrix2) {

    int[][] matrix3 = new int[matrix1.length][matrix1[0].length];

    for (int iterator = 0; iterator < matrix1.length; iterator++) {
        for (int iterator2 = 0; iterator2 < matrix1[0].length; iterator2++) {
            matrix3[iterator][iterator2] = matrix1[iterator][iterator2] + matrix2[iterator][iterator2];
        }
    }

    for (int iterator = 0; iterator < matrix3.length; iterator++) {
        for (int iterator2 = 0; iterator2 < matrix3[0].length; iterator2++) {
            System.out.print(matrix3[iterator][iterator2]);
            System.out.print(" ");
        }
        System.out.println();
    }
}
```
### Output
```
2 4 6
8 10 12
```
---
## Result
Hence the given programs were executed sucessfully
