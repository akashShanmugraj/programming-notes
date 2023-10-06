<p>Experiment 6<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Classes and Objects</h1>


### 1. Employee Class
**AIM: Create a class Employee with the following details.**
**The data members are name,address, age, gender and the method display() to show employee details.**

```java
class Employee {
    String name;
    String address;
    int age;
    String gender;

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
    }
}
```

### 2. Customer and Account Class
**AIM: Create classes that capture bank customers and bank accounts.A customer has a first and last name.An account has a customer and balance.Make objects for two accounts held by the same customer.**

```java
class Customer {
    String firstName;
    String lastName;
}

class Account {
    Customer customer;
    double balance;
}
```

### Driver Code

```java
public static void main(String[] args) {
    Customer customer = new Customer();
    customer.firstName = "John";
    customer.lastName = "Doe";

    Account account1 = new Account();
    account1.customer = customer;
    account1.balance = 1000.0;

    Account account2 = new Account();
    account2.customer = customer;
    account2.balance = 2000.0;

    Employee employee = new Employee();
    employee.name = "Jane";
    employee.address = "123 Main St";
    employee.age = 30;
    employee.gender = "Female";
    
    employee.display();
}
```

### Output
```
Name: Jane
Address: 123 Main St
Age: 30
Gender: Female
```