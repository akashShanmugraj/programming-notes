import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RPCProcess {
    int processid;
    int priority;
    boolean isDown;
    boolean isCoordinator;
    int timeout;
    List<RPCProcess> allRPCProcesses;
    int port;
    RPCProcess thecoordinator;

    public void addProcess(int processID, int priority, int port) {
        RPCProcess newprocess = new RPCProcess(processID, priority,port);
        this.allRPCProcesses.add(newprocess);
        newprocess.setProcesses(allRPCProcesses);
    }

    public List<RPCProcess> getProcesses() {
        return allRPCProcesses;
    }

    public void setProcesses(List<RPCProcess> newprocesslist) {
        this.allRPCProcesses = newprocesslist;
    }

    public RPCProcess(int id, int priority, int port) {
        this.processid = id;
        this.priority = priority;
        this.isDown = false;
        this.isCoordinator = false;
        this.timeout = 0;
        this.port = port;
    }

    public int reducetimeout() {
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

    // TODO: do some port connection shit
    public int talkTo(RPCProcess targetprocess) {
        if (targetprocess.isDown) {
            System.out.println(this.processid + " found process with PID "  + targetprocess.processid + " to be down!");
            return 0;
        }

        return 1;
    }

    public void randomlyKillYourself() {
        Random rm = new Random();
        if (rm.nextInt(100) < 30 && this.isCoordinator == true){
            this.isDown = true;
            this.isCoordinator = false;
        }
    }
    
    public RPCProcess BullyElector() {
        int maxpriority = Integer.MIN_VALUE;
        RPCProcess maxprocess = new RPCProcess(0, 0, 0);

        for (RPCProcess iter: allRPCProcesses) {
            if (iter.priority > maxpriority && !iter.isDown) {
                maxpriority = iter.priority;
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