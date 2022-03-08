// Client side C program to demonstrate Socket programming

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

	// declare variable
	int client_sockfd;
	char command[MAX], response[MAX];
	struct sockaddr_in server_addr, client_addr;
	int client_len, result;

	// create socket at client side
	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sockfd < 0)
	{
		perror("[-] Socket error");
		exit(1);
	}
	printf("[+] Socket created successfully\n");

	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr(ip);
	client_addr.sin_port = port;
	client_len = sizeof(client_addr);

	result = connect(client_sockfd, (struct socksddr *)&client_addr, client_len);
	if (result < 0)
	{
		perror("[-] Connection error");
		exit(1);
	}
	printf("\n");


	while (1)
	{
		printf("Client: ");
		scanf("%[^\n]%*c", command);
		write(client_sockfd, &command, MAX);

		read(client_sockfd, &response, MAX);
		printf("Server: %s\n", response);
	}
	close(client_sockfd);

	return 0;
}
