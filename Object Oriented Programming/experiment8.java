import SampleClasses.Employee.UserDetails;
import SampleClasses.multiplication.MULOP;

public class experiment8 {
    public static void main(String[] args) {
        UserDetails user = new UserDetails("John Doe", "123 Main Street", "123-456-7890", "jdoe", "password", "user",
                "SDev");
        user.displayUserDetails();

        MULOP MuliplicationObject = new MULOP();
        MuliplicationObject.twowaymultiplication(2, 3);
        MuliplicationObject.threewaymultiplication(2, 3, 4);

    }
}