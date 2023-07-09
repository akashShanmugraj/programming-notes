### Write a program in C to sort the lines of a text file in alphabetical order.
```c
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char str[100][100], temp[100];
    int i = 0, j = 0, k, n = 0;

    fp = fopen("sample.txt", "r");

    while (fgets(str[n], 100, fp) != NULL)
    {
        n++;
    }


    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nFile after sorting :\n\n");

    for (i = 0; i <= n; i++)
    {
        printf("%s", str[i]);
    }

    fclose(fp);

    return 0;
}
```
### Write a program in C to encrypt the contents of a file using a simple encryption algorithm

```c
#include <stdio.h>
#include <stdlib.h>

char encrypt(char object, int key){
    return object + key;
}

int main()
{
    FILE *filepointer;
    char ch;
    int i = 0;
    int encryption_key = 43;
    filepointer = fopen("sample.txt", "r+");
    if (filepointer == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    while ((ch = fgetc(filepointer)) != EOF)
    {
        fseek(filepointer, i, SEEK_SET);
        fputc(encrypt(ch, encryption_key), filepointer);
        i++;
    }
    fclose(filepointer);
    filepointer = fopen("sample.txt", "r");
    printf("\nEncrypted Content:\n");
    while ((ch = fgetc(filepointer)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(filepointer);
    return 0;
}
```
### Write a program in C to calculate the average of numbers stored in a file.

_Assuming file contains a set of integers, each written on a separate line, with first line containing._

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filepointer;
    int n, i, num;
    float sum = 0, avg;

    filepointer = fopen("sample.txt", "r");

    if (filepointer == NULL)
    {
        printf("Error opening file\n");
    }

    fscanf(filepointer, "%d", &n);
    printf("Number of elements = %d\n", n);

    for (i = 0; i < n; i++)
    {
        fscanf(filepointer, "%d", &num);
        sum += num;
    }

    printf("Average = %f\n", sum / n);

    fclose(filepointer);

    return 0;
}
```