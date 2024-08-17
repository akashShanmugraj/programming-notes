# Hangman Game using Sockets
### Submitted by Akash Shanmugaraj

## Problem Statement
Hangman is a word guessing game, implemented using TCP/IP sockets. The server will choose a random word from a list of words and the client will have to guess the word. The client will have 7 chances to guess the word. The client will send a letter to the server and the server will respond with the word with the correct letters guessed by the client. If the client guesses the word correctly, the server will respond with "You win!" and the game will end. If the client runs out of chances, the server will respond with "You lose!" and the game will end.

## Implementation

The four major components of the implementation are:
1. TCP/IP Sockets
2. Server Model
3. Client Model
4. Game Logic

We will discuss each of these components in detail.

### TCP/IP Sockets
A socket is a software concept for a connection. Sockets enable applications to connect to a Transmission Control Protocol/Internet Protocol (TCP/IP) network.

An application running on a host creates a socket or doorway to connect with an application on another host. Messages pass through this socket or doorway.

![](https://developerhelp.microchip.com/xwiki/bin/download/applications/tcp-ip/sockets-ports/WebHome/socket_door.jpg?width=270&height=166&rev=1.1)

When an application starts on a host, a port number is assigned to a process or a function running in it. When that application wants to communicate with another host, (go to a website for example) a socket is created.

This example shows three applications requiring three TCP communication channels: Two channels for each of the two web browsers acting as HTTP clients, and one for the email application acting as an SMTP client.

![](https://developerhelp.microchip.com/xwiki/bin/download/applications/tcp-ip/sockets-ports/WebHome/sockets.png?width=571&height=228&rev=1.1)

Sockets are physically implemented as transmit (TX) & receive (RX) memory buffers.

When an application wants to transmit a message, a process writes to the socket’s transmit buffer. This same process periodically checks the socket’s receive buffer for messages being sent by the host on the other end of the virtual connection.

The Transport layer delivers messages to the application by writing them to the socket’s receive buffer. The Transport layer also periodically polls the socket’s transmit buffer to determine if there are messages to send.

![](https://developerhelp.microchip.com/xwiki/bin/download/applications/tcp-ip/sockets-ports/WebHome/socket_buffers.png?width=566&height=226&rev=1.1)

### Server Model
The server model is implemented in C using `arpa/inet.h`, `sys/socket.h` and `netinet/in.h` libraries. The purpose of this model is only to create, listen and transmit messages in a TCP/IP socket. The remaining game logic is implemented in the game logic model.

The server model is implemented as follows:
0. Necessary header files are included and variables are declared.
```c
    // Variables and structures
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    char outputstore[1024];
    char *output = outputstore;
    char *targetword = malloc(1024);
    char guesshistory[1024] = "?";
    char *history = guesshistory;
    int turnsleft = 7;
    char* dummyptr = malloc(1024);
    char* status = malloc(1024);
```

```c
// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
```

1. Create a socket using `socket()`.
```c
    // Server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
```
2. Bind the socket to an address and Listen for incoming connections using `bind()` and `listen()`.
```c
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    printf("[LISTENING] Port Number: %d\n", PORT);
```

3. Accept incoming connections using `accept()`.
```c
addr_size = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
```

4. Send preliminary information to the client about the game
```c
// Send initial message to the client
        snprintf(buffer, sizeof(buffer), "Hello, welcome to the game of Hangman!\nYou will be guessing a word of length %d, so Good luck!\nthe output is formatted as below:\n\nStatus of Guess - Game State - Number of turns left\n\n", (int)strlen(targetword));
        send(client_fd, buffer, strlen(buffer), 0);
```

5. Receive the guess from the client
```c
// Clear the buffer
            memset(buffer, '\0', sizeof(buffer));

            // Receive message from the client
            int recv_len = recv(client_fd, buffer, 1024, 0);
            if (recv_len <= 0)
            {
                printf("Connection closed by client\n");
                break;
            }
```

6. Attempt to call the logic function to process the guess
```c
            callpythonlogicfunction(targetword, buffer, turnsleft, history, output);
```

7. Parse the output of the logic function to determine WIN, LOSS or CONTINUE and send the appropriate message to the client
```c
sscanf(output, "%s", status);

            if (strcmp(status, "Done") == 0) {
                strcpy(output, "Congratulations! You have won the game!\n");
                int send_result = send(client_fd, output, strlen(output), 0);
                if (send_result == -1) {
                    perror("send");
                } else {
                    printf("Sent: %s\n", output);
                }
                break;
            }
            sscanf(output, "%*s %s", history);

            sscanf(output, "%*s %*s %s", dummyptr);
            turnsleft = atoi(dummyptr);

            if (turnsleft == 0) {
                strcpy(output, "LOSE You have lost the game!\n");
                int send_result = send(client_fd, output, strlen(output), 0);
                if (send_result == -1) {
                    perror("send");
                } else {
                    printf("Sent: %s\n", output);
                }
                break;
            }
            // Send response to the client
            send(client_fd, output, strlen(output), 0);
```

8. Repeat steps 5-7 until the game ends
9. Close the client and server sockets
```c
    close(client_fd);
    close(server_fd);
```

### Client Model
0. Necessary header files are included and variables are declared.
```c
    // Variables and structures
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char clientname[1024];
    char* status = malloc(1024);
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455
```

1. Define socket object for connection
```c
// Client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
```

2. Attempt to connect to the socket using `connect()`
```c
    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Connection failed\n");
        return -1;
    }
```

3. Receive messages from the server and print it appropriately
```c
// Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive message from the server
        if (recv(client_fd, buffer, sizeof(buffer), 0) <= 0)
        {
            printf("Connection closed by server\n");
            break;
        }
        printf("[SERVER] %s\n", buffer);
```

4. Parse the message from the server to determine WIN or LOSS to determine termination of the game
```c
sscanf(buffer, "%s", status);
        if (strcmp(status, "DONE") == 0) {
            printf("Congratulations you won the game!\n");
            break;
        }
        if (strcmp(status, "LOSE") == 0) {
            printf("You lost the game!\n");
            break;
        }
```

5. If not WIN or LOSS, prompt the user for a guess and send it to the server
```c
memset(buffer, 0, sizeof(buffer));

        // Get message from the user
        char message[1024];
        printf("Enter your guess character: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        // Send message to the server
        snprintf(buffer, sizeof(buffer), "%s", message);
        send(client_fd, buffer, strlen(buffer), 0);
```

6. Repeat steps 3-5 until the game ends
7. Close the client socket
```c
    close(client_fd);
```

### Game Logic
The game logic is implemented in Python. It is a simple function that takes inputs from commandline arguments and performs from string manipulation to determine the game state.

The game logic is implemented as follows:
1. Obtain the target word, guess, turns left and history from the commandline arguments

```python
import sys

if len(sys.argv) < 5:
    print("ISFC ", sys.argv)
    sys.exit(1)

targetword = sys.argv[1]
guesscharacter = sys.argv[2]
guesscount = int(sys.argv[3])
guessstate = sys.argv[4]
```
2. Determine if the guess has already been made
```python
if guesscharacter in guessstate:
    print(f"ALR {guessstate} {guesscount}")
    sys.exit(0)
```

3. Determine if the guess is CRCT or DONE or WRNG and print accordingly
```python
if guesscharacter in targetword:
    guessstate = "".join([c if c == guesscharacter or c in guessstate else "_" for c in targetword])
    if guessstate == targetword:
        print(f"DONE {guessstate} {guesscount}")
    print(f"CRCT {guessstate} {guesscount}")
    sys.exit(0)

print(f"WRNG {guessstate} {guesscount-1}")
sys.exit(0)
```

Additionally, another python script containing the list of words is also used in the server to randomly select a word for the game.

```python
import random

wordlist = ["apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "ugli", "watermelon"]

randomword = random.choice(wordlist)
wordlength = len(set(randomword))

print(randomword, wordlength)
```

## Output

<img width="391" alt="server-word" src="https://github.com/user-attachments/assets/2b093b9b-c369-4b43-8692-aa602531a584">

When the server is first run, it determines a random word and starts listening for connections.

<img width="622" alt="init" src="https://github.com/user-attachments/assets/c6aa00df-b237-4d3c-8ad7-5de76fe5c8e7">

The client first asks for the players name and connects to the server. The server sends the initial message to the client and the game begins.

<img width="354" alt="crt" src="https://github.com/user-attachments/assets/01fa23a0-352c-4fa8-9ea9-03c1e9e55969">

The client proceeds to guess the word and the server responds with the game state.

<img width="359" alt="wrng" src="https://github.com/user-attachments/assets/b0cfa691-a0f8-490c-9a7c-1f4fca8e3b27">

If the client attempts an incorrect guess, number of turns left is decremented.

<img width="389" alt="win" src="https://github.com/user-attachments/assets/959d7baa-da69-4d3c-ac93-7f36afd82886">

If the client guesses the word correctly, the server responds with "Congratulations you won the game!" and the game ends.

<img width="445" alt="lose" src="https://github.com/user-attachments/assets/71692073-cf08-4360-a152-857565ba2a59">

If the client runs out of turns, the server responds with "You have lost the game!" and the game ends.