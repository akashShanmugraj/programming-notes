import java.util.Scanner;
public class experiment3 {
    public static int intro(){
        for (int i=0;i<100;i++){
            if (i % 3 == 0 && i % 5 == 0){
                System.out.println("FizzBuzz");
            } else if (i % 3 == 0){
                System.out.println("Fizz");
            } else if (i % 5 == 0) {
                System.out.println("Buzz");
            } else {
                System.out.println(i);
            }
        }
        System.out.println("Hello");

        return 0;
    }
    public static void question1(int number1, int number2){
        if (number1 > number2){
            System.out.println("number1 > number2");
        } else {
            System.out.println("number1 < number 2");
        }
    }

    public static void question2(int mark){
        if (mark > 90){
            System.out.println("GRADE A");
        } else if (mark > 80){
            System.out.println("GRADE B");
        } else if (mark > 70){
            System.out.println("GRADE C");
        } else if (mark > 60){
            System.out.println("GRADE D");
        } else{
            System.out.println("GRADE F");
        }
    
    }

    public static void question3(int number){
        if (number < 0){
            System.out.println("NEGATIVE");
        } else if (number == 0){
            System.out.println("ZERO");
        } else {
            System.out.println("POSITIVE");
        }
    }

    public static int question4(int length, int breadth){
        int area = length * breadth;
        System.out.println(area);
        
        return area;
    }

    public static void question5(int number){
        int sum = 0;
        for (int iterator = 0; iterator <= number; iterator++){
            sum += iterator;
        }
        System.out.println(sum);
    }

    public static void question6(int number){
        int sumofodd = 0;
        int sumofeven = 0;

        while (number > 0){
            int remainder = number % 10;
            if (remainder % 2 == 0){
                sumofeven += remainder;
            } else {
                sumofodd += remainder;
            }
            number = number / 10;
        }
        System.out.println("Sum of even digits: " + sumofeven);
        System.out.println("Sum of odd digits: " + sumofodd);
    }

    public static void question7(int limit){
        // print a pattern of stars 
        for (int i = 0; i < limit; i++){
            for (int j = 0; j < i; j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public static void main(String args[]){
        int rem,even=0,odd=0;
        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter the number:");
        int number = scanner.nextInt();
        while(number>0){
            rem=number %10;
            if(rem%2==0){
                even=even+rem;
            }
            else
                odd=odd+rem;


            
        }
        
        
    }
}