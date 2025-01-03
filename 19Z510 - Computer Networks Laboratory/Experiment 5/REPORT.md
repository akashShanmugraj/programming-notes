<p>Experiment 5<p>


<h1 align="center">Implementation of Sliding Window – Stop and Wait Protocol using UDP sockets</h1>


## Aim
To implement Sliding Window – Stop and Wait Protocol using UDP sockets.

## Source Code

### Server
```c
// server code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/select.h>

#define PORT 10000
#define BUFFER_SIZE 1024

int main()
{
    // Variables and structures
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE] = "[INFO] Connection Established\n";
    char buffercopy[BUFFER_SIZE];
    int ack = 0;
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
        addr_size = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);

        printf("[CLIENT] %s\n", buffer);
        send(client_fd, buffer, strlen(buffer), 0);

        while (1)
        {
            memset(buffer, '\0', BUFFER_SIZE);

            int recv_len = recv(client_fd, buffer, 1024, 0);
            if (recv_len <= 0)
            {
                printf("[WARN] Connection closed by client\n");
                break;
            }

            memset(buffercopy, '\0', BUFFER_SIZE);

            if (strcmp(buffer, "EXIT\n") == 0)
            {
                printf("[WARN] Connection closed by client\n");
                break;
            }

            printf("ACK / NACK %s\n", buffer);

            // Set up the file descriptor set
            fd_set set;
            struct timeval timeout;
            int rv;

            // Initialize the file descriptor set
            FD_ZERO(&set);
            FD_SET(STDIN_FILENO, &set);

            // Set the timeout to 5 seconds
            timeout.tv_sec = 5;
            timeout.tv_usec = 0;

            // Wait for input with a timeout
            rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);

            if (rv == -1)
            {
                perror("select"); // Error occurred in select()
            }
            else if (rv == 0)
            {
                // Timeout occurred, send NACK
                printf("\n[WARN] Time Out, Send NACK\n");
                snprintf(buffercopy, BUFFER_SIZE, "NACK %s", buffer);
            }
            else
            {
                // Input is available, read it
                scanf("%d", &ack);
                if (ack)
                {
                    printf("[INFO] Send ACK\n");
                    snprintf(buffercopy, BUFFER_SIZE, "ACK %s", buffer);
                }
                else
                {
                    printf("[INFO] Send NACK\n");
                    snprintf(buffercopy, BUFFER_SIZE, "NACK %s", buffer);
                }
            }

            send(client_fd, buffercopy, strlen(buffercopy), 0);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
```

### Client
```c
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
```

## Output

### Server
```plaintext
[LISTENING] Port Number: 10000
[CLIENT] [INFO] Connection Established

ACK / NACK 1
1
[INFO] Send ACK
ACK / NACK 2
0
[INFO] Send NACK
ACK / NACK 2
0
[INFO] Send NACK
ACK / NACK 2

[WARN] Time Out, Send NACK
ACK / NACK 2
1
[INFO] Send ACK
ACK / NACK 3
1
[INFO] Send ACK
ACK / NACK 4
1
[INFO] Send ACK
ACK / NACK 5
1
[INFO] Send ACK
ACK / NACK 6

[WARN] Time Out, Send NACK
[WARN] Connection closed by client
```

### Client
```plaintext
Enter number of frames: 6
[SERVER] [INFO] Connection Established

[INFO] Sending 1
[SERVER] ACK 1
[INFO] Sending 2
[SERVER] NACK 2
[INFO] NACK recieved for 2, number of re-tries left: 3

[SERVER] NACK 2
[INFO] NACK recieved for 2, number of re-tries left: 2

[SERVER] NACK 2
[INFO] NACK recieved for 2, number of re-tries left: 1

[SERVER] ACK 2
[INFO] Sending 3
[SERVER] ACK 3
[INFO] Sending 4
[SERVER] ACK 4
[INFO] Sending 5
[SERVER] ACK 5
[INFO] Sending 6
[INFO] All frames sent
```

## Result
The implementation of Sliding Window – Stop and Wait Protocol using UDP sockets was carried out successfully.