import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static void main(String[] args) {
        try {
            Process p1 = new Process();
            Registry registry = LocateRegistry.createRegistry(5006);
            registry.bind("calculator", p1);
            System.out.println("Calculator is being served on 5006");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}