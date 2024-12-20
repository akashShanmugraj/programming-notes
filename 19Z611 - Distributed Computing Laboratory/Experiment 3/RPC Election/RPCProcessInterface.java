import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface RPCProcessInterface extends Remote {
    void addProcess(int processID, int priority, int port) throws RemoteException;
    List<RPCProcessInterface> getProcesses() throws RemoteException;
    void setProcesses(List<RPCProcessInterface> newprocesslist) throws RemoteException;
    int reducetimeout() throws RemoteException;
    void randomlyKillYourself() throws RemoteException;
    boolean isDown() throws RemoteException;
    int getPriority() throws RemoteException;
    RPCProcessInterface BullyElector() throws RemoteException;
}