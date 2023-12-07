<p>Experiment 13<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Collections and Framework</h1>


## 1. ArrayList Operations:
**AIM**: Write a Java Program to create an array list. Add some colors and do the following
operations:

i) Insert an element at the first position.

ii) Delete the third element.

iii) Search for “Red” color.

iv) Sort the array list.

v) Update the fourth element with “Yellow”

```java
import java.util.ArrayList;
import java.util.Collections;

public class ArrayListOperations {
    public static void main(String[] args) {
        // Create ArrayList
        ArrayList<String> colors = new ArrayList<>();

        // Add some colors
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");

        // i) Insert an element at the first position
        colors.add(0, "Purple");

        // ii) Delete the third element
        colors.remove(2);

        // iii) Search for “Red” color
        int indexOfRed = colors.indexOf("Red");
        System.out.println("Index of 'Red': " + indexOfRed);

        // iv) Sort the array list
        Collections.sort(colors);

        // v) Update the fourth element with “Yellow”
        colors.set(3, "Yellow");

        // Display the modified ArrayList
        System.out.println("Modified ArrayList: " + colors);
    }
}
```

### Output
```
Index of 'Red': 2
Modified ArrayList: [Green, Purple, Red, Yellow]
```


## 2. LinkedList Operations:

**AIM**: Write a Java program to create a linked list. 
Add some names of animals and do the
following operations:

i) Insert “cat” at third position.

ii) Remove the first and last elements.

iii) Check if the animal “dog” exists in the linked list.

iv) Replace the second element with “Elephant”

v) Display the elements and their positions.

```java
import java.util.LinkedList;

public class LinkedListOperations {
    public static void main(String[] args) {
        // Create LinkedList
        LinkedList<String> animals = new LinkedList<>();

        // Add some names of animals
        animals.add("Lion");
        animals.add("Tiger");
        animals.add("Bear");

        // i) Insert “cat” at third position
        animals.add(2, "Cat");

        // ii) Remove the first and last elements
        animals.removeFirst();
        animals.removeLast();

        // iii) Check if the animal “dog” exists in the linked list
        boolean containsDog = animals.contains("Dog");
        System.out.println("Contains 'Dog': " + containsDog);

        // iv) Replace the second element with “Elephant”
        animals.set(1, "Elephant");

        // v) Display the elements and their positions
        for (int i = 0; i < animals.size(); i++) {
            System.out.println("Element: " + animals.get(i) + ", Position: " + i);
        }
    }
}
```

### Output
```
Contains 'Dog': false
Element: Tiger, Position: 0
Element: Elephant, Position: 1
```

## 3. PriorityQueue Operations:

**AIM**: Write a Java Program to create a Priority queue.
Add some subject names and do the
following operations:

i) Insert the subject “Mathematics” into the priority queue.

ii) Iterate through all the elements.

iii) Count the number of elements in the priority queue.

iv) Retrieve the first element.

v) Add all the elements of the Priority queue to another Priority queue.

```java
import java.util.PriorityQueue;

public class PriorityQueueOperations {
    public static void main(String[] args) {
        // Create PriorityQueue
        PriorityQueue<String> subjects = new PriorityQueue<>();

        // Add some subject names
        subjects.add("Physics");
        subjects.add("Chemistry");
        subjects.add("Biology");

        // i) Insert the subject “Mathematics” into the priority queue
        subjects.offer("Mathematics");

        // ii) Iterate through all the elements
        System.out.println("PriorityQueue elements:");
        for (String subject : subjects) {
            System.out.println(subject);
        }

        // iii) Count the number of elements in the priority queue
        int numberOfElements = subjects.size();
        System.out.println("Number of elements: " + numberOfElements);

        // iv) Retrieve the first element
        String firstElement = subjects.peek();
        System.out.println("First element: " + firstElement);

        // v) Add all the elements of the PriorityQueue to another PriorityQueue
        PriorityQueue<String> anotherPriorityQueue = new PriorityQueue<>(subjects);

        // Display the elements of the second PriorityQueue
        System.out.println("Second PriorityQueue elements:");
        for (String subject : anotherPriorityQueue) {
            System.out.println(subject);
        }
    }
}
```

### Output
```
PriorityQueue elements:
Biology
Chemistry
Physics
Mathematics
Number of elements: 4
First element: Biology
Second PriorityQueue elements:
Biology
Chemistry
Physics
Mathematics
```