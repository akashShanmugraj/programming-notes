import java.util.Scanner;

public class experiment5 {
    public static void question1() {
        int[] array = { 1, 2, 3, 4, 5 };
        int sum = 0;
        for (int iterator = 0; iterator < array.length; iterator++) {
            sum += array[iterator];
        }
        System.out.println(sum);
    }

    public static void question2() {
        int[] array = { 1, 2, 3, 4, 5 };
        int maxofarray;
        int minofarray;

        maxofarray = array[0];
        minofarray = array[0];
        for (int iterator = 0; iterator < array.length; iterator++) {
            if (array[iterator] > maxofarray) {
                maxofarray = array[iterator];
            }
            if (array[iterator] < minofarray) {
                minofarray = array[iterator];
            }
        }

        System.out.println(maxofarray + minofarray);
    }

    public static void question3(int[] numberarray, int number) {
        int generalsummation = 0, sumofarray = 0;
        for (int iterator = 1; iterator <= number; iterator++) {
            generalsummation += iterator;
        }
        for (int iterator = 0; iterator < numberarray.length; iterator++) {
            sumofarray += numberarray[iterator];
        }
        System.out.println(generalsummation - sumofarray);
    }

    public static void question4() {
        int[] array;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int numberofelements = scanner.nextInt();
        array = new int[numberofelements];
        System.out.println("Enter the elements of the array (line-by-line): ");
        for (int iterator = 0; iterator < numberofelements; iterator++) {
            array[iterator] = scanner.nextInt();
        }

        int maxoccurringelement = array[0];
        int maxoccurringelementcount = 0;

        for (int iterator = 0; iterator < numberofelements; iterator++) {
            int count = 0;
            for (int iterator2 = 0; iterator2 < numberofelements; iterator2++) {
                if (array[iterator] == array[iterator2]) {
                    count++;
                }
            }
            if (count > maxoccurringelementcount) {
                maxoccurringelementcount = count;
                maxoccurringelement = array[iterator];
            }
        }

        System.out.println("The maximum occurring element is " + maxoccurringelement + " and it occurs "
                + maxoccurringelementcount + " times.");
    }

    public static void question5(int[] array, int element, int position) {
        int[] newarray = new int[array.length + 1];
        for (int iterator = 0; iterator < position; iterator++) {
            newarray[iterator] = array[iterator];
        }
        newarray[position] = element;
        for (int iterator = position + 1; iterator < newarray.length; iterator++) {
            newarray[iterator] = array[iterator - 1];
        }
        for (int iterator = 0; iterator < newarray.length; iterator++) {
            System.out.print(newarray[iterator]);
            System.out.print(" ");
        }
        System.out.println();

    }

    public static void question6(int[][] matrix1, int[][] matrix2) {
        // add two matrices
        int[][] matrix3 = new int[matrix1.length][matrix1[0].length];

        for (int iterator = 0; iterator < matrix1.length; iterator++) {
            for (int iterator2 = 0; iterator2 < matrix1[0].length; iterator2++) {
                matrix3[iterator][iterator2] = matrix1[iterator][iterator2] + matrix2[iterator][iterator2];
            }
        }

        for (int iterator = 0; iterator < matrix3.length; iterator++) {
            for (int iterator2 = 0; iterator2 < matrix3[0].length; iterator2++) {
                System.out.print(matrix3[iterator][iterator2]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        System.out.println("QUES1");
        question1();
        System.out.println("QUES2");
        question2();
        System.out.println("QUES3");
        question3(new int[] { 1, 2, 4, 5 }, 5);
        System.out.println("QUES4");
        question4();
        System.out.println("QUES5");
        question5(new int[] { 1, 2, 3, 4, 5 }, 6, 2);
        System.out.println("QUES6");
        question6(new int[][] { { 1, 2, 3 }, { 4, 5, 6 } }, new int[][] { { 1, 2, 3 }, { 4, 5, 6 } });
    }

}