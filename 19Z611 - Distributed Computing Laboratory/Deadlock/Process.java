import java.util.*;

public class Process {
    int pid;
    Resource waitingfor;
    Resource using;
    Boolean accessedOutside;
    ArrayList<Site> accessSites = new ArrayList<>();
    Site primarySite;
    ArrayList<Process> dependents = new ArrayList<>();
    ArrayList<Process> dependencies = new ArrayList<>();

    public Process(int pid){
        this.pid = pid;
    }

    public void acceptDependents(Process process){
        dependents.add(process);
        if (process.primarySite != this.primarySite){
            accessSites.add(process.primarySite);
            this.accessedOutside = true;
        }
    }
     
}
