<p>Experiment 9A<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Interfaces</h1>

## 1. Illustration of uses of `interface` with two classes
**Aim:** Illustrate the use of interface technique
Teacher and Student are two classes each of them having their own unique components. You want to
define an interface, say, Resume which will include all the components both in Teacher and Student.

### `Profile` Interface
```java
interface Profile {

    void department();

    void jobtitle();

    void university();

    void qualification();

    void displayall();
}
```

### Implementation 1 - `Teacher` class
```java
class Teacher implements Profile {
    String qualification = "Post Graduation in Theoratical Computer Science";
    int experienceInYears = 16;

    public void department() {
        System.out.println("Computer Science and Engineering");
    }

    public void jobtitle() {
        System.out.println("Assistant Professor, Senior Grade");
    }

    public void university() {
        System.out.println("PSG College of Technology");
    }

    public void qualification() {
        System.out.println("Qualification: " + qualification + ", Experience: " + experienceInYears + " years");
    }

    public void displayall() {
        department();
        jobtitle();
        university();
        qualification();

    }

    public static void main(String[] args) {
        Teacher newteacher = new Teacher();
        newteacher.displayall();
    }
}
```

### Implementation 2 - `Student` class

```java
class Student implements Profile {
    String qualification = "High School Diploma";

    public void department() {
        System.out.println("Computer Science and Engineering");
    }

    public void jobtitle() {
        System.out.println("Sophomore");
    }

    public void university() {
        System.out.println("PSG College of Technology");
    }

    public void qualification() {
        System.out.println("Qualification: " + qualification);
    }

    public void displayall() {
        department();
        jobtitle();
        university();
        qualification();

    }

    public static void main(String[] args) {
        Student newstudent = new Student();
        newstudent.displayall();
    }
}
```

### Driver Code
```java
    public static void main(String[] args) {

        Student newstudent = new Student();
        Teacher newteacher = new Teacher();

        newstudent.displayall();
        newteacher.displayall();

    }
```

### Output
```
Computer Science and Engineering
Sophomore
PSG College of Technology
Qualification: High School Diploma

Computer Science and Engineering
Assistant Professor, Senior Grade
PSG College of Technology
Qualification: Post Graduation in Theoratical Computer Science, Experience: 16 years
```

## 2. Differentiating Interface and Classes
**AIM**: Interface, in many way, similar to a class; however, no object can be instantiated from an interface.
Demonstrate it.

### `Cars` Interface
```java
interface Cars {
    double ManufacturerInformation();
}
```

### Class Implementation
```java
class Volkswagen implements Cars {
    private double groundclearance;

    public Volkswagen(double groundclearance) {
        this.groundclearance = groundclearance;
    }

    @Override
    public String ManufacturerInformation() {
        return "Germany";
    }
}

class BritishMotorWorks implements Cars {
    private double groundclearance;

    public BritishMotorWorks(double groundclearance) {
        this.groundclearance = groundclearance;
    }

    @Override
    public String ManufacturerInformation() {
        return "England";
    }
}
```

### Output
```
Germany
England
```

## 3. Inheritance in Interfaces
**AIM**: Like classes, interfaces also have a chain of inheritance i.e. an interface can be derived from other interface.
Implement single inheritance with interface .

### Primary Interfaces
```java
interface Human {
    void walk();
}

interface Woman extends Human {
    void takecare();
}
```

### Inheritance
```java
class Person implements Human {
    @Override
    public void walk() {
        System.out.println("Person Walking");
    }
}

class AnotherPerson implements Woman {
    @Override
    public void walk() {
        System.out.println("Another Person Walking");
    }

    @Override
    public void takecare() {
        System.out.println("Another Person Taking Care");
    }
}
```
### Driver Code
```java
    public static void main(String[] args) {
        Human Person = new Person();
        Woman AnotherPerson = new AnotherPerson();

        Person.walk();
        AnotherPerson.walk();
        AnotherPerson.takecare();
    }
```

### Output
```
Person Walking
Another Person Walking
Another Person Taking Care
```


## 4. Multiple Inheritance
**Aim:** An interface is a significant feature in Java in the sense that it enables the multiple inheritance.
Implement the same
Illustrate class A which implements two interfaces (I1 and I2)

### Interfaces
```java
interface interface1 {
    void attributeMethod1();
}

interface interface2 {
    void attributeMethod2();
}
```

### Inheritance
```java
class A implements interface1, interface2 {
    @Override
    public void attributeMethod1() {
        System.out.println("Method 1 implementation in class A");
    }

    @Override
    public void attributeMethod2() {
        System.out.println("Method 2 implementation in class A");
    }

    public void classAMethod() {
        System.out.println("Additional method in class A");
    }
}
```

### Output
```
Method 1 implementation in class A
Method 2 implementation in class A
Additional method in class A
```

## 5. Implementation using two interfaces
**Aim:** Use two interfaces and implement the drive() method in Hybrid_Car class.

### Primary Interfaces
```java
interface ElectricCar {
    void drive();
}

interface FuelCar {
    void drive();
}
```

### Inheritance
```java
class Hybrid_Car implements ElectricCar, FuelCar {
    @Override
    public void drive() {
        System.out.println("Hybrid car can commute using a combination of Fuel and Electric Power.");
    }
}
```

### Output
```
Hybrid car can commute using a combination of Fuel and Electric Power.
```

## 6. Stack Implementation
**Aim:** Design an interface named Stack with the following methods
a. Push and Pop elements from the stack
b. Check whether the stack is empty or not. Implement the stack with the help of arrays and if
the size of the array becomes too small to hold the elements, create a new one. Test this interface by
inheriting it in its subclass StackTest.java.

### Primary Interface
```java
interface StackObject {
    void PushOperation(int element);
    int PopOperation();
    boolean isEmpty();
}
```

### Stack Implementation
```java
class ArrayStackObject implements StackObject {
    static final int INITIAL_CAPACITY = 10;
    int[] elements;
    int size;

    public ArrayStackObject() {
        elements = new int[INITIAL_CAPACITY];
        size = 0;
    }

    public void PushOperation(int element) {
        if (size == elements.length) {
            int[] newElements = new int[2 * elements.length];
            System.arraycopy(elements, 0, newElements, 0, elements.length);
            elements = newElements;
        }
        elements[size] = element;
        size++;
    }

    public int PopOperation() {
        if (isEmpty()) {
            throw new IllegalStateException("StackObject is empty.");
        }
        int top = elements[size - 1];
        size--;
        return top;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
```

### Driver Code
```java
    public static void main(String[] args) {
        StackObject StackObject = new ArrayStackObject();

        StackObject.PushOperation(13);
        StackObject.PushOperation(9);
        StackObject.PushOperation(10);

        System.out.println("POP : " + StackObject.PopOperation()); 
        System.out.println("POP : " + StackObject.PopOperation()); 

        System.out.println("ISEMPTY : " + StackObject.isEmpty()); 

        StackObject.PushOperation(17);
        System.out.println("ISEMPTY : " + StackObject.isEmpty()); 

        while (!StackObject.isEmpty()) {
            System.out.println("POP : " + StackObject.PopOperation());
        }

        System.out.println("ISEMPTY : " + StackObject.isEmpty());
    }
```

### Output
```
POP : 10
POP : 9
ISEMPTY : false
ISEMPTY : false
POP : 17
POP : 13
ISEMPTY : true
```