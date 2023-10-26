<p>Experiment 9<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Packages</h1>

> Note that the working file is `main.java` inside a folder containing all necessary packages

### 1. Importing BuiltIn packages
**AIM: Write a program to show the use of the `ArrayList` class of Java.util package**

```java
public static void question1() {
    ArrayList<String> names = new ArrayList<>();

    names.add("Alice");
    names.add("Bob");
    names.add("Charlie");

    System.out.println("Names: " + names);

    System.out.println("Size: " + names.size());

    String first = names.get(0);
    System.out.println("First name: " + first);

    names.set(1, "Bobby");
    System.out.println("Modified names: " + names);

    names.remove(2);
    System.out.println("Names after removal: " + names);

    names.clear();
    System.out.println("Names after clear: " + names);
  }
```

### Output
```
Names: [Alice, Bob, Charlie]
Size: 3
First name: Alice
Modified names: [Alice, Bobby, Charlie]
Names after removal: [Alice, Bobby]
Names after clear: []
```

### Importing a UserDefined Package
> using `OOP.java` inside folder **learnjava**

```java
package learnjava;

public class OOP {

    public static void abstraction(){
        System.out.println("This is Abstraction.");
    }

    public static void inheritance(){
        System.out.println("This is Inheritance.");
    }

    public static void encapsulation(){
        System.out.println("This is Encapsulation.");
    }

    public static void learn(){
        abstraction();
        inheritance();
        encapsulation();
    }
}
```
In our working file,
```java
import learnjava.OOP;
:
:
    public static void question2(){
        OOP.learn()
    }
:
:
```

### Output
```
This is Abstraction.
This is Inheritance.
This is Encapsulation.
```

### 3. Define a package plus it's class, and call that class
**AIM: Create a class Calculator inside a package name Advcalculate. To create a class inside a package, declare the package name in the first statement in your program. A class can have only one package declaration.
Make use of this package  Advcalculate   in another program and use the class Calculator.**

> using `Calculator.java` inside Advcalculate folder
```java
package Advcalculate;

public class Calculator {
    public static int add(int a, int b) {
        return a + b;
    }

    public static int subtract(int a, int b) {
        return a - b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }

    public static double divide(double a, double b) {
        return a / b;
    }
}
```