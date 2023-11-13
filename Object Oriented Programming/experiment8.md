<p>Experiment 8<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Abstract Class</h1>

## Brief on Abstract Classes

Abstract classes are a key aspect of object-oriented programming in Java. They are classes that cannot be instantiated, meaning you cannot create an object of an abstract class. Instead, they are designed to be subclassed by other classes. Abstract classes are used to represent general concepts, which can be specialized by their subclasses.

For example, consider a program that simulates a zoo. We might have an abstract class `Animal`, which represents any kind of animal. This class could define a method `makeSound()`, but it doesn't know how to implement this method because different animals make different sounds. So, it declares the method as abstract, meaning it doesn't provide any implementation for it. The `Animal` class might also have non-abstract methods, like `eat()` and `sleep()`, which have implementations that are common to all animals.

Now, we can create subclasses like `Lion` and `Elephant` that extend the `Animal` class. These subclasses provide their own implementation for the `makeSound()` method. For instance, the `Lion` class might implement it to print "Roar!" and the `Elephant` class might implement it to print "Trumpet!".

The power of abstract classes is that they allow us to write code that is agnostic to the specific subclasses of the abstract class. For example, we could write a method `performTrick(Animal a)` that makes any animal make a sound, like this:

```java
void performTrick(Animal a) {
    a.makeSound();
}
```

This method works with any subclass of `Animal`, because it only calls methods that are guaranteed to be there by the `Animal` class. This is a key aspect of polymorphism, one of the four fundamental principles of object-oriented programming.

In conclusion, abstract classes are a powerful tool in Java for representing general concepts and enabling polymorphic behavior. They are a cornerstone of good object-oriented design and are used extensively in many Java programs.

## 1. Accounts Abstract Class
**AIM**: Create an Abstract class Accounts with the following details
- Data members:
    - Balance
    - Account number
    - Account holders name
    - Address
- Methods:
    - `withdrawal()` – abstract
    - `deposit()` – abstract
    - `display()` – to show the balance of the account number
Create a subclass of this class SavingsAccount and add the following details
- Data members:
    - Interest Rate
- Methods:
    - `calculateAmount()`

### Abstract Class
```java
abstract class Accounts {
    double Balance;
    int AccountNumber;
    String AccountHoldersName;
    String Address;

    abstract void withdrawal();
    abstract void deposit();

    void display() {
        System.out.println("Balance of account number " + AccountNumber + " is: " + Balance);
    }
}
```

### Subclass
```java
class SavingsAccount extends Accounts {
    double rateOfInterest;

    void calculateAmount() {
        double amount = Balance + (Balance * rateOfInterest / 100);
        System.out.println("The total amount in the account after adding interest is: " + amount);
    }

    void withdrawal() {
        Scanner scanningobject = new Scanner(System.in);
        
        System.out.println("Enter amount for withdrawal (your current balance is "+Balance+" INR):");
        double towithdraw = scanningobject.nextDouble();

        if (towithdraw <= Balance){
            Balance -= towithdraw;
            System.out.println("Sucessfully withdrew " + towithdraw + " INR.\nYour current balance is " +Balance+"INR.");
        } else {
            System.out.println("Insufficient Funds.\nYour current balance is:"+Balance+" INR");
        }

        scanningobject.close();
    }

    void deposit() {
        double todeposit;

        System.out.println("Enter amount for deposit (your current balance is "+Balance+" INR):");
        Scanner depositscanningobject = new Scanner(System.in);
        todeposit = depositscanningobject.nextDouble();

        Balance += todeposit;

        System.out.println("Sucessfully deposited an amount of " + todeposit + ". \nYour current balance is " + Balance + " INR.");

        depositscanningobject.close();

    }
}
```

### Driver Class
```java
public class expt8 {

    public static void main(String[] args) {
        SavingsAccount myAccount = new SavingsAccount();
        myAccount.rateOfInterest = 3.5;

        myAccount.deposit();
        myAccount.display();

        myAccount.calculateAmount();

        myAccount.withdrawal();
        myAccount.display();
    }

}
```

### Output
```
Enter amount for deposit (your current balance is 0.0 INR):
100.2
Sucessfully deposited an amount of 100.2. 
The total amount in the account after adding interest is: 103.70700000000001
Enter amount for withdrawal (your current balance is 100.2 INR): 
50.1
Sucessfully withdrew 40.1 INR.
Your current balance is 60.1 INR.
```

## 2. Library Management Abstract Class
**AIM: Create an Abstract class named Library Management that has functions for getting the**
**book name and display the names of the books. There are two derived classes, Issue and**
**Return. These classes have decrement and increment functions. The user can take or**
**return books. Update the system accordingly. Include provision for searching for a book.**

### Abstract Class
```java
abstract class LibraryManagement {
    String bookName;
    List<String> bookNames = new ArrayList<>();

    void getBookName() {
        this.bookName = "Sample Book";
    }

    void displayBookNames() {
        for(String book : bookNames) {
            java.lang.System.out.println(book);
        }
    }
}
```

### Issue and Return subclass
```java
class Issue extends LibraryManagement {
    int count = 10;

    void decrement() {
        count--;
    }

    void getBookName() {
        super.getBookName();
    }

    void displayBookNames() {
        super.displayBookNames();
    }
}

class Return extends LibraryManagement {
    int count = 0;

    void increment() {
        count++;
    }

    void getBookName() {
        super.getBookName();
    }

    void displayBookNames() {
        super.displayBookNames();
    }
}
```

### Other necessary classes
```java
class User {
    Issue issue = new Issue();
    Return returnBook = new Return();

    void takeBook() {
        issue.decrement();
    }

    void returnBook() {
        returnBook.increment();
    }
}

class LibrarySystem {
    User user = new User();

    void searchBook(String bookName) {
        user.issue.getBookName();
        if(user.issue.bookName.equals(bookName)) {
            java.lang.System.out.println("Book Found");
        } else {
            java.lang.System.out.println("Book Not Found");
        }
    }
}
```

### Driver Code
```java
Issue issue = new Issue();
issue.getBookName();
issue.decrement();
java.lang.System.out.println("Book issued: " + issue.bookName);
java.lang.System.out.println("Remaining books: " + issue.count);

Return returnBook = new Return();
returnBook.getBookName();
returnBook.increment();
java.lang.System.out.println("Book returned: " + returnBook.bookName);
java.lang.System.out.println("Total books: " + returnBook.count);
```

### Output
```
Book issued: Sample Book
Remaining books: 9
Book returned: Sample Book
Total books: 1
```