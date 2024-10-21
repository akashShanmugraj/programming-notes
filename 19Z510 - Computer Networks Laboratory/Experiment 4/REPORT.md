<p>Experiment 4<p>


<h1 align="center">Implementation of DNS using UDP Sockets</h1>


## Aim
To implement Domain Name System using UDP sockets.

## Program

### Server
```c
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
        sscanf(line, "%s %s", comparekey, value);
        if (strcmp(comparekey, key) == 0)
        {
            break;
        }
    }

    if (!(strcmp(comparekey, key) == 0)) {
        strcpy(value, "IP address not found");
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
	int listenfd;
    socklen_t len; 
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
	int n = recvfrom(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr,&len); //receive message from server 
	buffer[n] = '\0'; 

	// Get the IP address from the file
	getipaddr(buffer, message);

	// send the response 
	sendto(listenfd, message, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));

    free(message);
    return 0; 
} 
```

### Client
```c
// udp client driver program 
#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 

#define PORT 5000 
#define MAXLINE 1000 

// Driver code 
int main() 
{ 
	char buffer[100]; 
	char *message = "www.hotmail.com"; 
	int sockfd, n; 
	struct sockaddr_in servaddr; 
	
	// clear servaddr 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 
	
	// create datagram socket 
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	
	// connect to server 
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
	{ 
		printf("\n Error : Connect Failed \n"); 
		exit(0); 
	} 

	// request to send datagram 
	// no need to specify server address in sendto 
	// connect stores the peers IP and port 
	sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr)); 
	
	// waiting for response 
	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); 
	puts(buffer); 

	// close the descriptor 
	close(sockfd); 
} 
```

## Output

```plaintext
20.207.73.82
142.250.193.142
157.240.192.52
```

## Result
The implementation of Domain Name System using UDP sockets was carried out successfully.