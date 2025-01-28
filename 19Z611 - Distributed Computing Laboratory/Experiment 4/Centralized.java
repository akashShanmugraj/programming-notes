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
        // System.out.println("Current site ids: " + currentsiteids);
        // System.out.println("Next site ids: " + nextsiteids);
        for (int siteid : nextsiteids){
            if (!currentsiteids.contains(siteid)){
                // System.out.println("Difference found: " + siteid);
                return false;
            }
        }
        // System.out.println("No difference found");
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
        // System.err.println(r.assignedto == null);
        System.out.println("\n\n");
        if (r.assignedto == null) {
            this.using = r;
            r.assignedto = this;
            System.out.println("Assigned resource " + r.rid + " to process " + this.pid);
            return 1;
        } else {
            System.out.println("Process " + this.pid + " requesting resource " + r.rid + " assigned to p" + r.assignedto.pid);
            Process current;
            current = r.assignedto;
            
            if (!siteSubtraction(current.siteIDs, this.siteIDs)){
                System.out.println("Deadlock present in system");
                return -2;
            }

            while (current.pid > 0) {
                if (current == this) {
                    System.out.println("this is the problem");
                    current = new Process(-1, Collections.emptySet());
                    break;
                }
                if (current.waitingfor == null) {
                    System.out.println("Process " + current.pid + " is not waiting for any resource");
                    current = new Process(0, Collections.emptySet());
                    break;
                }
                if (!siteSubtraction(current.waitingfor.assignedto.siteIDs, current.siteIDs)){
                    current = new Process(-2, Collections.emptySet());
                    break;
                }
                System.out.println("Process " + current.pid + " is waiting for resource " + current.waitingfor.rid + " assigned to p" + current.waitingfor.assignedto.pid);
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

class Resource {
    int rid; // resource id
    Process assignedto;
    Process waiting;

    public Resource(int rid, Process assignedto, Process waiting){
        this.rid = rid;
        this.assignedto = assignedto;
        this.waiting = waiting;
    }
}

public class Centralized {
    public static void main(String[] args) {
        Process p1 = new Process(1, new HashSet<>(Arrays.asList(1)));
        Process p2 = new Process(2, new HashSet<>(Arrays.asList(1)));
        Process p3 = new Process(3, new HashSet<>(Arrays.asList(1)));
        Process p4 = new Process(4, new HashSet<>(Arrays.asList(1)));

        Resource r1 = new Resource(101, null, null);
        Resource r2 = new Resource(102, null, null);
        Resource r3 = new Resource(103, null, null);
        Resource r4 = new Resource(104, null, null);
        
        p1.request(r1);
        p2.request(r2);
        p3.request(r3);
        p4.request(r4);

        p1.request(r3);
        p3.request(r2);
        p2.request(r4);
        p4.request(r1);
    }
}
