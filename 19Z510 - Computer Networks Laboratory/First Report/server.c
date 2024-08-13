#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

int main() {

  // Variables and structures
  int client_fd;
  struct sockaddr_in server_addr;
  char buffer[1024];

  // Client socket
  client_fd = socket(AF_INET, SOCK_STREAM, 0);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Connection failed\n");
    return -1;
  }
  printf("[CONNECTED] Connected to the server\n");

  // Receive message from the server
  recv(client_fd, buffer, 1024, 0);
  printf("[SERVER] %s\n", buffer);

  // Send message to the server
  strcpy(buffer, "Hello, Server. This is the client.");
  send(client_fd, buffer, strlen(buffer), 0);

  // Close the socket
  close(client_fd);
  printf("[DISCONNECTED] Connection closed\n");

  return 0;
}