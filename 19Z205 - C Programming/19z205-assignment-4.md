# **19Z205 - C Programming**
## Assigment 4
#### *Akash Shanmugaraj on 18th April 2023*

### Question 1: *Create a program to print sequential pyramid of numbers, get the height of the pattern from user*

Importing necessary modules, declaring Initial Variables, getting height from the user 
```c
#include<stdio.h>
void main(){
  int height;
```
Getting the value of height of the pattern from user
```c
  printf("Enter the height of the pattern: ");
  scanf("%d",&height);
```
Looping over from `i = 1` to `i = height` to create pattern
```c
  for(int i=1;i<=height;i++){
     for(int j=height;j>=i;j--){
      printf("\t");
     }
     for(int j=1;j<=i;j++){
       printf("%d\t",j);
     }
     for(int j=i-1;j>=1;j--){
      printf("%d\t",j);
     }
     printf("\n");
  }
  printf("");
}

```


### Question 2: *Create a program to print a range of numbers from `k1` to `k2` for `n` times. Get `k1`, `k2`, `n` as inputs from the user.*

Importing necesary modules, initializing variables
```c
#include<stdio.h>
void main(){
  int rangeStart,rangeEnd,limit,incrementVariable=0;
```

Getting all required inputs from the user
```c
  printf("Enter the start of the range:");
  scanf("%d",&rangeStart);
  
  printf("Enter the end of the range:");
  scanf("%d",&limit);
  
  printf("Enter the limit of execution:");
  scanf("%d",&limit);
```

Looping the program over logic
```c
  while(limit>=incrementVariable){
  
    for(int i=rangeStart;i<=rangeEnd;i++){
    
      printf("%d\n",i);
      incrementVariable++;
      if(incrementVariable==limit){
        goto jump;
      }
    }
  }
```
Declaring the end of the program
```c
  jump:
    printf("End of program.");
}

```