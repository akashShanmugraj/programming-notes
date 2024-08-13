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
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    char *hmmokaymessage = "HMM OKAY";

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

        // Send initial message to the client
        strcpy(buffer, "Hello, This is a test message");
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
            printf("%s\n", buffer);

            // Send response to the client
            send(client_fd, hmmokaymessage, strlen(hmmokaymessage), 0);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}