public class Resource {
    int rid; // resource id
    Process assignedto;
    Process waiting;

    public Resource(int rid, Process assignedto, Process waiting){
        this.rid = rid;
        this.assignedto = assignedto;
        this.waiting = waiting;
    }
}