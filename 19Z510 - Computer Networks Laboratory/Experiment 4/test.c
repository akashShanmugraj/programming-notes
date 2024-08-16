#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getfield(char* line, int num);

int main()
{   
    char * key = "www.google.com";
    char * value = malloc(1024);
    strcpy(value, "IP address not found");
    char* comparekey = malloc(1024);

    char filename[] = "data.txt";
    printf("Opening file %s\n", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s\n", line);
        sscanf(line, "%s %s", comparekey, value);
        if (strcmp(comparekey, key) == 0)
        {
            break;
        }
    }
    
    fclose(file);
    printf("%s\n", value);
    free(value);
    return 0;
}

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}