public class experiment7a {

    // Method overloading by changing the number of arguments
    public int sum(int a, int b) {
        System.out.println("Method with 2 integer parameters");
        return a + b;
    }

    public int sum(int a, int b, int c) {
        System.out.println("Method with 3 integer parameters");
        return a + b + c;
    }

    public int sum(int a, int b, int c, int d) {
        System.out.println("Method with 4 integer parameters");
        return a + b + c + d;
    }

    // Method overloading by changing data type of parameters
    public int sub(int a, int b) {
        System.out.println("Method with 2 integer parameters");
        return a - b;
    }

    public double sub(double a, double b) {
        System.out.println("Method with 2 double parameters");
        return a - b;
    }

    public float sub(float a, float b) {
        System.out.println("Method with 2 float parameters");
        return a - b;
    }

    // Method overloading by changing sequence of data type of parameters
    public int multiply(int a, double b) {
        System.out.println("Method with first integer and second double parameters");
        return a * (int)b;
    }

    public int multiply(double a, int b) {
        System.out.println("Method with first double and second integer parameters");
        return (int)a * b;
    }

    public double multiply(double a, double b) {
        System.out.println("Method with two double parameters");
        return a * b;
    }

    public static void main(String[] args) {
        experiment7a obj = new experiment7a();
        System.out.println(obj.sum(1, 2));
        System.out.println(obj.sum(1, 2, 3));
        System.out.println(obj.sum(1, 2, 3, 4));

        System.out.println(obj.sub(1, 2));
        System.out.println(obj.sub(1.0, 2.0));
        System.out.println(obj.sub(1.0f, 2.0f));

        System.out.println(obj.multiply(1, 2.0));
        System.out.println(obj.multiply(1.0, 2));
        System.out.println(obj.multiply(1.0, 2.0));
    }
}
