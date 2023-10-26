import java.util.ArrayList;
import SampleClasses.Employee.UserDetails;
import SampleClasses.multiplication.MULOP;

public class experiment8 {
    public static void question1(){
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

    public static void question2(String[] args) {
        UserDetails user = new UserDetails("John Doe", "123 Main Street", "123-456-7890", "jdoe", "password", "user",
                "SDev");
        user.displayUserDetails();

        MULOP MuliplicationObject = new MULOP();
        MuliplicationObject.twowaymultiplication(2, 3);
        MuliplicationObject.threewaymultiplication(2, 3, 4);

    }
}