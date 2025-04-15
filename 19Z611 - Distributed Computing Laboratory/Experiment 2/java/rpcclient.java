import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*;

public class rpcclient {
    public static void main(String[] args) {
        try {
            Registry registry1 = LocateRegistry.getRegistry("localhost", 5001);
            rpcprocessinterface process1 = (rpcprocessinterface) registry1.lookup("process1");

            process1.helloworld();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}