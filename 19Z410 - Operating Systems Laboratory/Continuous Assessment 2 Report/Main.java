import java.util.concurrent.Semaphore;
import java.util.Random;
import java.util.ArrayList;


public class Main {
    public static void main(String[] args) {
        Semaphore caregiverSemaphore = new Semaphore(3);
        Semaphore childSemaphore = new Semaphore(0);

        Caregiver caregiver = new Caregiver(caregiverSemaphore, childSemaphore);
        caregiver.start();

        ArrayList<Child> children = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            Child child = new Child(i, caregiverSemaphore, childSemaphore);
            children.add(child);
            child.start();
        }

        try {
            for (Child child : children) {
                child.join();
            }
            caregiver.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Child extends Thread {
    private int name;
    private Semaphore caregiverSemaphore;
    private Semaphore childSemaphore;

    public Child(int name, Semaphore caregiverSemaphore, Semaphore childSemaphore) {
        this.name = name;
        this.caregiverSemaphore = caregiverSemaphore;
        this.childSemaphore = childSemaphore;
    }

    public void run() {
        try {
            System.out.println("Child " + name + " needs care.");
            caregiverSemaphore.acquire();
            System.out.println("Child " + name + " is receiving care.");
            Thread.sleep(new Random().nextInt(3000) + 1000);
            System.out.println("Child " + name + " has finished receiving care.");
            caregiverSemaphore.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Caregiver extends Thread {
    private Semaphore caregiverSemaphore;
    private Semaphore childSemaphore;

    public Caregiver(Semaphore caregiverSemaphore, Semaphore childSemaphore) {
        this.caregiverSemaphore = caregiverSemaphore;
        this.childSemaphore = childSemaphore;
    }

    public void run() {
        try {
            while (true) {
                caregiverSemaphore.acquire();
                System.out.println("Caregiver is available.");
                childSemaphore.release();
                System.out.println("Caregiver is caring for a child.");
                Thread.sleep(new Random().nextInt(3000) + 1000);
                System.out.println("Caregiver has finished caring for a child.");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}