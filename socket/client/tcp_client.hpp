#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class tcp_client
{
public:
   tcp_client()
      : socket_fd{}
      , server_IP{ "127.0.0.1"}
      , server_PORT{8080}
      , size{socklen_t(sizeof(address))}
   {
      address.sin_port = htons(server_PORT);
      address.sin_family = AF_INET;
      address.sin_addr.s_addr = INADDR_ANY;
      
      if (inet_pton(AF_INET, server_IP.c_str(), &address.sin_addr) < 0)  throw std::runtime_error("Error converting addres\n");; 
      
      create_socket();
      connect_to_server();
   }

private:
   void create_socket()
   {
      socket_fd = socket(AF_INET, SOCK_STREAM, 0);
      
      if (socket_fd < 0)
      {
         throw std::runtime_error("Error creating socket\n");
      }
   }

   void connect_to_server()
   {
      if (connect(socket_fd, reinterpret_cast<sockaddr*>(&address), size) < 0)
      {
         throw std::runtime_error("Error connecting to server \n");
      }
      std::cout << "Connected to the server\n";
   }

public:   
   void request(const std::string& req)
   { 
      size_t sent_bytes = send(socket_fd, req.c_str(), req.size(), 0);
      
      if (sent_bytes < 0)
      {
         throw std::runtime_error("Error sending request to server");
      }
   }

   std::string response()
   {
      char buff[2048];
      size_t received_bytes = recv(socket_fd, buff , sizeof(buff), 0);

      if (received_bytes < 0)
      {
         throw std::runtime_error("Error reading response from server");
      }

      buff[received_bytes] = '\0';

      return static_cast<std::string>(buff);
   }

   void close_connection()
   {
      close(socket_fd);
      std::cout << "Conenciton closed\n";
   }

private:

   int socket_fd;
   sockaddr_in address;
   socklen_t size;
   std::string server_IP;
   const int server_PORT;
};
