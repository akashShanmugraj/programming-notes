<p>Experiment 11-A<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">String Handling - 2</h1>


## 1. Convert an array to string:
**AIM:** Write a java program to convert an array to string
```java
import java.util.Arrays;

public class ArrayToString {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        String result = Arrays.toString(array);
        System.out.println(result);
    }
}
```

### Output
```
[1, 2, 3, 4, 5]
```

## 2. Print duplicate characters from the string
**AIM:** To Print duplicate characters from the string
```java
public class DuplicateCharacters {
    public static void main(String[] args) {
        String str = "programming";
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                if (str.charAt(i) == str.charAt(j)) {
                    System.out.println(str.charAt(i));
                    break;
                }
            }
        }
    }
}
```

### Output
```
r
g
```

## 3. Check if two strings are anagrams
**AIM:** To check if two strings are anagrams of each other
```java
import java.util.Arrays;

public class AnagramCheck {
    public static void main(String[] args) {
        String str1 = "listen";
        String str2 = "silent";

        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        boolean areAnagrams = Arrays.equals(arr1, arr2);
        System.out.println("Are the strings anagrams? " + areAnagrams);
    }
}
```

### Output
```
Are the strings anagrams? true
```

## 4. Convert string to integer
**AIM:** To convert string to integer
```java
public class StringToInteger {
    public static void main(String[] args) {
        String str = "123";
        int number = Integer.parseInt(str);
        System.out.println("Converted integer: " + number);
    }
}
```

### Output
```
Converted integer: 123
```

## 5. Count the number of words in a given string sentence
**AIM:** To count the number of words in a given string sentence
```java
public class WordCount {
    public static void main(String[] args) {
        String sentence = "This is a sample sentence.";
        String[] words = sentence.split("\\s+");
        int wordCount = words.length;
        System.out.println("Number of words: " + wordCount);
    }
}
```

### Output
```
Number of words: 5
```

## 6. Arrange each word in alphabetical order
**AIM:** Write a program to get input as a string from user and arrange each word in Alphabetical Order.
```java
import java.util.Arrays;

public class ArrangeWords {
    public static void main(String[] args) {
        String input = "this is a sample sentence";
        String[] words = input.split("\\s+");

        for (String word : words) {
            char[] charArray = word.toCharArray();
            Arrays.sort(charArray);
            System.out.print(new String(charArray) + " ");
        }
    }
}
```

### Output
```
hist is a aelmps ceeennst
```