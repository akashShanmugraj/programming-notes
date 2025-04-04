import java.rmi.registry.*;

public class Client {
    public static void main(String[] args) {
        try {
            Registry r = LocateRegistry.getRegistry(5006);
            ProcessInterface p = (ProcessInterface) r.lookup("calculator");

            // add() doesn't return a value, it prints on the server side
            p.add(5, 3);
            
            // random() returns a float value
            float randomValue = p.random(1, 10);
            System.out.println("Random value: " + randomValue);
            
            // subtract() doesn't return a value, it prints on the server side
            p.subtract(10, 4);

        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
    
}