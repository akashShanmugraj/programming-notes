# C Programming
### *19Z205 - C Programming* 

#### 20.03.2023

## General
1. Some datatypes are `char`, `int`, `double`

2. `printf()` is used for printing something onto the console, which is function from the library `stdio.h`

3. Import packages onto the file by `#include <package-name>`. 

4. Formatting values into a string changes based on the type of value. For Example, 
    - `%s` for strings 
    - `%d` for integers
    - `%f` for double/float
    - `%c` for characters

5. A string must be enclosed by double quotes (`"<string>"`) and characters (*single length strings*) must be enclosed by single quotes (`'<character>'`)

6. Character Declarations:
    - String: `char name[] = "Akash Shanmugaraj"`
    - Character: `char grade = 'A"`

7. Continuous string formatting is supported   
    - `printf("Your name is %s, Your age is %d", name, age)`

8. Mathematical Operations are supported directly as arguments of `printf`
    - `printf("%d", 5+4)`

9. Anything and Everything (*including variables and expressions*) in C can only be logged onto the console with string formatting

10. Single like comments can be used by `//`

11. Multiline comments are as follows
    
    ```
    /* Multi
     * Line
     * Comments
     * can be used
     * DOCSTRING*/
    ```

12. Variables with a `const` keyword at the time of delcaration cannot be modified later

13. `<variable-name>++` operator is used to increment the passed variable

## Mathematical Functions
#### *make sure to `#include <math.h>`*

Some supported basic Mathematical functions from `math.h` are:
    
    int poweringFunction = pow(2,3);
    double squareRoot = sqrt(2);
    int floorFunction = floor(23.21);
    int ceilFunction = ceil(23.21); 


## I/O functions
#### 21.03.2023

1. The function `scanf(<formatted-string>, <parameters>**)` is used for getting input in C

2. Rules for `<formatted-string>` are as follows
    - `%c` for Characters
    - `%s` for Continuous Characters or Strings
    - `%d` for Integers
    - `%lf` for Double or Float

3. `<parameters>` of the datatype int, double and char must have a preceeding ampersand (`&`), like '*&< variable-name >*'
