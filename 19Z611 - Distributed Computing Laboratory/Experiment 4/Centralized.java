// yet to be checked
import java.util.*;

class Process {
    int pid; // process id
    Resource waitingfor;
    Resource using;
    Set<Integer> siteIDs; // site ids

    public void addSite(int sid) {
        this.siteIDs.add(sid);
    }

    public boolean siteSubtraction(Set<Integer> nextsiteids, Set<Integer> currentsiteids){
        for (int siteid : nextsiteids){
            if (!currentsiteids.contains(siteid)){
                return false;
            }
        }
        return true;
    }
    
    public Process(int pid, Set<Integer> siteIDs){
        this.pid = pid;
        this.siteIDs = siteIDs;
    }

    public int request(Resource r) {
        // return 1 for assigned to resource
        // return 0 for waiting for resource
        // return -1 for deadlock in local site
        // return -2 for deadlock in system (between multiple sites)
        if (r.assignedto == null) {
            this.using = r;
            r.assignedto = this;
            System.out.println("Assigned resource " + r.rid + " to process " + this.pid);
            return 1;
        } else {
            Process current;
            current = r.assignedto;
            
            if (siteSubtraction(current.siteIDs, this.siteIDs)){
                System.out.println("Deadlock present in system");
                return -2;
            }

            while (current.pid > 0) {
                if (current.waitingfor == null) {
                    current = new Process(0, Collections.emptySet());
                }
                if (current == this) {
                    current = new Process(-1, Collections.emptySet());
                    break;
                }
                if (!siteSubtraction(current.waitingfor.assignedto.siteIDs, current.siteIDs)){
                    current = new Process(-2, Collections.emptySet());
                    break;
                }
                current = current.waitingfor.assignedto;
            }

            if (current.pid == -1) {
                System.out.println("Deadlock present in local site");
                return -1;
            } else if (current.pid == -2) {
                System.out.println("Deadlock present in system");
                return -2;
            } else {
                this.waitingfor = r;
                r.waiting = this;
                System.out.println("Process " + this.pid + " waiting for resource " + r.rid);
                return 0;
            }
            
        }
    }
}

class Resources {
    int rid; // resource id
    Process assignedto;
    Process waiting;
    
    Set<Integer> siteIDs; // site ids

    public void addSite(int sid) {
        this.siteIDs.add(sid);
    }

    public Resources(int rid, Set<Integer> siteIDs, Process assignedto, Process waiting){
        this.rid = rid;
        this.siteIDs = siteIDs;
        this.assignedto = assignedto;
        this.waiting = waiting;
    }
}

public class Centralized {
    
}
