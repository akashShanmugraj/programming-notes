// server code
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

// checker function for ACK
int validitychecker(char *buffer, int key)
{
    int number;
    if (sscanf(buffer, "%d", &number) != 1)
    {
        return 0;
    }

    if (number % key == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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
                printf("Connection closed by client\n");
                break;
            }

            memset(buffercopy, '\0', BUFFER_SIZE);

            if (strcmp(buffer, "EXIT\n") == 0)
            {
                printf("[WARN] Connection closed by client\n");
                break;
            }

            printf("[CLIENT] %sACK/NACK? ", buffer);
            scanf("%d", &ack);
            if (ack)
            {
                snprintf(buffercopy, BUFFER_SIZE, "ACK %s", buffer);
            }
            else
            {
                printf("nack-ing %s\n", buffer);
                snprintf(buffercopy, BUFFER_SIZE, "NACK %s", buffer);
            }
            printf("sending %s\n", buffercopy);
            
            send(client_fd, buffercopy, BUFFER_SIZE, 0);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}