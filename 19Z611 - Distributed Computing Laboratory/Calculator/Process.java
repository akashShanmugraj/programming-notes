import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class Process extends UnicastRemoteObject implements ProcessInterface {

    public Process() throws RemoteException {
        super();
    }

    public void add(int a, int b) throws RemoteException {
        System.out.println("Sum is " + (a + b));
    }

    public void subtract(int a, int b) throws RemoteException{
        System.out.println("subtract 1");
    }
    public void add(float a, float b) throws RemoteException{
        System.out.println("Extra function");
    }
    public float random(int a, int b) throws RemoteException{
        System.out.println("random function");
        return 0;
    }
}