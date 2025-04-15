import java.util.PriorityQueue;
import java.util.Comparator;

class Node {
    int val;
    public Node(int val){
        this.val = val;
    }
}

public class test {
    public static void main(String[] args) {
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(
            Comparator.comparing((Node n) -> n.val)
        );

        Node n1 = new Node(11);
        Node n2 = new Node(102);
        Node n3 = new Node(14);

        priorityQueue.offer(n1);
        priorityQueue.offer(n2);
        priorityQueue.offer(n3);
        
        System.out.println(priorityQueue.peek().val);
    }
    
}