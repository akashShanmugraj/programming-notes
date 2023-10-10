// Abstract class
abstract class Shape {
    // Abstract method (does not have a body)
    public abstract double area();
}

// Subclass (inherits from Shape)
class Rectangle extends Shape {
    private double length;
    private double width;
    
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Implementation of the abstract method
    public double area() {
        return length * width;
    }
}

// Subclass (inherits from Shape)
class Circle extends Shape {
    private double radius;
    
    public Circle(double radius) {
        this.radius = radius;
    }

    // Implementation of the abstract method
    public double area() {
        return Math.PI * radius * radius;
    }
}

// Test program
public class main {
    public static void main(String[] args) {
        Shape myShape = new Rectangle(5, 3); // Create a Rectangle object
        System.out.println("Area of rectangle: " + myShape.area());

        myShape = new Circle(2); // Create a Circle object
        System.out.println("Area of circle: " + myShape.area());
    }
}