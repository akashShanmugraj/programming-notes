import java.util.*;

class ProbeMessage{
    int senderid;
    int receiverid;
    int blockedid;
    public ProbeMessage(int senderid, int receiverid, int blockedid) {
        this.senderid = senderid;
        this.receiverid = receiverid;
        this.blockedid = blockedid;
    }
}

class Process {
    int pid; // process id
    Resource waitingfor; // p2 --> this
    Resource using; // this --> p2
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

    public int LinkProcess(Process targetprocess){
        if (targetprocess.waitingfor == null){

        }
        return 0;

    }
}

public class ProbeBased {
    
}

