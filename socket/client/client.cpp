#include "tcp_client.hpp"

#if 0
// Example of usage client;
int main() {
    try {
        tcp_client client;

        while (true) {
            std::string req;
            std::cout << "Enter request (or 'exit' to close): ";
            std::cin >> req;

            if (req == "exit") 
            {
               break;
            }

            client.request(req);
            std::cout << "Request sent. Waiting for response...\n" << std::flush;

            std::string resp = client.response();
            std::cout << "Response :\n" << resp << std::endl;
        }

        client.close_connection();
    } catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
#endif
