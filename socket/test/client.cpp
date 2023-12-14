// #include <iostream>
// #include <cstring>
// #include <arpa/inet.h>
// #include <unistd.h>

// const char *SERVER_ADDRESS = "127.0.0.1";
// const int PORT = 8080;

// int main() {
//     int sock = 0, valread;
//     struct sockaddr_in serv_addr;
//     char buffer[1024] = {0};

//     while (true) {
//         sock = socket(AF_INET, SOCK_STREAM, 0);

//         serv_addr.sin_family = AF_INET;
//         serv_addr.sin_port = htons(PORT);

//         inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

//         connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) ;
//         std::string message;
//         std::cout << "Enter a message  ";
//         std::getline(std::cin, message);


//         send(sock, message.c_str(), message.length(), 0);
//         printf("Message sent\n");

//         valread = read(sock, buffer, 1024);
//         printf("Server response: %s\n", buffer);

//         close(sock);
//     }

//     return 0;
// }
