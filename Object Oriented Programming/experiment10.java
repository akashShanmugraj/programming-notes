public class experiment10 {
    public static void main(String[] args) {
        Student student = new Student();
        try {
            student.getInput("John Doe", 123456, 85, 90, 78);
            student.calculateTotalAndAverage();
            student.displayStudentInfo();
        } catch (InvalidRegNoException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (MarkOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}

class InvalidRegNoException extends Exception {
    public InvalidRegNoException(String message) {
        super(message);
    }
}

class MarkOutOfBoundsException extends Exception {
    public MarkOutOfBoundsException(String message) {
        super(message);
    }
}

class Student {
    private String Name;
    private int RegisterNumber;
    private int Mark1;
    private int Mark2;
    private int Mark3;

    public void getInput(String name, int regNo, int mark1, int mark2, int mark3) throws InvalidRegNoException, MarkOutOfBoundsException {
        if (regNo > 999999) {
            throw new InvalidRegNoException("Invalid Register Number. Should be 6 digits or less.");
        }
        if (mark1 > 100 || mark2 > 100 || mark3 > 100) {
            throw new MarkOutOfBoundsException("Marks should be in the range of 0 to 100.");
        }
        this.Name = name;
        this.RegisterNumber = regNo;
        this.Mark1 = mark1;
        this.Mark2 = mark2;
        this.Mark3 = mark3;
    }

    public void calculateTotalAndAverage() {
        int total = Mark1 + Mark2 + Mark3;
        double average = total / 3.0;
        System.out.println("Total Marks: " + total);
        System.out.println("Average Marks: " + average);
    }

    public void displayStudentInfo() {
        System.out.println("Name: " + Name);
        System.out.println("Register Number: " + RegisterNumber);
        System.out.println("Mark 1: " + Mark1);
        System.out.println("Mark 2: " + Mark2);
        System.out.println("Mark 3: " + Mark3);
    }
}

