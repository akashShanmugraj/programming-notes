<p>Experiment 12<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">IO Stream</h1>

## 1. Read Characters from Console:
**AIM:** Write a Java program for reading characters from the console

```java
import java.io.IOException;

public class ConsoleReader {
    public static void main(String[] args) throws IOException {
        System.out.print("Enter a character: ");
        int charCode = System.in.read();
        char inputChar = (char) charCode;
        System.out.println("You entered: " + inputChar);
    }
}
```

### Output
    
```sudo
Enter a character: a
You entered: a
```

## 2. Read String from Console using BufferedReader:
**AIM:** Write a Java program to Read a string from console using a BufferReader

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ConsoleStringReader {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a string: ");
        String inputString = reader.readLine();
        System.out.println("You entered: " + inputString);
    }
}
```

### Output

```sudo
Enter a string: Hello, World!
You entered: Hello, World!
```

## 3. Demonstrate the use of `write()` for Console Output:
**AIM:** Demonstrate the use of  write() to perform console output


```java
public class ConsoleWriteDemo {
    public static void main(String[] args) {
        System.out.write('H');
        System.out.write('i');
        System.out.write('\n');
    }
}
```

### Output

```sudo
Hi
```

## 4. Usage of PrintWriter for Console Output:
**AIM:** Illustrate the usage  if  PrintWriter to handle console output


```java
import java.io.PrintWriter;

public class PrintWriterDemo {
    public static void main(String[] args) {
        PrintWriter writer = new PrintWriter(System.out);
        writer.println("Hello, PrintWriter!");
        writer.flush();
    }
}
```

### Output

```sudo
Hello, PrintWriter!
```

## 5. Read and Display Contents of a File:
**AIM:** Write a Java program to copy a file called SOURCE.TXT to a file called DESTINATION.TXT


```java
import java.io.FileReader;
import java.io.IOException;

public class FileReadDemo {
    public static void main(String[] args) throws IOException {
        FileReader fileReader = new FileReader("example.txt");
        int data;
        while ((data = fileReader.read()) != -1) {
            System.out.print((char) data);
        }
        fileReader.close();
    }
}
```

### Output

```sudo
Hello, World!
```

## 6. Copy File SOURCE.TXT to DESTINATION.TXT:
**AIM:** Write a Java program to copy a file called SOURCE.TXT to a file called DESTINATION.TXT


```java
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileCopyDemo {
    public static void main(String[] args) throws IOException {
        FileReader sourceReader = new FileReader("SOURCE.TXT");
        FileWriter destinationWriter = new FileWriter("DESTINATION.TXT");

        int data;
        while ((data = sourceReader.read()) != -1) {
            destinationWriter.write(data);
        }

        sourceReader.close();
        destinationWriter.close();
    }
}
```

### Output

```sudo
Hello, World!
```

## 7. Managing File Resources with Automatic Resource Management (ARM):
**AIM:** State how you can manage File resources by automating
the closing process through Automatic Resource
Management (ARM) feature.

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class AutoCloseableDemo {
    public static void main(String[] args) {
        // Using try-with-resources to automatically close the resources
        try (
            FileReader fileReader = new FileReader("example.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader)
        ) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

### Output

```sudo
Hello, World!
```
