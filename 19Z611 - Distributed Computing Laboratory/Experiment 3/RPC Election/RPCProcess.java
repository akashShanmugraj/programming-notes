import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

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

    public boolean isDown() {
        return this.isDown;
    }

    public int getProcessID() throws RemoteException {
        return this.processid;
    }


    public RPCProcessInterface getCoordinator() {
        return this.thecoordinator;
    }

    public void setCoordinator(RPCProcessInterface newCoordinator) throws RemoteException {
        if (this.processid == newCoordinator.getProcessID()) {
            this.thecoordinator = this;
            this.isCoordinator = true;
        } else {
            this.isCoordinator = false;
            this.thecoordinator = newCoordinator;
        }
    }

    public void informNewCoordinator(RPCProcessInterface newCoordinator) throws RemoteException{
        for  (RPCProcessInterface process: this.allRPCProcesses) {
            process.setCoordinator(newCoordinator);
        }
    }
    
    public boolean isCoordinator() throws RemoteException {
        return this.isCoordinator;
    }

    public boolean TalkToCoordinator() throws RemoteException {
        if (this.isDown) {
            return true;
        }
        return !(this.thecoordinator.isDown());
    }
    
    public List<String> getProcesses() throws RemoteException {
        List<String> processlist = new ArrayList<String>();
        for (RPCProcessInterface iter : allRPCProcesses) {
            processlist.add(iter.toString());
        }
        return processlist;
    }
    
    public void setProcesses(List<RPCProcessInterface> newprocesslist) throws RemoteException {
        this.allRPCProcesses = newprocesslist;
    }
    
    public void addProcess(int processID, int priority, int port) throws RemoteException {
        RPCProcessInterface newprocess = new RPCProcess(processID, priority, port);
        this.allRPCProcesses.add(newprocess);
        newprocess.setProcesses(allRPCProcesses);
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
            System.out.println("Process " + this.processid + " priority " + this.priority + " was killed as a coordinator");
            this.timeout = 5;
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

    public void ElectInform(int electiontype) throws RemoteException{
        if (electiontype == 1) {
            RPCProcessInterface newCoordinator = this.BullyElector();
            System.out.println("Process " + newCoordinator.getProcessID() + " priority " + newCoordinator.getPriority() + " was set as the coordinator");

            this.informNewCoordinator(newCoordinator);
        }
    }

    

    @Override
    public String toString() {
        return "Process{id=" + processid + ", prior=" + priority + ", down=" + isDown + ", coord=" + isCoordinator + ", port=" + port +"}";
    }
}