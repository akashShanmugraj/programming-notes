import java.util.List;
import java.util.Random;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RPCProcess extends UnicastRemoteObject implements RPCProcessInterface {
    int processid;
    int priority;
    boolean isDown;
    boolean isCoordinator;
    int timeout;
    List<RPCProcessInterface> allRPCProcesses;
    int port;
    RPCProcessInterface thecoordinator;

    public RPCProcess(int id, int priority, int port) throws RemoteException {
        this.processid = id;
        this.priority = priority;
        this.isDown = false;
        this.isCoordinator = false;
        this.timeout = 0;
        this.port = port;
    }

    public int getPriority() throws RemoteException {
        return this.priority;
    }

    public boolean isDown() throws RemoteException {
        return this.isDown;
    }

    public int getProcessID() throws RemoteException {
        return this.processid;
    }

    public boolean isCoordinator() throws RemoteException {
        return this.isCoordinator;
    }

    public void addProcess(int processID, int priority, int port) throws RemoteException {
        RPCProcessInterface newprocess = new RPCProcess(processID, priority, port);
        this.allRPCProcesses.add(newprocess);
        newprocess.setProcesses(allRPCProcesses);
    }

    public List<RPCProcessInterface> getProcesses() throws RemoteException {
        return allRPCProcesses;
    }

    public void setProcesses(List<RPCProcessInterface> newprocesslist) throws RemoteException {
        this.allRPCProcesses = newprocesslist;
    }

    public int reducetimeout() throws RemoteException {
        if (!this.isDown) {
            return 1;
        }
        this.timeout -= 1;
        if (this.timeout == 0) {
            this.isDown = false;
            System.out.println(this.processid + " process woke up!");
            return this.priority; 
        }
        return -1;
    }

    public void randomlyKillYourself() throws RemoteException {
        Random rm = new Random();
        if (rm.nextInt(100) < 30 && this.isCoordinator){
            this.isDown = true;
            this.isCoordinator = false;
        }
    }

    public RPCProcessInterface BullyElector() throws RemoteException {
        int maxpriority = Integer.MIN_VALUE;
        RPCProcessInterface maxprocess = null;

        for (RPCProcessInterface iter : allRPCProcesses) {
            if (iter.getPriority() > maxpriority && !iter.isDown()) {
                maxpriority = iter.getPriority();
                maxprocess = iter;
            }
        }
        return maxprocess;
    }

    

    @Override
    public String toString() {
        return "Process{id=" + processid + ", prior=" + priority + ", down=" + isDown + ", coord=" + isCoordinator + ", port=" + port +"}";
    }
}