import java.util.*;

class Site {
    int siteID;
    int numberofprocesses;
    ArrayList<ArrayList<Integer>> adjacencyMatrix;

    public Site(int siteID, int numberofprocesses) {
        this.siteID = siteID;
        this.numberofprocesses = numberofprocesses;
        this.adjacencyMatrix = new ArrayList<>();

        // Initialize the matrix with 0s
        for (int i = 0; i < numberofprocesses; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < numberofprocesses; j++) {
                row.add(0);  // Initially, no processes are adjacent
            }
            adjacencyMatrix.add(row);
        }
    }

    public void addEdge(int from, int to) {
        adjacencyMatrix.get(from).set(to, 1);
    }

    public void setadjacencyMatrix(ArrayList<ArrayList<Integer>> adjacencyMatrix) {
        this.adjacencyMatrix = adjacencyMatrix;
    }

    public void detectDeadlock() {
        // visited set
        Set<Integer> visited = new HashSet<>();
        Set<Integer> recStack = new HashSet<>();
        for (int i = 0; i < numberofprocesses; i++) {
            if (detectCycle(i, visited, recStack)) {
                System.out.println("Deadlock detected in site " + siteID);
                return;
            }
        }
        System.out.println("No deadlock detected in site " + siteID);
    }

    private boolean detectCycle(int node, Set<Integer> visited, Set<Integer> recStack) {
        if (recStack.contains(node)) {
            return true;
        }
        if (visited.contains(node)) {
            return false;
        }
        visited.add(node);
        recStack.add(node);
        for (int neighbor = 0; neighbor < numberofprocesses; neighbor++) {
            if (adjacencyMatrix.get(node).get(neighbor) == 1) {
                if (detectCycle(neighbor, visited, recStack)) {
                    return true;
                }
            }
        }
        recStack.remove(node);
        return false;
    }
}

class MasterSystem {
    ArrayList<Site> sites;
    int numberofprocesses;

    public MasterSystem(int numberofprocesses) {
        sites = new ArrayList<>();
        this.numberofprocesses = numberofprocesses;
    }

    public void addSite(Site s) {
        sites.add(s);
    }

    public void detectDeadlock() {
        for (Site s : sites) {
            s.detectDeadlock();
        }
    }

    public void centralizedDeadlockDetection() {
        Site centralsite = new Site(100, numberofprocesses);
        for (Site s : sites) {
            for (int i = 0; i < s.numberofprocesses; i++) {
                for (int j = 0; j < s.numberofprocesses; j++) {
                    if (s.adjacencyMatrix.get(i).get(j) == 1) {
                        centralsite.addEdge(i, j);
                    }
                }
            }
        }
        centralsite.detectDeadlock();
        
    }
}

public class AlsoCentralized {
    public static void main(String[] args) {
        int numberofprocesses = 3;
        MasterSystem ms = new MasterSystem(numberofprocesses);

        Site s1 = new Site(1, numberofprocesses);
        ms.addSite(s1);

        s1.addEdge(0, 1);
        s1.addEdge(1,2);
        
        Site s2 = new Site(2, numberofprocesses);
        ms.addSite(s2);

        s2.addEdge(2, 1);
        s2.addEdge(0, 1);
        
        s1.detectDeadlock();
        s2.detectDeadlock();
        ms.centralizedDeadlockDetection();
    }
}