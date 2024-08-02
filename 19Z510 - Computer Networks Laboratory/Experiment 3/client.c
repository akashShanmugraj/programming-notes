#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[100]; // change the string here for customisation
    char buffer[BUFFER_SIZE] = {0};

    printf("Enter Code: ");
    scanf("%s", hello);

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect the socket to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    while (1) {
        // Send message to server
        printf("You: ");
        scanf("%s", hello);
        send(sock, hello, strlen(hello), 0);

        // Read server response
        valread = read(sock, buffer, BUFFER_SIZE);
        printf("Them: %s\n", buffer);

        if (strcmp(buffer, "STOP") == 0) {
            printf("STOP command received. Shutting down...\n");
            send(sock, "Server stopping\n", 16, 0);
            close(sock);
            break;
        }
    }
    return 0;
}
