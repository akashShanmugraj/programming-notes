import java.rmi.RemoteException;
import java.rmi.Remote;

public interface rpcprocessinterface extends Remote {
    void helloworld() throws RemoteException;

}
