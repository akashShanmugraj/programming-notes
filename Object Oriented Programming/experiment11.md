<p>Experiment 11<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">String Handling</h1>

## Aim of Experiment:
To implement various string functions that perform **Character Extraction**, **Comparision**, **Searching**, **Modifying**, **Data Conversion** and **String Buffer**

### 1. String Concatenation

```java
String str1 = "Hello";
String str2 = "World";
String str3 = str1 + str2;
System.out.println(str3);
```

Output:

```
HelloWorld
```

### 2. String Concatenation with other Data Types

```java
String str4 = "Hello";
int num = 123;
String str5 = str4 + num;
System.out.println(str5);
```

Output:

```
Hello123
```

### 3. String Conversion and `toString()` method

```java
int num1 = 123;
String str6 = String.valueOf(num1);
System.out.println(str6);

```

Output:

```
123
```

### 4. Character Extraction

`charAt()` method example
```java
String str7 = "Hello";
char ch = str7.charAt(0);
System.out.println(ch);
```

Output:

```
H
```

`getChars()` method example

```java
String str8 = "Hello";
char[] ch1 = new char[10];
str8.getChars(0, 3, ch1, 0);
System.out.println(ch1);
```

Output:

```
Hel
```

`getBytes()` method example

```java
String str9 = "Hello";
byte[] b = str9.getBytes();
for (int i = 0; i < b.length; i++) {
    System.out.println(b[i]);
}
```

Output:


```
72
101
108
108
111
```

`toCharArray()` method example

```java
String str10 = "Hello";
char[] ch2 = str10.toCharArray();
for (int i = 0; i < ch2.length; i++) {
    System.out.println(ch2[i]);
}

```

Output:


```
H
e
l
l
o
```
### 5. String Comparison

`equals()` and `equalsIgnoreCase()` method example

```java
String str11 = "Hello";
String str12 = "Hello";
String str13 = "hello";
System.out.println(str11.equals(str12));
System.out.println(str11.equals(str13));
System.out.println(str11.equalsIgnoreCase(str13));

```

Output:

```
true
false
true
```

`regionMatches()` method example

```java
String str14 = "Hello";
String str15 = "Hello World";
System.out.println(str14.regionMatches(0, str15, 0, 5));
System.out.println(str14.regionMatches(0, str15, 6, 5));

```

Output:

``` 
true
false
```

`startsWith()` and `endsWith()` method example

```java
String str16 = "Hello";
System.out.println(str16.startsWith("He"));
System.out.println(str16.endsWith("lo"));
```

Output:

```
true
true
```
`equals()` and `==` operator example

```java
String str17 = "Hello";
String str18 = "Hello";
String str19 = new String("Hello");
System.out.println(str17 == str18);
System.out.println(str17 == str19);
System.out.println(str17.equals(str18));
```

Output:


```
true
false
true
```
`compareTo()` method example

```java
String str20 = "Hello";
String str21 = "Hello";
String str22 = "hello";
System.out.println(str20.compareTo(str21));
System.out.println(str20.compareTo(str22));
System.out.println(str22.compareTo(str20));

```

Output:


```
0
-32
32
```
### 6. Searching Strings

```java
String str23 = "Hello World";
System.out.println(str23.indexOf('o'));
System.out.println(str23.indexOf('o', 5));
System.out.println(str23.lastIndexOf('o'));
System.out.println(str23.lastIndexOf('o', 5));

```

Output:


```
4
7
7
4
```
### 7. Modifying Strings

`substring()` method example

```java
String str24 = "Hello World";
System.out.println(str24.substring(6));
System.out.println(str24.substring(0, 5));

```

Output:


```
World
Hello
```
`concat()` method example

```java
String str25 = "Hello";
String str26 = "World";
System.out.println(str25.concat(str26));

```

Output:


```
HelloWorld
```

`replace()` method example

```java
String str27 = "Hello World";
System.out.println(str27.replace('l', 'p'));
System.out.println(str27.replace("Hello", "Hi"));

```

Output:


```
Heppo Worpd
Hi World
```
`trim()` method example

```java
String str28 = "   Hello World   ";
System.out.println(str28.trim());

```

Output:


```
Hello World
```
### 8.Data conversion using `valueOf()` method

```java
int num2 = 123;
String str29 = String.valueOf(num2);
System.out.println(str29);

```

Output:


```
123
```

### 9.Changing the case of characters within a string

```java
String str30 = "Hello World";
System.out.println(str30.toUpperCase());
System.out.println(str30.toLowerCase());

```

Output:


```
HELLO WORLD
hello world
```
### 10.String Buffer Class

```java
StringBuffer sb1 = new StringBuffer();
StringBuffer sb2 = new StringBuffer(50);
StringBuffer sb3 = new StringBuffer("Hello World");
System.out.println(sb1.capacity());
System.out.println(sb2.capacity());
System.out.println(sb3.capacity());

```

Output:


```
16
50
27
```
Length and Capacity

```java
StringBuffer sb4 = new StringBuffer("Hello World");
System.out.println(sb4.length());
System.out.println(sb4.capacity());

```

Output:


```
11
27
```
`ensureCapacity()` method

```java
StringBuffer sb5 = new StringBuffer();
System.out.println(sb5.capacity());
sb5.ensureCapacity(50);
System.out.println(sb5.capacity());

```

Output:


```
16
50
```
`setLength()` method

```java
StringBuffer sb6 = new StringBuffer("Hello World");
System.out.println(sb6.length());
sb6.setLength(5);
System.out.println(sb6.length());

```

Output:


```
11
5
```
`charAt()` and `setCharAt()` method

```java
StringBuffer sb7 = new StringBuffer("Hello World");
System.out.println(sb7.charAt(0));
sb7.setCharAt(0, 'M');
System.out.println(sb7.charAt(0));

```

Output:


```
H
M
```
`getChars()` method

```java
StringBuffer sb8 = new StringBuffer("Hello World");
char[] ch3 = new char[10];
sb8.getChars(0, 5, ch3, 0);
System.out.println(ch3);

```

Output:


```
Hello
```

`append()` method

```java
StringBuffer sb9 = new StringBuffer("Hello");
sb9.append(" World");
System.out.println(sb9);
```

Output:


```
Hello World
```
`insert()` method

```java
StringBuffer sb10 = new StringBuffer("Hello World");
sb10.insert(5, " ");
System.out.println(sb10);
```

Output:


```
Hello  World
```
`reverse()` method

```java
StringBuffer sb11 = new StringBuffer("Hello World");
sb11.reverse();
System.out.println(sb11);

```

Output:


```
dlroW olleH
```

`delete()` and `deleteCharAt()` method

```java
StringBuffer sb12 = new StringBuffer("Hello World");
sb12.delete(5, 11);
System.out.println(sb12);
sb12.deleteCharAt(0);
System.out.println(sb12);

```

Output:


```
Hello
ello
```
`replace()` method

```java
StringBuffer sb13 = new StringBuffer("Hello World");
sb13.replace(5, 11, " ");
System.out.println(sb13);
```

Output:


```
Hello 
```
`substring()` method

```java
StringBuffer sb14 = new StringBuffer("Hello World");
System.out.println(sb14.substring(6));

```

Output:


```
World
```