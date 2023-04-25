# 19Z205 - C Programming 
## Assignment 2
#### *Akash Shanmugaraj on 28th March 2023*

Following piece of program depicts the way to convert celsius temperature to farenheit.

```c
#include <stdio.h>

#include <stdio.h>

int main() {
    double temperature_c, temperature_f;
    printf("Enter the Temperature in Celsius:");
    scanf("%lf", &temperature_c);
    temperature_f = (temperature_c * 1.8) + 32;
    printf("The equivalent temperature in farenheit is %lf", temperature_f);

}
```

Using `%lg` and `%g` as a format specifier expresses the output in scientific notation (only the significant digits). 

It is an alternative to `%lf` and `%f`. 

The following code log numbers from 1 to 6 onto the console.

```c
#include <stdio.h>

int main() {
    int loopvariable;
    
    for (loopvariable = 1; loopvariable < 7; loopvariable++) {
        printf("The iterated value in the loop is %d\n", loopvariable);
    }
}
```


The following code computes the multiples of 3 iteratively.

```c
#include <stdio.h>

int main() {
    int loopVariable;
    for (loopVariable = 3; loopVariable < 61; loopVariable += 3) {
        printf("Iterated value is %d \n", loopVariable);
    }
}

```

The following code computes exponents of 2 from 1 to 100.

```c
#include <stdio.h>
#include <math.h>
int main() {
    int loopVariable;
    double exponent; 
    for (loopVariable = 1; loopVariable < 101; loopVariable ++) {
        exponent = pow(2, loopVariable);
        printf("2 ^ %d is computed as %lf \n", loopVariable, exponent);
    }
}
```

The following code is a similar adaptation of the above code, to compute exponents of 9.

```c
#include <stdio.h>
#include <math.h>
int main() {
    int loopVariable;
    double exponent; 
    for (loopVariable = 1; loopVariable < 101; loopVariable ++) {
        exponent = pow(9, loopVariable);
        printf("9 ^ %d is computed as %lf \n", loopVariable, exponent);
    }
}

```

The following is a program to analyze the bytes allocated for a datatype.

```c
#include <stdio.h>

int main() {
    int integerVariable;
    float floatVariable;
    char characterVariable;
    double doubleVariable;
    char stringVariable[100];
    long double longDoubleVariable; 
    
    printf("Size of an integer variable: %d bytes\n", sizeof(integerVariable));
    printf("Size of a float variable: %d bytes\n", sizeof(floatVariable));
    printf("Size of character variable: %d bytes\n", sizeof(characterVariable));
    printf("Size of double variable: %d bytes\n", sizeof(doubleVariable));
    printf("Size of string variable (defined to 100bytes): %d bytes\n", sizeof(stringVariable));
    printf("Size of long double variable: %d bytes\n", sizeof(longDoubleVariable));


    return 0;
}
```

The output of the above program is as follows

```
Size of an integer variable: 4 bytes
Size of a float variable: 4 bytes
Size of character variable: 1 bytes
Size of double variable: 8 bytes
Size of string variable (defined to 100bytes): 100 bytes
Size of long double variable: 16 bytes
```

Below is a more sophisticated method to fetch memory allocated for all datatypes.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Number of bytes allocated for 'char' (CHAR_BIT)                     :   %d\n", CHAR_BIT);
    printf("Maximum number of bytes allocated for 'char' (CHAR_MAX)             :   %d\n", CHAR_MAX);
    printf("Minimum number of bytes allocated for 'char' (CHAR_MIN)             :   %d\n", CHAR_MIN);
    printf("Maximum number of bytes allocated for 'int' (INT_MAX)               :   %d\n", INT_MAX);
    printf("Minimum number of bytes allocated for 'int' (INT_MIN)               :   %d\n", INT_MIN);
    printf("Maximum number of bytes allocated for 'long' (LONG_MAX)             :   %ld\n", (long) LONG_MAX);
    printf("Minimum number of bytes allocated for 'long' (LONG_MIN)             :   %ld\n", (long) LONG_MIN);
    printf("Maximum number of bytes allocated for 'unsigned char' (UCHAR_MAX)   :   %d\n", UCHAR_MAX);
    printf("Maximum number of bytes allocated for 'unsigned int' (UINT_MAX)     :   %u\n", (unsigned int) UINT_MAX);
    printf("Maximum number of bytes allocated for 'unsigned long' (ULONG_MAX)   :   %lu\n", (unsigned long) ULONG_MAX);


    return 0;
}
```

Output of the following code is as follows:

```
Number of bytes allocated for 'char' (CHAR_BIT)                     :   8
Maximum number of bytes allocated for 'char' (CHAR_MAX)             :   127
Minimum number of bytes allocated for 'char' (CHAR_MIN)             :   -128
Maximum number of bytes allocated for 'int' (INT_MAX)               :   2147483647
Minimum number of bytes allocated for 'int' (INT_MIN)               :   -2147483648
Maximum number of bytes allocated for 'long' (LONG_MAX)             :   2147483647
Minimum number of bytes allocated for 'long' (LONG_MIN)             :   -2147483648
Maximum number of bytes allocated for 'unsigned char' (UCHAR_MAX)   :   255
Maximum number of bytes allocated for 'unsigned int' (UINT_MAX)     :   4294967295
Maximum number of bytes allocated for 'unsigned long' (ULONG_MAX)   :   4294967295
```


## Datatypes in C

The datatypes in C are as follows.
| Data type   | Format Specifier | Size in bytes                                                   | Range                                  | Default          |
|-------------|------------------|-----------------------------------------------------------------|----------------------------------------|------------------|
| `char`        | `%c`               | 1                                                               | *1 character in local character set*     |        nil       |
| `int`         | `%d, %i`           | 4(at least 2) Natural size of integers in host machine          | *-2^31 to 2^31*                          | signed           |
| `float`       | `%f`               | 4                                                               | *3×10³⁸ and about as small as 1.4×10⁻⁴⁵* | Sinle precision  |
| `double`      | `%lf`              | 8                                                               | *2.3E-308 to 1.7E+308*                   | Double precision |
| `long double` | `%Lf`              | at least 10, usually 12 or 16 Extended precision floating point | *3.4E-4932 to 1.1E+4932*                 | long double      |

### Signed and Unsigned Integers

| Data type              | Format Specifier | Size in bytes         | Range                  | Default |
|------------------------|------------------|-----------------------|------------------------|---------|
| short int              | %hd              | 2 usually             | *3.4E-4932 to 1.1E+4932* | 0       |
| unsigned int           | %u               | at least 2, usually 4 | *0 to 4.2E+9*            | 16      |
| long int               | %ld, %li         | at least 4, usually 8 | *-2.1E+11 to 2.1E11*     | 0       |
| long long int          | %lld, %lli       | at least 8            | *-9.2E+18 to 9.2E+18*    | 79      |
| unsigned long int      | %lu              | at least 4            | *0 to 4.2E+9*            | 0       |
| unsigned long long int | %llu             | at least 8            | *0 to 1.8E+19*           | 4199705 |

### Signed and Unsigned Character Types

| Data type     | Format Specifier | Size in bytes | Range                       |
|---------------|------------------|---------------|-----------------------------|
| signed char   | %c               | 1             | *-128 to 127 -2^7 to (2^7-1)* |
| unsigned char | %c               | 1             | *0 to 255 0 to 2^8* |
