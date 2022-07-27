//
// Created by illisoft on 7/27/22.
//

#include "ServerSocket.h"
#include "SocketException.h"
#include <string.h>
#include <iostream>

int main( int argc, char **argv)
{
    std::cout << "running....\n";

    try {
        ServerSocket server(30000);
        while (true) {

            ServerSocket new_sock;
            server.accept(new_sock);

            try {
                while (true) {
                    while (true) {
                        std::string data;
                        new_sock >> data;
                        new_sock << data;
                    }
                }
            }
            catch (SocketException&) {}
        }
    }
    catch(SocketException& e){
        std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

    return 0;
}