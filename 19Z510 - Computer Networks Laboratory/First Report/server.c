// server code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

void callpythonfunction(char* targetword, char* guess, int chancesleft, char* guessstate, char* outputstore) {
    char command[2048];
    snprintf(command, sizeof(command), "python3 logic.py %s %s %d %s > output.txt ", targetword, guess, chancesleft, guessstate);
    // printf("%s\n", command);
    system(command);
    FILE *f = fopen("output.txt", "r");
    if (f == NULL) {
        printf("Error! File not found\n");
        exit(1);
    }
    fgets(outputstore, 1024, f);
    fclose(f);
}

int main()
{
    // Variables and structures
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    char *targetword = "NETWORKING";
    char guesshistory[1024] = "?";
    char *history = guesshistory;
    char outputstore[1024];
    char *output = outputstore;
    int turnsleft = 5;
    char* dummyptr = malloc(1024);
    char* status = malloc(1024);

    // Server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    printf("[LISTENING] Port Number: %d\n", PORT);

    while (1)
    {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
        
        printf("%s\n", buffer);
        // Send initial message to the client
        strcpy(buffer, "Hello, welcome to the game of Hangman!\nGood luck!\nthe output is formatted as below:\n\nStatus of Guess - Game State - Number of turns left\n\n");
        send(client_fd, buffer, strlen(buffer), 0);
        
        while (1)
        {
            // Clear the buffer
            memset(buffer, '\0', sizeof(buffer));

            // Receive message from the client
            int recv_len = recv(client_fd, buffer, 1024, 0);
            if (recv_len <= 0)
            {
                printf("Connection closed by client\n");
                break;
            }

            callpythonfunction(targetword, buffer, turnsleft, history, output);
            
            sscanf(output, "%s", status);

            if (strcmp(status, "Done") == 0) {
                strcpy(output, "Congratulations! You have won the game!\n");
                int send_result = send(client_fd, output, strlen(output), 0);
                if (send_result == -1) {
                    perror("send");
                } else {
                    printf("Sent: %s\n", output);
                }
                break;
            }
            sscanf(output, "%*s %s", history);

            sscanf(output, "%*s %*s %s", dummyptr);
            turnsleft = atoi(dummyptr);

            // Send response to the client
            send(client_fd, output, strlen(output), 0);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}