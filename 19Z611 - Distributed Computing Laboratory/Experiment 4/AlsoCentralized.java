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
    
    public boolean detectCycle(int start, Set<Integer> visited) {
        // find who start is waiting for
        // find who that who is waiting for
        // go on until you realise you are the problem

        visited.add(start);
        for (int i = 0; i < numberofprocesses; i++) {
            if (adjacencyMatrix.get(start).get(i) == 1) {
                if (visited.contains(i)) {
                    return true;
                }
                if (detectCycle(i, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public void detectDeadlock() {
        // visited set
        Set<Integer> visited = new HashSet<>();
        for (int i = 0; i < numberofprocesses; i++) {
            if (!visited.contains(i)) {
                if (detectCycle(i, visited)) {
                    System.out.println("Deadlock detected in site " + siteID);
                    return;
                }
            }
        }
        
    }
}

public class AlsoCentralized {
    public static void main(String[] args) {
        Site s1 = new Site(1, 4);
        s1.addEdge(0, 2);
        s1.addEdge(1,3);
        s1.addEdge(2, 1);
        // s1.addEdge(0, 3);
        
        s1.detectDeadlock();
    }
}