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
            
            Registry registry4 = LocateRegistry.getRegistry("localhost", 4004);
            RPCProcessInterface process4 = (RPCProcessInterface) registry4.lookup("process4");

            Registry registry5 = LocateRegistry.getRegistry("localhost", 4005);
            RPCProcessInterface process5 = (RPCProcessInterface) registry5.lookup("process5");

            List<RPCProcessInterface> AllProcessesList = new ArrayList<RPCProcessInterface>();
            AllProcessesList.add(process1);
            AllProcessesList.add(process2);
            AllProcessesList.add(process3);
            AllProcessesList.add(process4);
            AllProcessesList.add(process5);
            
            System.out.println("Process 1 priority: " + process1.getProcesses());
            System.out.println("Process 2 priority: " + process2.getProcesses());
            System.out.println("Process 3 priority: " + process3.getProcesses());
            System.out.println("Process 4 priority: " + process4.getProcesses());
            System.out.println("Process 5 priority: " + process5.getProcesses());

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