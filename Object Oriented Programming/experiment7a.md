<p>Experiment 7A<p>

<p align = 'right'>Rollnumber: 22z255</p>

<p align = 'right'>Date:________________</p>

<h1 align="center">Method Overloading</h1>

### 1. Method overloading by changing the number of arguments
**AIM: Create two methods, the first method sum() will perform addition of two numbers and second method sum() will perform addition of three numbers by overloading concept.**

```java
public int sum(int a, int b) {
    System.out.println("Method with 2 integer parameters");
    return a + b;
}

public int sum(int a, int b, int c) {
    System.out.println("Method with 3 integer parameters");
    return a + b + c;
}

public int sum(int a, int b, int c, int d) {
    System.out.println("Method with 4 integer parameters");
    return a + b + c + d;
}
```
### 2. Method overloading by changing data type of parameters
**AIM: Create two methods having the same name but will differ in the data type of parameters. The first method sub() will receive two integer arguments and the second method sub() will receive two double arguments. **

```java
public int sub(int a, int b) {
    System.out.println("Method with 2 integer parameters");
    return a - b;
}

public double sub(double a, double b) {
    System.out.println("Method with 2 double parameters");
    return a - b;
}

public float sub(float a, float b) {
    System.out.println("Method with 2 float parameters");
    return a - b;
}
```


### 3. Method overloading by changing sequence of data type of parameters
**AIM: The method multiply() must be overloaded based on the sequence of data type of parameters. The overloaded methods have to calculate multiplication of two numbers based on the sequence of argument types while calling methods at runtime**

```java
public int multiply(int a, double b) {
    System.out.println("Method with first integer and second double parameters");
    return a * (int)b;
}

public int multiply(double a, int b) {
    System.out.println("Method with first double and second integer parameters");
    return (int)a * b;
}

public double multiply(double a, double b) {
    System.out.println("Method with two double parameters");
    return a * b;
}
```

### Driver Code
```java
public static void main(String[] args) {
    experiment7 obj = new experiment7();
    
    System.out.println(obj.sum(1, 2));
    System.out.println(obj.sum(1, 2, 3));    
    System.out.println(obj.sum(1, 2, 3, 4));
    
    System.out.println(obj.sub(1, 2));
    System.out.println(obj.sub(1.0, 2.0));    
    System.out.println(obj.sub(1.0f, 2.0f));
    
    System.out.println(obj.multiply(1, 2.0));
    System.out.println(obj.multiply(1.0, 2));
    System.out.println(obj.multiply(1.0, 2.0));
}
```
### Output
```
Method with 2 integer parameters
3
Method with 3 integer parameters
6
Method with 4 integer parameters
10
Method with 2 integer parameters
-1
Method with 2 double parameters
-1.0
Method with 2 float parameters
-1.0
Method with first integer and second double parameters
2
Method with first double and second integer parameters
2
Method with two double parameters
2.0
```