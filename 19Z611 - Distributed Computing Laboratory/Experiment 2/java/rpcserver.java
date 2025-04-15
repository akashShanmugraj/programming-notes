import java.rmi.registry.*;
import java.security.spec.ECFieldF2m;

public class rpcserver {

    public static void main(String[] args) {
        try {
            rpcprocess p1 = new rpcprocess(10);

            Registry registry = LocateRegistry.createRegistry(5001);
            registry.bind("process1", p1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}