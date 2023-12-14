// #include <iostream>
// #include <cstring>
// #include <arpa/inet.h>
// #include <unistd.h>

// const int PORT = 8080;

// int main() {
//     int server_fd, new_socket;
//     struct sockaddr_in address;
//     int addrlen = sizeof(address);
//     char buffer[1024] = {0};
//     const char *hello = "Hello from server";

//     // Creating socket file descriptor
//     if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//         perror("Socket failed");
//         exit(EXIT_FAILURE);
//     }

//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = INADDR_ANY;
//     address.sin_port = htons(PORT);

//     // Binding the socket
//     if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
//         perror("Bind failed");
//         exit(EXIT_FAILURE);
//     }

//     // Listening for connections
//     if (listen(server_fd, 3) < 0) {
//         perror("Listen");
//         exit(EXIT_FAILURE);
//     }

//     std::cout << "Server listening on port " << PORT << std::endl;

//     while (true) {
//         // Accepting incoming connections
//         if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
//             perror("Accept");
//             exit(EXIT_FAILURE);
//         }

//         int valread = read(new_socket, buffer, 1024);
//         printf("Received message from client: %s\n", buffer);

//         // Sending a response
//         send(new_socket, hello, strlen(hello), 0);
//         printf("Hello message sent\n");

//         // Close the socket for this client and wait for the next connection
//         close(new_socket);
//     }

//     return 0;
// }
