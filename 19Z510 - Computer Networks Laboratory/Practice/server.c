#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 10000

int main() {
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	char buffer[1024];

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_address.s_addr = inet_addr("127.0.0.1");

	bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(server_fd, 5);

	while (1){
		addr_size = sizeof(client_addr);
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
		
		printf("[CLIENT] %s\n", buffer);
		send(client_fd, buffer, strlen(buffer));

		while (1) {
			memset(buffer, '\0', sizeof(buffer));
			int recv_len = recv(client_fd, buffer, 1024, 0);
			if (recv_len <= 0) {
				printf("[WARN] Connection Closed by Client");
				break;
			}
			printf("[CLIENT]: %s", buffer);
			memset(buffer, '\0', sizeof(buffer));
			
			if (strcmp(buffer, "EXIT\n")) {
				printf("[WARN] Connection closed by Client");
				break;
			}
			
			printf("[SERVER]: ");
			fgets(buffer, 1024, stdin);

			send(client_fd, buffer, 1024);
		}
		
		close(client_fd);
	}
	
	close(server_fd);

	return 0;
}
