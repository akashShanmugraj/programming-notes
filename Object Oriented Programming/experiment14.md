<p>Experiment 14<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Lambda Expression</h1>

## 1. Lambda Expression to Find the Sum of Two Integers

**AIM**: Write a Java program to implement a lambda expression to find the sum of two
integers. 

```java
interface SumCalculator {
    int calculateSum(int a, int b);
}

public class SumOfIntegers {
    public static void main(String[] args) {
        SumCalculator sumCalculator = (a, b) -> a + b;
        
        int result = sumCalculator.calculateSum(5, 7);
        System.out.println("Sum of two integers: " + result);
    }
}
```

### Output
```
Sum of two integers: 12
```

## 2. Lambda Expression to Sort a List of Strings in Alphabetical Order

**AIM**: Write a Java program to implement a lambda expression to sort a list of strings in
alphabetical order.

```java
import java.util.Arrays;
import java.util.List;

public class StringSorter {
    public static void main(String[] args) {
        List<String> stringList = Arrays.asList("Banana", "Apple", "Orange", "Grapes");

        stringList.sort((s1, s2) -> s1.compareTo(s2));

        System.out.println("Sorted List of Strings: " + stringList);
    }
}
```

### Output

```
Sorted List of Strings: [Apple, Banana, Grapes, Orange]
```

## 3. Lambda Expression to Concatenate Two Strings

**AIM**: Write a Java program to implement a lambda expression to concatenate two strings.

```java
interface StringConcatenator {
    String concatenateStrings(String s1, String s2);
}

public class StringConcatenation {
    public static void main(String[] args) {
        StringConcatenator concatenator = (s1, s2) -> s1 + s2;
        
        String result = concatenator.concatenateStrings("Hello, ", "World!");
        System.out.println("Concatenated String: " + result);
    }
}
```

### Output

```
Concatenated String: Hello, World!
```

## 4. Lambda Expression to Find Maximum and Minimum Values in a List of Integers

**AIM**: Write a Java program to implement a lambda expression to find the maximum and
minimum values in a list of integers.

```java
import java.util.Arrays;
import java.util.List;

public class MinMaxFinder {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(3, 1, 8, 4, 6, 2, 7, 5);

        int max = numbers.stream().max(Integer::compare).orElse(0);
        int min = numbers.stream().min(Integer::compare).orElse(0);

        System.out.println("Maximum Value: " + max);
        System.out.println("Minimum Value: " + min);
    }
}
```

### Output

```
Maximum Value: 8
Minimum Value: 1
```

## 5. Lambda Expression to Calculate the Sum of Squares of Odd and Even Numbers in a List

**AIM**: Write a Java program to implement a lambda expression to calculate the sum of
squares of all odd and even numbers in a list.

```java
import java.util.Arrays;
import java.util.List;

public class SumOfSquares {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        int sumOfSquaresOdd = numbers.stream()
                .filter(n -> n % 2 != 0)
                .mapToInt(n -> n * n)
                .sum();

        int sumOfSquaresEven = numbers.stream()
                .filter(n -> n % 2 == 0)
                .mapToInt(n -> n * n)
                .sum();

        System.out.println("Sum of Squares of Odd Numbers: " + sumOfSquaresOdd);
        System.out.println("Sum of Squares of Even Numbers: " + sumOfSquaresEven);
    }
}
```

### Output

```
Sum of Squares of Odd Numbers: 165
Sum of Squares of Even Numbers: 220
```