# Packages in Java

## 16th October 2023

A set of classes and interfaces grouped together are known as `Packages` in Java

## Benefits

- Organize grioup of classes into single API Unit
- auto control naming conflicts
- easy access protection
- 2 access levels: Protected, Default

Java Package
Subpackage
Class units

Other 2 major types: BuiltIn , UserDefined

`Java.awt.event`:

- Java: Package
- awt: sub package
- event: class

## BuiltIn

come along with JDK
use import statement

```java
package Example;
import java.util.ArrayList;

class buildinpackage{
    psvm{
        // define array, insert elements, print array
    }
}
```

### How to access package from another package?

1. `import package.*` (available for both BI and UD)
2. `import package.classname`
3. some fully qualified name, without `import`

fully qualified like:

```java
class myarray implements java.util.ArrayList{
    // something
}
```

makes only the declared class of the package accessible
adv  when two packages have same class name

## Creating a Package

- use package command as the starting statement, like `package Example`
- further define all necessary classes

creating a class inside a package while importing another package is also valid

to define a subpackage, modify package command acc, like
`package ExamplePackage.multiply`

Private Package: can only access private modifier within the package
Protected Package: can only access directly from the class and thru classes from child class. They make use of the `inheritance` concept

Public: can be accessed anywhere (within class and outside class)

|Access Modifier|Access in Class|Access in Package|Access outside package using subclass|Access directly outside class|
|--|--|--|--|--|
|Private|Y|N|N|N|
|Default|Y|Y|N|N|
|Protected|Y|Y|Y|N|
|Public|Y|Y|Y|Y|
