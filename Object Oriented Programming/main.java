import java.util.*;

public class Main {
    public static <T extends Comparable<T>> T returnelement(T int1, T int2, T int3) {
        T max = int1;
        if (int2.compareTo(max) > 0) {
            max = int2;
        }
        if (int3.compareTo(max) > 0) {
            max = int3;
        }
        return max;
    }
    public static void main(String[] args) {
        System.out.println(returnelement(12,3,14));

        ArrayList al1 = new ArrayList();
        al1.add(100);
        al1.add("AADS");
        al1.get(1);

        System.out.println(al1);

        ArrayList<Integer> integerarraylist = new ArrayList<Integer>();
        integerarraylist.add(100);
        integerarraylist.add(200);
        integerarraylist.add(1);

        System.out.println(integerarraylist);

        integerarraylist.remove(1);

        System.out.println(integerarraylist);

        integerarraylist.remove(1);

        System.out.println(integerarraylist);

        System.out.println("Linked List");
        LinkedList linkedlist1 = new LinkedList();

        linkedlist1.add(100);
        linkedlist1.add("one");

        linkedlist1.addAll(integerarraylist);

        System.out.println(linkedlist1);

        System.out.println("PRQ");

        PriorityQueue<Integer> prqueue = new PriorityQueue<Integer>();

        prqueue.offer(50);
        prqueue.offer(25);
        prqueue.offer(75);

        Object[] array = prqueue.toArray();
        for (Object element : array) {
            System.out.println(element);
        }

        for (Object node : prqueue) {
            System.out.println("P"+node);
        }
    }

    

}
