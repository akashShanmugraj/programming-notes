import java.util.Scanner;

public class experiment8 {

    public static void main(String[] args) {
        Scanner commonscannerobject = new Scanner(System.in);

        SavingsAccount myAccount = new SavingsAccount();
        myAccount.rateOfInterest = 3.5;

        myAccount.deposit();
        myAccount.display();

        myAccount.calculateAmount();

        myAccount.withdrawal();
        myAccount.display();

        commonscannerobject.close();
    }

}

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

class SavingsAccount extends Accounts {
    double rateOfInterest;

    void calculateAmount() {
        double amount = Balance + (Balance * rateOfInterest / 100);
        System.out.println("The total amount in the account after adding interest is: " + amount);
    }

    void withdrawal() {
        Scanner scanningobject = new Scanner(System.in);

        System.out.println("Enter amount for withdrawal (your current balance is " + Balance + " INR):");
        double towithdraw = scanningobject.nextDouble();

        if (towithdraw <= Balance) {
            Balance -= towithdraw;
            System.out.println(
                    "Sucessfully withdrew " + towithdraw + " INR.\nYour current balance is " + Balance + "INR.");
        } else {
            System.out.println("Insufficient Funds.\nYour current balance is:" + Balance + " INR");
        }

        scanningobject.close();
    }

    void deposit() {
        double todeposit;

        System.out.println("Enter amount for deposit (your current balance is " + Balance + " INR):");
        Scanner depositscanningobject = new Scanner(System.in);
        todeposit = depositscanningobject.nextDouble();

        Balance += todeposit;

        System.out.println(
                "Sucessfully deposited an amount of " + todeposit + ". \nYour current balance is " + Balance + " INR.");

        depositscanningobject.close();

    }
}

