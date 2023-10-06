public class experiment6 {
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
}
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

class Customer {
    String firstName;
    String lastName;
}

class Account {
    Customer customer;
    double balance;
}

