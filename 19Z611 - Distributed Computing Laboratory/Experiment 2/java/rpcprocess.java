import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class rpcprocess extends UnicastRemoteObject implements rpcprocessinterface {
    int numvar = 10;

    public rpcprocess(int num) throws RemoteException {
        this.numvar = num;

    }

    public static void main(String[] args) {
        System.out.println("rpcprocess's main function");
    }

    public void helloworld() throws RemoteException {
        System.out.println("Hello World");
    }
}