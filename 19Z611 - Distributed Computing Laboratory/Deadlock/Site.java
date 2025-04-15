import java.util.*;

class ProcessLink{
    int sourceprocessid;
    int destinationprocessid;
    Process sourceProcess;
    Process destinationProcess;

    public ProcessLink(int spid, int dpid, Process spr, Process dpr){
        this.sourceProcess = spr;
        this.destinationProcess = dpr;
        this.sourceprocessid = spid;
        this.destinationprocessid = dpid;
    }
}

public class Site {
    int siteid;
    ArrayList<ProcessLink> masterlinklist = new ArrayList<>();
    ArrayList<Process> processlist = new ArrayList<>();


    public Site(int siteid){
        this.siteid = siteid;
    }

    public void addProcess(Process newprocess){
        processlist.add(newprocess);
    }

    public void createLink(Process sourceprocess, Process destinationprocess){
        masterlinklist.add(
            new ProcessLink(sourceprocess.pid, destinationprocess.pid, sourceprocess, destinationprocess)
        );

        sourceprocess.
    }

}