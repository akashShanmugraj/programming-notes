<p>Experiment 13<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Generics</h1>


### 1. Reuse Same Class for Two Different Data Types Using Generics

**AIM**: Reuse same class for two different data types and demonstrate that  Generics helps in code reusability with ease.

```java
class Pair<T> {
    private T first;
    private T second;

    public Pair(T first, T second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public T getSecond() {
        return second;
    }

    public void displayPair() {
        System.out.println("Pair: (" + first + ", " + second + ")");
    }
}

public class GenericPairExample {
    public static void main(String[] args) {
        Pair<Integer> integerPair = new Pair<>(5, 10);
        integerPair.displayPair();

        Pair<String> stringPair = new Pair<>("Hello", "World");
        stringPair.displayPair();
    }
}
```

### Output
```
Pair: (5, 10)
Pair: (Hello, World)
```

### 2. Generic Type with More Than One Parameter

**AIM**: Write a java program for Generic Type with more than one parameter

```java
class Tuple<A, B> {
    private A first;
    private B second;

    public Tuple(A first, B second) {
        this.first = first;
        this.second = second;
    }

    public A getFirst() {
        return first;
    }

    public B getSecond() {
        return second;
    }

    public void displayTuple() {
        System.out.println("Tuple: (" + first + ", " + second + ")");
    }
}

public class GenericTupleExample {
    public static void main(String[] args) {
        Tuple<Integer, String> tuple1 = new Tuple<>(5, "Hello");
        tuple1.displayTuple();

        Tuple<Double, Boolean> tuple2 = new Tuple<>(3.14, true);
        tuple2.displayTuple();
    }
}
```

### Output
```
Tuple: (5, Hello)
Tuple: (3.14, true)
```

### 3. Generic Methods with Different Types of Arguments

**AIM**: Write a java program for creating generic methods that can be called with different types of arguments.

```java
public class GenericMethodsExample {
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static <A, B> void displayPair(A first, B second) {
        System.out.println("Pair: (" + first + ", " + second + ")");
    }

    public static void main(String[] args) {
        Integer[] intArray = {1, 2, 3, 4, 5};
        Double[] doubleArray = {1.1, 2.2, 3.3, 4.4, 5.5};
        String[] stringArray = {"One", "Two", "Three", "Four", "Five"};

        printArray(intArray);
        printArray(doubleArray);
        printArray(stringArray);

        displayPair(10, "Java");
        displayPair(3.14, true);
    }
}
```

### Output
```
1 2 3 4 5 
1.1 2.2 3.3 4.4 5.5 
One Two Three Four Five 
Pair: (10, Java)
Pair: (3.14, true)
```
