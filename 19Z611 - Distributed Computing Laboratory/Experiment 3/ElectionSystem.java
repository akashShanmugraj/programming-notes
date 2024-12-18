import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ElectionSystem {

    class Process {
        int processid;
        int priority;
        boolean isDown;
        boolean isCoordinator;
        int timeout;

        public Process(int id, int priority) {
            this.processid = id;
            this.priority = priority;
            this.isDown = false;
            this.isCoordinator = false;
            this.timeout = 0;
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

        public int talkTo(Process targetprocess) {
            if (targetprocess.isDown == true) {
                System.out.println(this.processid + " found process with PID "  + targetprocess.processid + " to be down!");
                return 0;
            }

            return 1;
        }

        @Override
        public String toString() {
            return "Process{id=" + processid + ", prior=" + priority + ", down=" + isDown + ", coord=" + isCoordinator + "}";
        }
    }

    public Process electCoordinator(List<Process> processList, int electType) {
        int maxpriority = processList.get(0).priority;
        Process maxvalprocess = processList.get(0);

        for (Process processiter : processList) {
            if (processiter.priority > maxpriority && !processiter.isDown) {
            maxpriority = processiter.priority;
                maxvalprocess = processiter;
            }
        }

        if (electType == 1) {
            System.out.println("Elected " + maxvalprocess.processid + " with priority " + maxvalprocess.priority + ".");
        } else if (electType == 2) {
            System.out.println("Relected " + maxvalprocess.processid + " with priority " + maxvalprocess.priority + ".");
        }
        
        maxvalprocess.isCoordinator = true;
        return maxvalprocess;
    }

    public List<Process> randomprocesses(int len) {
        List<Process> processList = new ArrayList<>();

        Random rh = new Random();

        for (int iter = 0; iter < len; iter++) {
            int id = rh.nextInt(1000);         
            int priority = rh.nextInt(100);  
            processList.add(new Process(id, priority));
        }

        return processList;
    }

    public List<Process> serialprocesses(int len) {
        List<Process> processList = new ArrayList<>();


        for (int iter = 0; iter < len; iter++) {
            int id = iter;
            int priority = iter;
            processList.add(new Process(id, priority));
        }

        return processList;
    }


    public boolean shouldKill() {
        Random rm = new Random();
        return rm.nextInt(100) < 30;
    }

    public void killRandom(List<Process> processeslist, int processescount) {
        Random rm = new Random();
        int killIndex = rm.nextInt(processescount);
        processeslist.get(killIndex).isDown = true;
        processeslist.get(killIndex).isCoordinator = false;
        processeslist.get(killIndex).timeout = 5;
        System.out.println("Process " + processeslist.get(killIndex).processid + " with priority " + processeslist.get(killIndex).priority + " was killed.");
    }

    public void killCoordinator(Process coordinatorProcess) {
        coordinatorProcess.isCoordinator = false;
        coordinatorProcess.isDown = true;
        coordinatorProcess.timeout = 5;
        System.out.println("Process " + coordinatorProcess.processid + " with priority " + coordinatorProcess.priority + " was killed.");
    }


    public static void main(String[] args) {
        ElectionSystem electionsystem = new ElectionSystem();
        int totalNumberofProcesses = 5;
        // List<Process> processes = electionsystem.randomprocesses(totalNumberofProcesses);
        List<Process> processes = electionsystem.serialprocesses(totalNumberofProcesses);

        for (Process process : processes) {
            System.out.println(process);
        }

        Process coordinatorreference = electionsystem.electCoordinator(processes, 1);
        int timeCycleCounter = 0;

        while (true) {
            // System.out.println("Coordinator is " + coordinatorreference.processid + " with priority " + coordinatorreference.priority);
            System.out.println("T"+timeCycleCounter);
            timeCycleCounter++;
            if (electionsystem.shouldKill()) {
                electionsystem.killCoordinator(coordinatorreference);
            }

            for (Process process : processes) {
                int wakeupPriority = process.reducetimeout();
                int wentdownResponse = process.talkTo(coordinatorreference);

                if (wakeupPriority > coordinatorreference.priority || wentdownResponse == 0) {
                    coordinatorreference = electionsystem.electCoordinator(processes, 2);
                }
            }

            try {
                Thread.sleep(1000); // Delay for 1 second
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
