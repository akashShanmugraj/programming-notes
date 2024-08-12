#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char hello[BUFFER_SIZE] = "Hello I am server on the other side of the connection";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming message... \n\n");
   
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        int sumval = 0;

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, BUFFER_SIZE);
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("First Number: %s\n", buffer);
        sumval += atoi(buffer);

        memset(buffer, 0, BUFFER_SIZE);
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Second Number: %s\n", buffer);
        sumval += atoi(buffer);

        if (strcmp(buffer, "STOP") == 0) {
            printf("STOP command received. Shutting down...\n");
            send(new_socket, "Server stopping\n", 16, 0);
            close(new_socket);
            break;
        }

        // Convert sumval to string and send it
        char sumval_str[50];
        sprintf(sumval_str, "%d", sumval);
        send(new_socket, sumval_str, strlen(sumval_str), 0);
        printf("Sum value sent: %s\n", sumval_str);

        close(new_socket); // Close the current connection before accepting a new one
    }

    return 0;
}