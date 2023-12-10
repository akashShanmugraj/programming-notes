// import arraylist 

import java.util.ArrayList;

public class experiment13 {
    public static void main(String[] args) {
        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] strArray = {"Hello", "World"};

        // integer arraylist
        ArrayList<Integer> intArrayList = new ArrayList<Integer>();
        intArrayList.add(1);
        intArrayList.add(2);
        intArrayList.add(3);
        intArrayList.add(4);
        intArrayList.add(5);

        // string arraylist
        ArrayList<String> strArrayList = new ArrayList<String>();
        strArrayList.add("Hello");
        strArrayList.add("World");

        printArray(intArray); // This works because Integer is a valid type
        printArray(strArray); // This works because String is a valid type

        printArray(intArrayList); // This doesn't work because ArrayList<Integer> is not an array
        printArray(strArrayList); // This doesn't work because ArrayList<String> is not an array

        printArray(123); // This doesn't work because 123 is not an array
    }

    public static <ba> void printArray(ba inputArray) {
        System.out.println(inputArray);
        System.out.println(inputArray.getClass().getSimpleName());
        System.out.println();
    }
}