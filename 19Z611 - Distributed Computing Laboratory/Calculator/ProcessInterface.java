import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ProcessInterface extends Remote {
    void add(int a, int b) throws RemoteException;
    void subtract(int a, int b) throws RemoteException;
    float random(int a, int b) throws RemoteException;
}
