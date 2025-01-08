class Process {
    int pid;
    Resource waitingfor;
    Resource using;
    public Process(int pid){
        this.pid = pid;
    }

    public boolean request(Resource r) {
        // System.out.println("Process " + this.pid + " requesting resource " + r.rid + " isnotassigned " + r.assignedto);
        // System.err.println(r.assignedto == null);
        if (r.assignedto == null) {
            this.using = r;
            r.assignedto = this;
            System.out.println("Assigned resource " + r.rid + " to process " + this.pid);
            return true;

        } else {
            // find who holds r
            // find 'what' that who is waiting for
            // go on until you realise you are the problem

            Process current;
            current = r.assignedto;
            while (current != null) {
                if (current == this) {
                    break;
                }
                if (current.waitingfor == null) {
                    current = null;
                    break;
                }
                current = current.waitingfor.assignedto;
            }

            if (current == null) {
                this.waitingfor = r;
                r.waiting = this;
                System.out.println("Assigned resource " + r.rid + " to process " + this.pid);

                return true;
            } else if (current == this) {
                System.out.println("Deadlock Detected! Cannot assign process " + this.pid + " to resource " + r.rid);
                return false;
            }

            return false;
        }
    }
}

class Resource {
    int rid;
    Process assignedto;
    Process waiting;
    public Resource(int rid, Process assignedto, Process waiting){
        this.rid = rid;
        this.assignedto = assignedto;
        this.waiting = waiting;
    }
}

public class Deadlock {
    public static void main(String[] args) {
        Process p1 = new Process(1);
        Process p2 = new Process(2);
        Process p3 = new Process(3);
        Process p4 = new Process(4);
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
