package University.Department;

public class Staff {
    int age;
    String name;
    String position;
    double salary;
    
    public Staff(int age, String name, String position, double salary) {
        this.age = age;
        this.name = name;
        this.position = position;
        this.salary = salary;
    }
    
    // Getters and setters for the variables
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String getName() {
        return name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getPosition() {
        return position;
    }
    
    public void setPosition(String position) {
        this.position = position;
    }
    
    public double getSalary() {
        return salary;
    }
    
    public void setSalary(double salary) {
        this.salary = salary;
    }

}
