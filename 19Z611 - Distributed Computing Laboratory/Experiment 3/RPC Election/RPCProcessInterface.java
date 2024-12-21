import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface RPCProcessInterface extends Remote {
    int getPriority() throws RemoteException;

    int getProcessID() throws RemoteException;

    RPCProcessInterface getCoordinator() throws RemoteException;

    List<String> getProcesses() throws RemoteException;

    boolean isDown() throws RemoteException;

    boolean isCoordinator() throws RemoteException;

    void setProcesses(List<RPCProcessInterface> newprocesslist) throws RemoteException;

    void setCoordinator(RPCProcessInterface newCoordinator) throws RemoteException;

    void informNewCoordinator(RPCProcessInterface newCoordinator) throws RemoteException;

    boolean TalkToCoordinator() throws RemoteException;

    void addProcess(int processID, int priority, int port) throws RemoteException;

    int reducetimeout() throws RemoteException;

    void randomlyKillYourself() throws RemoteException;

    RPCProcessInterface BullyElector() throws RemoteException;

    void ElectInform(int priority) throws RemoteException;

}