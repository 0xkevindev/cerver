#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int PORT = 8080;

int main () {
    int server_fd = socket(AF_INET,SOCK_STREAM,0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    } else {
        printf("socket created :) \n");
    }
    
    struct sockaddr_in server_addr;
    
    memset(&server_addr,0,sizeof(server_addr));     // clean all bytes to 0
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_fd,(struct sockaddr*)&server_addr, sizeof(server_addr));
    if (bind < 0) {
        perror("not bind");
        return 1;
    } else {
        printf("Bind :) \n");
    }

    listen(server_fd,5);
    if (listen < 0) {
        perror("not listen");
        return 1;
    } else {
        printf("Listening on port %d :) \n",PORT);
    }

    int new_socket;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // handle multiple sockets
    while (1) {
        int new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);    
        if (new_socket < 0) {
            perror("accept");
            continue; 
        }
        printf("Client connected :) \n");

    char msg[] = "{\"message\":\"fuck nodejs and python devs :)\"}";
    char response[512];
    sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: %zu\r\n"
        "\r\n"
        "%s",
        strlen(msg), msg);

    send(new_socket, response, strlen(response), 0);
    printf("Message sent to client \n");
    close(new_socket);
}
    return 0;
}