// server program for udp connection 
#include <stdio.h> 
#include <stdlib.h>
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#define PORT 5000 
#define MAXLINE 1000 

int getipaddr(char* key, char*value)
{   
    strcpy(value, "IP address not found");
    char* comparekey = malloc(1024);

    char filename[] = "data.txt";
    printf("Opening file %s\n", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s\n", line);
        sscanf(line, "%s %s", comparekey, value);
        if (strcmp(comparekey, key) == 0)
        {
            break;
        }
    }
    
	return 0;
}

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

// Driver code 
int main() 
{ 
	char buffer[100]; 
	char *message = malloc(1024); 
	int listenfd, len; 
	struct sockaddr_in servaddr, cliaddr; 
	bzero(&servaddr, sizeof(servaddr)); 

	// Create a UDP Socket 
	listenfd = socket(AF_INET, SOCK_DGRAM, 0);		 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 

	// bind server address to socket descriptor 
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
	
	//receive the datagram 
	len = sizeof(cliaddr); 
	int n = recvfrom(listenfd, buffer, sizeof(buffer), 
			0, (struct sockaddr*)&cliaddr,&len); //receive message from server 
	buffer[n] = '\0'; 

	// Get the IP address from the file
	getipaddr(buffer, message);

	// send the response 
	sendto(listenfd, message, MAXLINE, 0, 
		(struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
} 
