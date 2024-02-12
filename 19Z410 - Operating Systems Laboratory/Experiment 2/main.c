#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listDirectoryContents(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL)
    {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

char *get_current_dir()
{
    char *buffer;
    long size;

    size = pathconf(".", _PC_PATH_MAX);

    if ((buffer = (char *)malloc((size_t)size)) != NULL)
    {
        return getcwd(buffer, (size_t)size);
    }

    return NULL;
}

void singleinput(char *prefixstring, char *string1)
{
    printf("$ %s ", prefixstring);
    scanf("%s", string1);
}

int main()
{
    // Allocate memory for command and prefix
    char *prefix = malloc(256 * sizeof(char));
    char *command = malloc(256 * sizeof(char));

    while (1)
    {
        singleinput(prefix, command);

        if (strcmp(command, "ls") == 0)
        {
            listDirectoryContents(get_current_dir());
        }
        if (strcmp(command, "pwd") == 0)
        {
            printf("%s\n", get_current_dir());
        }
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        if (strcmp(command, "cd") == 0)
        {
            singleinput(prefix, prefix);
            // chdir(suffix);
        }
    }

    // Free the allocated memory
    free(prefix);
    free(command);

    printf("Hello");

    return 0;
}