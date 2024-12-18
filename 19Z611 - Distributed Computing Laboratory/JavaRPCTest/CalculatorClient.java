import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CalculatorClient {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            Calculator calculator = (Calculator) registry.lookup("CalculatorService");

            System.out.println("10 + 5 = " + calculator.add(10, 15));
            System.out.println("10 - 5 = " + calculator.subtract(10, 5));
            System.out.println("10 * 5 = " + calculator.multiply(10, 15));
            System.out.println("10 / 5 = " + calculator.divide(10, 5));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
