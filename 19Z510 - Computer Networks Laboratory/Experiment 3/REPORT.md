<p>Experiment 3<p>

  
  

<h1 align="center">Chat Program using TCP Sockets using C language</h1>

## Aim
To implement Chat Program using TCP Sockets in C language
## Source Code for One Way Chat
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

#define PORT 10000


int main()
{
    // Variables and structures
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024] = "[INFO] Connection Established\n";

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
            memset(buffer, '\0', sizeof(buffer));

            int recv_len = recv(client_fd, buffer, 1024, 0);
            if (recv_len <= 0)
            {
                printf("Connection closed by client\n");
                break;
            }
            
            printf("[CLIENT] %s\n", buffer);
            memset(buffer, '\0', sizeof(buffer));

            if (strcmp(buffer, "EXIT\n") == 0)
            {
                printf("[WARN] Connection closed by client\n");
                break;
            }

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

int main()
{
    // Variables and structures
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char clientname[1024];

    printf("Enter your name: ");
    scanf("%s", clientname);
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection failed\n");
        return -1;
    }
// Clear the buffer
    memset(buffer, 0, sizeof(buffer));

        // Receive message from the server
    if (recv(client_fd, buffer, sizeof(buffer), 0) <= 0)
    {
        printf("Connection closed by server\n");
        return -1;
    }
    printf("[SERVER] %s\n", buffer);
    while (1)
    {

        memset(buffer, 0, sizeof(buffer));

        printf("[CLIENT] ");
        fgets(buffer, sizeof(buffer), stdin);
        // message[strcspn(message, "\n")] = 0; // Remove newline character
        if (strcmp(buffer, "EXIT\n") == 0)
        {
            printf("[WARN] Connection closed by client\n");
            break;
        }
        send(client_fd, buffer, strlen(buffer), 0);
    }

    // Close the socket
    close(client_fd);

    return 0;
}
```
## Output

### Server

```plaintext
[LISTENING] Port Number: 4455
[CLIENT] [INFO] Connection Established

[CLIENT] hey

[CLIENT] how are you

[CLIENT] bye

Connection closed by client
```

### Client

```plaintext
Enter your name: akash
[SERVER] [INFO] Connection Established

[CLIENT] hey
[CLIENT] how are you
[CLIENT] bye
[CLIENT] EXIT
[WARN] Connection closed by client
```

## Source Code for Two Way Chat

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

#define PORT 4455


int main()
{
    // Variables and structures
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024] = "[INFO] Connection Established\n";

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
            memset(buffer, '\0', sizeof(buffer));

            int recv_len = recv(client_fd, buffer, 1024, 0);
            if (recv_len <= 0)
            {
                printf("Connection closed by client\n");
                break;
            }
            
            printf("[CLIENT] %s\n", buffer);
            memset(buffer, '\0', sizeof(buffer));

            if (strcmp(buffer, "EXIT\n") == 0)
            {
                printf("[WARN] Connection closed by client\n");
                break;
            }

            printf("[SERVER] ");
            fgets(buffer, 1024, stdin);

            send(client_fd, buffer, strlen(buffer), 0);
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

#define PORT 4455

int main()
{
    // Variables and structures
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char clientname[1024];

    printf("Enter your name: ");
    scanf("%s", clientname);
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection failed\n");
        return -1;
    }

    while (1)
    {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive message from the server
        if (recv(client_fd, buffer, sizeof(buffer), 0) <= 0)
        {
            printf("Connection closed by server\n");
            break;
        }
        printf("[SERVER] %s\n", buffer);

        memset(buffer, 0, sizeof(buffer));

        printf("[CLIENT] ");
        fgets(buffer, sizeof(buffer), stdin);
        // message[strcspn(message, "\n")] = 0; // Remove newline character
        if (strcmp(buffer, "EXIT\n") == 0)
        {
            printf("[WARN] Connection closed by client\n");
            break;
        }
        send(client_fd, buffer, strlen(buffer), 0);
    }

    // Close the socket
    close(client_fd);

    return 0;
}
```

## Output

### Server
```plaintext
[LISTENING] Port Number: 4455
[CLIENT] [INFO] Connection Established

[CLIENT] hi

[SERVER] hey
[CLIENT] how are you?

[SERVER] i'm fine, how are you?
[CLIENT] i'm great!

[SERVER] okay i gtg
[CLIENT] ah okay bye

[SERVER] bye
Connection closed by client
```

### Client
```plaintext
Enter your name: akash
[SERVER] [INFO] Connection Established

[CLIENT] hi
[SERVER] hey

[CLIENT] how are you?
[SERVER] i'm fine, how are you?

[CLIENT] i'm great!
[SERVER] okay i gtg

[CLIENT] ah okay bye
[SERVER] bye

[CLIENT] EXIT
[WARN] Connection closed by client
```
## Result

The implementation of Domain Name System using UDP sockets was carried out successfully.