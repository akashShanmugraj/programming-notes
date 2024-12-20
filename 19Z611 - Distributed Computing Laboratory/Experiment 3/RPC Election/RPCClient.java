import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RPCClient {
    public static void main(String[] args) {
        try {
            Registry registry1 = LocateRegistry.getRegistry("localhost", 4001);
            RPCProcessInterface process1 = (RPCProcessInterface) registry1.lookup("process1");

            Registry registry2 = LocateRegistry.getRegistry("localhost", 4002);
            RPCProcessInterface process2 = (RPCProcessInterface) registry2.lookup("process2");

            Registry registry3 = LocateRegistry.getRegistry("localhost", 4003);
            RPCProcessInterface process3 = (RPCProcessInterface) registry3.lookup("process3");

            System.out.println("Process 1 priority: " + process1.getPriority());
            System.out.println("Process 2 priority: " + process2.getPriority());
            System.out.println("Process 3 priority: " + process3.getPriority());
        } catch (Exception e) {
            e.printStackTrace();
    }
}
}