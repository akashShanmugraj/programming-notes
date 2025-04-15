import java.util.*;

public class Process {
    int processid;
    int priority;
    int sleeptime;
    Boolean isasleep;
    Boolean iscoordinator;
    ArrayList<Process> processlist = new ArrayList<>();

    public Process(int pid, int priority){
        this.processid = pid;
        this.priority = priority;
        this.isasleep = false;
        this.iscoordinator = false;
        this.sleeptime = 0;
    }

    public void setProcessList(ArrayList<Process> processlist){
        this.processlist = processlist;
    }

    public ArrayList<Process> getProcessList(){
        return this.processlist;
    }

    public void addProcesstoProcessList(Process newprocess){
        processlist.add(newprocess);
        Collections.sort(processlist);
    }

    public Boolean isAlive(){
        return !this.isasleep;
    }

    public Process getNextImportantProcess(){
        for (Process iterprocess : this.processlist) {
            if (iterprocess.priority > this.priority){
                return iterprocess
            }
        }

        return null;
    }

    public Process conductElection(Process predecessor){
        Process successor = null;
        successor = getNextImportantProcess()

        if not(sucessor){
            if (this.isAlive()){
                return 
            }
        }
    }

    public int randomlykillyourself(){
        if (this.isasleep){
            return 208;
        }

        Random robject = new Random();
        if (robject.nextInt(100) > 91){
            System.out.println("Killing " + this.processid);
            this.isasleep = true;
            this.sleeptime = 5;
        }
    }

    public void passtime(){
        if (this.isasleep){
            this.sleeptime -= 1;
        }
    }
}
