import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;
import java.util.ArrayList;



public class RPCServer {
    public static void main(String[] args) {
        try {
            RPCProcess process1 = new RPCProcess(1, 10, 4001);
            RPCProcess process2 = new RPCProcess(2, 20, 4002);
            RPCProcess process3 = new RPCProcess(3, 30, 4003);
            
            List<RPCProcessInterface> allProcesses = new ArrayList<RPCProcessInterface>();
            allProcesses.add(process1);
            allProcesses.add(process2);
            allProcesses.add(process3);

            process1.setProcesses(allProcesses);
            process2.setProcesses(allProcesses);
            process3.setProcesses(allProcesses);

            Registry registry1 = LocateRegistry.createRegistry(4001);
            registry1.rebind("process1", process1);

            Registry registry2 = LocateRegistry.createRegistry(4002);
            registry2.rebind("process2", process2);
            
            Registry registry3 = LocateRegistry.createRegistry(4003);
            registry3.rebind("process3", process3);

            System.out.println("RPCService is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
