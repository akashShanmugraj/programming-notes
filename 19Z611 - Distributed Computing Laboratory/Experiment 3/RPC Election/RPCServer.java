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
            RPCProcess process4 = new RPCProcess(4, 40, 4004);
            RPCProcess process5 = new RPCProcess(5, 50, 4005);

            List<RPCProcessInterface> allProcesses = new ArrayList<RPCProcessInterface>();
            allProcesses.add(process1);
            allProcesses.add(process2);
            allProcesses.add(process3);
            allProcesses.add(process4);
            allProcesses.add(process5);

            process1.SetProcesses(allProcesses);
            process2.SetProcesses(allProcesses);
            process3.SetProcesses(allProcesses);
            process4.SetProcesses(allProcesses);
            process5.SetProcesses(allProcesses);

            process1.ElectInform(1);

            Registry registry1 = LocateRegistry.createRegistry(4001);
            registry1.rebind("process1", process1);

            Registry registry2 = LocateRegistry.createRegistry(4002);
            registry2.rebind("process2", process2);

            Registry registry3 = LocateRegistry.createRegistry(4003);
            registry3.rebind("process3", process3);

            Registry registry4 = LocateRegistry.createRegistry(4004);
            registry4.rebind("process4", process4);

            Registry registry5 = LocateRegistry.createRegistry(4005);
            registry5.rebind("process5", process5);

            System.out.println("RPCService is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
