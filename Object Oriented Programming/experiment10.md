<p>Experiment 10<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Exception Handling</h1>

## Reciprocal Program
**AIM:** Consider a program that reads an integer from the user and prints its reciprocal. If the
user enters zero, the program will throw an exception. Write the code to handle this
exception using a try-catch block

```java
public void reciprocal() {
    Scanner scannerobject = new Scanner(System.in);
    System.out.print("Number: ");
    
    try {
        int targetnumber = scannerobject.nextInt();
        if (targetnumber == 0) {
            throw new ArithmeticException("ARERR: ZeroDivision");
        }
        double reciprocal = 1.0 / targetnumber;
        System.out.println("Reciprocal: " + reciprocal);
    } catch (ArithmeticException e) {
        System.out.println("Error: " + e.getMessage());
    }
}
```
### Output 
```
Enter an integer: 0
Error: Cannot divide by zero
```

## Exception Handling in Static Methods
**AIM:** Define a class that has static methods `main()`, `p()`, `q()`, `r()` and `s()`. 

- The `main()` method calls `p()`. 
- Method `p()` calls `q()`. 
- Method `q()` calls `r()`. 
- Method `r()` calls `s()`.
- Method `s()` declares a local array with six integer type elements and then attempts to access the element at position 10. 

Therefore, an exception of type
`ArrayIndexOutOfBoundsException` is generated. 

Each method has a catch block for this
type of exception. The catch blocks in `q()`, `r()` and `s()` contain a throw statement to
generate this type of exception. 

Indicate the flow of control during the execution by
displaying the suitable output messages.

Also include a finally block with print
statements.

### `p()` function
```java
public static void p() {
    try {
        q();
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("ERR: ArrayIndexOutOfBoundsException @ p()");
        throw e;
    } finally {
        System.out.println("FINBLK @ p()");
    }
}
```

### `q()` function
```java
public static void q() {
    try {
        r();
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("ERR: ArrayIndexOutOfBoundsException @ q()");
        throw e;
    } finally {
        System.out.println("FINBLK @ q()");
    }
}
```

### `r()` function
```java
public static void r() {
    try {
        s();
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("ERR: ArrayIndexOutOfBoundsException @ r()");
        throw e;
    } finally {
        System.out.println("FINBLK @ r()");
    }
}
```

### `s()` function
```java
public static void s() {
    try {
        int[] arr = new int[6];
        int value = arr[10];
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("ERR: ArrayIndexOutOfBoundsException @ s()");
        throw e;
    } finally {
        System.out.println("FINBLK @ s()");
    }
}
```

### `main()` function
```java
public static void main(String[] args) {
    try {
        p();
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("ERR: ArrayIndexOutOfBoundsException @ main()");
    } finally {
        System.out.println("FINBLK @ main()");
    }
}
```

### Output
```
Caught ArrayIndexOutOfBoundsException in s()
Finally block in s()
Caught ArrayIndexOutOfBoundsException in r()
Finally block in r()
Caught ArrayIndexOutOfBoundsException in q()
Finally block in q()
Caught ArrayIndexOutOfBoundsException in p()
Finally block in p()
Caught ArrayIndexOutOfBoundsException in main()
Finally block in main()
```

## Student Class with Custom Exceptions
**AIM:** Create a class Student with the data members _Name_, _Register Number_, _Mark1_, _Mark2_,
_Mark3_, _Total_ and _Average_. Using necessary member functions get the input, calculate Total and Average and display the student information’s. 

If the register number exceeds 6 digits then raise one user defined exception called `InvalidRegNoException`. 
Similarly if marks value is greater than 100 throw an exception called `MarkOutOfBoundsException`

### Exception Definitions
```java
class InvalidRegNoException extends Exception {
    public InvalidRegNoException(String message) {
        super(message);
    }
}

class MarkOutOfBoundsException extends Exception {
    public MarkOutOfBoundsException(String message) {
        super(message);
    }
}
```

### Student Class
```java
class Student {
    private String Name;
    private int RegisterNumber;
    private int Mark1;
    private int Mark2;
    private int Mark3;

    public void getInput(String name, int regNo, int mark1, int mark2, int mark3) throws InvalidRegNoException, MarkOutOfBoundsException {
        if (regNo > 999999) {
            throw new InvalidRegNoException("Invalid Register Number. Should be 6 digits or less.");
        }
        if (mark1 > 100 || mark2 > 100 || mark3 > 100) {
            throw new MarkOutOfBoundsException("Marks should be in the range of 0 to 100.");
        }
        this.Name = name;
        this.RegisterNumber = regNo;
        this.Mark1 = mark1;
        this.Mark2 = mark2;
        this.Mark3 = mark3;
    }

    public void calculateTotalAndAverage() {
        int total = Mark1 + Mark2 + Mark3;
        double average = total / 3.0;
        System.out.println("Total Marks: " + total);
        System.out.println("Average Marks: " + average);
    }

    public void displayStudentInfo() {
        System.out.println("Name: " + Name);
        System.out.println("Register Number: " + RegisterNumber);
        System.out.println("Mark 1: " + Mark1);
        System.out.println("Mark 2: " + Mark2);
        System.out.println("Mark 3: " + Mark3);
    }
}
```


### Driver Code
```java
public static void main(String[] args) {
    Student student = new Student();
    try {
        student.getInput("John Doe", 123456, 85, 90, 78);
        student.calculateTotalAndAverage();
        student.displayStudentInfo();
    } catch (InvalidRegNoException e) {
        System.out.println("Error: " + e.getMessage());
    } catch (MarkOutOfBoundsException e) {
        System.out.println("Error: " + e.getMessage());
    }
}
```

### Output
```
Total Marks: 253
Average Marks: 84.33333333333333
Name: John Doe
Register Number: 123456
Mark 1: 85
Mark 2: 90
Mark 3: 78
```