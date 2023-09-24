import java.util.Scanner;

public class experiment4 {

    public static void question1(int targetnumber){
        for (int iterable = 0; iterable < 10; iterable++) {
            System.out.println("x: "+iterable);
            System.out.println("y: "+targetnumber);
            System.out.println("");
            targetnumber -= 2;
        }
    }

    public static void question2(double radius){
        System.out.println("Area of circle: "+(Math.PI*Math.pow(radius, 2)));
    }

    public static void question3(int targetnumber){
        long factorialnumber = 1;
        for (int iterable = 1; iterable <= targetnumber; iterable++) {
            factorialnumber *= iterable;
        }
        System.out.println("Factorial of "+targetnumber+" is "+factorialnumber);
    }

    public static void question4(int targetyear){
        if (targetyear%4==0 && targetyear%100!=0 || targetyear%400==0){
            System.out.println("Leap year");
        } else {
            System.out.println("Not leap year");
        }
    }

    public static void question5(int targetnumber){
        if (targetnumber%2==0){
            System.out.println("Even number");
        } else {
            System.out.println("Odd number");
        }
    }


    public static void question6(){
        // make use of break statement in a while loop to calculate the sum of all positive numbers
        int tempnumber = 0;
        int summation;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int targetnumber = scanner.nextInt();
        while (targetnumber > 0){
            tempnumber += targetnumber;
            System.out.print("Enter an integer: ");
            targetnumber = scanner.nextInt();
        }

        System.out.println("Summation of all above numbers is "+tempnumber);
    }

    public static void question7(){
        int sourceinteger = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        int targetnumber = scanner.nextInt();
        while (targetnumber > 0){
            sourceinteger += targetnumber;
            System.out.print("Enter a positive integer: ");
            targetnumber = scanner.nextInt();
        }
        System.out.println("Summation of all above numbers is "+sourceinteger);
    }

    public static void question8(int targetnumber){
    // check if targetnumber is a palindrome integer
        int sourceinteger = targetnumber;
        int reversedinteger = 0;
        while (targetnumber > 0){
            reversedinteger = reversedinteger*10 + targetnumber%10;
            targetnumber /= 10;
        }
        if (sourceinteger == reversedinteger){
            System.out.println("Palindrome");
        } else {
            System.out.println("Not palindrome");
        }
    }
    public static void main(String[] args) {
        // question4(2004);
        question7();
    }
}
