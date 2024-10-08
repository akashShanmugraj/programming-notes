// client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10000
#define BUFFER_SIZE 1024

int shouldretry(int counter, int limit)
{
    if (counter == limit)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    // Variables and structures
    int client_fd;
    struct sockaddr_in server_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];
    char ackbuffer[BUFFER_SIZE];
    char clientname[BUFFER_SIZE];
    int faillimit = 4;
    int failcounter = 0;
    int framesize;
    int framecounter = 0;

    printf("Enter number of frames: ");
    scanf("%d", &framesize); // Pass the address of framesize
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // Client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("[WARN] Connection failed\n");
        return -1;
    }

    while (1)
    {
        if (framecounter == framesize)
        {
            printf("[INFO] All frames sent\n");
            break;
        }

        // Clear the buffer
        memset(recvbuffer, '\0', BUFFER_SIZE);

        // Receive message from the server
        if (recv(client_fd, recvbuffer, BUFFER_SIZE, 0) <= 0)
        {
            printf("[WARN] Connection closed by server\n");
            break;
        }

        sscanf(recvbuffer, "%s %s", ackbuffer, sendbuffer);
        printf("[SERVER] %s\n", recvbuffer);

        if (strcmp(ackbuffer, "NACK") == 0)
        {
            failcounter++;
            if (shouldretry(failcounter, faillimit) == 0)
            {
                printf("[WARN] Retry Limit Exceeded, moving on with next input\n\n");
                failcounter = 0;
                framecounter++;
                printf("[INFO] Sending %d\n", framecounter);
                snprintf(sendbuffer, BUFFER_SIZE, "%d", framecounter);
            }
            else
            {
                printf("[INFO] NACK recieved for %s, number of re-tries left: %d\n\n", sendbuffer, faillimit - failcounter);
            }
        }
        else
        {
            failcounter = 0;
            framecounter++;
            printf("[INFO] Sending %d\n", framecounter);
            snprintf(sendbuffer, BUFFER_SIZE, "%d", framecounter);
        }

        send(client_fd, sendbuffer, strlen(sendbuffer), 0);

        memset(sendbuffer, '\0', BUFFER_SIZE);
    }

    // Close the socket
    close(client_fd);

    return 0;
}