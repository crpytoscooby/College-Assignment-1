// Server side C program to demonstrate Socket programming

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define MAX 1024

int main()
{
	char *ip = "127.0.0.1";
	int port = 9734;

	// declare variables
	int server_sockfd, client_sockfd;
	char command[MAX], response[MAX];
	struct sockaddr_in server_addr, client_addr;
	int server_len, client_len;
	int n;

	// create socket at server side
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sockfd < 0)
	{
		perror("[-] Socket error");
		exit(1);
	}
	printf("[+] Socket created successfully\n");

	// initialization of structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	server_addr.sin_port = port;
	server_len = sizeof(server_addr);

	// binding server information to its own socket
	n = bind(server_sockfd, (struct sockaddr *)&server_addr, server_len);
	if (n < 0)
	{
		perror("[-] Bind error");
		exit(1);
	}
	printf("[+] Binded to the port number: %d\n", port);

	// listening on server socket for multiple client
	listen(server_sockfd, 5);
	printf("[+] Server is listening\n\n");

	// send and write
	while (1)
	{
		client_len = sizeof(client_addr);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);

		while (1)
		{
			// recieving message from client
			read(client_sockfd, &command, MAX);
			printf("Client: %s\n", command);

			// sending message to client
			printf("Server: ");
			scanf("%[^\n]%*c", response);
			write(client_sockfd, &response, MAX);
		}
	}

	return 0;
}
