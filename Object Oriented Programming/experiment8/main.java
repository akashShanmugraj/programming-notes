import java.util.ArrayList;
import learnjava.OOP;
import Advcalculate.*;
import University.Department.Staff;

public class main {
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

  public static void question2() {
    OOP.learn();
  }

  public static void question3() {
    int resultAddition = Calculator.add(5, 3);
    int resultSubtraction = Calculator.subtract(8, 3);
    int resultMultiplication = Calculator.multiply(4, 2);
    double resultDivision = Calculator.divide(10.0, 2.0);

    System.out.println("Addition: " + resultAddition);
    System.out.println("Subtraction: " + resultSubtraction);
    System.out.println("Multiplication: " + resultMultiplication);
    System.out.println("Division: " + resultDivision);
  }

  public static void question4(){
    Staff staffMember = new Staff(35, "John Smith", "Professor", 75000.0);

    System.out.println("Name: " + staffMember.getName());
    System.out.println("Position: " + staffMember.getPosition());
    System.out.println("Age: " + staffMember.getAge());
    System.out.println("Salary: " + staffMember.getSalary());
  }

  public static void main(String[] args) {
    question1();
    question2();
    question3();
    question4();
  }
}