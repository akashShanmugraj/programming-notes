import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.List;
public class RPCClient {
    public static void main(String[] args) {
        try {
            Registry registry1 = LocateRegistry.getRegistry("localhost", 4001);
            RPCProcessInterface process1 = (RPCProcessInterface) registry1.lookup("process1");

            Registry registry2 = LocateRegistry.getRegistry("localhost", 4002);
            RPCProcessInterface process2 = (RPCProcessInterface) registry2.lookup("process2");

            Registry registry3 = LocateRegistry.getRegistry("localhost", 4003);
            RPCProcessInterface process3 = (RPCProcessInterface) registry3.lookup("process3");
            
            List<RPCProcessInterface> AllProcessesList = new ArrayList<RPCProcessInterface>();
            AllProcessesList.add(process1);
            AllProcessesList.add(process2);
            AllProcessesList.add(process3);
            
            System.out.println("Process 1 priority: " + process1.getProcesses());
            System.out.println("Process 2 priority: " + process2.getProcesses());
            System.out.println("Process 3 priority: " + process3.getProcesses());

            while (true) {
                process1.getCoordinator().randomlyKillYourself();
                boolean ElectionNeeded = false;
                int WakeupPriority;
                RPCProcessInterface WhistleBlower = process1;             
                for (RPCProcessInterface process : AllProcessesList) {
                    WakeupPriority = process.reducetimeout();
                    if (!process.TalkToCoordinator() || WakeupPriority > process.getCoordinator().getPriority() ) {
                        ElectionNeeded = true;
                        WhistleBlower = process;
                    }
                }

                if (ElectionNeeded) {
                    WhistleBlower.ElectInform(1);
                }

                try {
                    Thread.sleep(1000); // Delay for 1 second
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
    }
}
}