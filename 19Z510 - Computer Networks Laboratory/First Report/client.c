// client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

int main()
{
    // Variables and structures
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char clientname[1024];
    char* status = malloc(1024);

    printf("Enter your name: ");
    scanf("%s", clientname);
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection failed\n");
        return -1;
    }

    while (1)
    {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive message from the server
        if (recv(client_fd, buffer, sizeof(buffer), 0) <= 0)
        {
            printf("Connection closed by server\n");
            break;
        }
        printf("[SERVER] %s\n", buffer);
        sscanf(buffer, "%s", status);
        if (strcmp(status, "DONE") == 0) {
            printf("Congratulations you won the game!\n");
            break;
        }
        if (strcmp(status, "LOSE") == 0) {
            printf("You lost the game!\n");
            break;
        }



        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Get message from the user
        char message[1024];
        printf("Enter your guess character: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        // Send message to the server
        snprintf(buffer, sizeof(buffer), "%s", message);
        send(client_fd, buffer, strlen(buffer), 0);
    }

    // Close the socket
    close(client_fd);

    return 0;
}