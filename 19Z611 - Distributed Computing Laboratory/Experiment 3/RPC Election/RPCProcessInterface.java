import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface RPCProcessInterface extends Remote {
    int GetPriority() throws RemoteException;

    int GetProcessID() throws RemoteException;

    RPCProcessInterface GetCoordinator() throws RemoteException;

    List<String> GetProcesses() throws RemoteException;

    boolean IsDown() throws RemoteException;

    boolean IsCoordinator() throws RemoteException;

    void SetProcesses(List<RPCProcessInterface> newprocesslist) throws RemoteException;

    void SetCoordinator(RPCProcessInterface newCoordinator) throws RemoteException;

    void InformNewCoordinator(RPCProcessInterface newCoordinator) throws RemoteException;

    boolean TalkToCoordinator() throws RemoteException;

    void AddProcess(int processID, int priority, int port) throws RemoteException;

    int ReduceTimeout() throws RemoteException;

    void RandomlyKillYourself() throws RemoteException;

    RPCProcessInterface BullyElector() throws RemoteException;

    void ElectInform(int priority) throws RemoteException;

}