//
// Created by js_77 on 2022-07-22 0022.
//Reference: https://tldp.org/LDP/LG/issue74/tougher.html#4
//

#include "ServerSocket.h"
#include "SocketException.h"

ServerSocket::ServerSocket(int port){
    if(! Socket::create()){
        throw SocketException ("could not create server socket.");
    }
    if(! Socket::bind(port)){
        throw SocketException ("Could not bind port.");
    }
    if(! Socket::listen()){
        throw SocketException("Could not listen to socket.");
    }
}

ServerSocket::~ServerSocket() {

}

const ServerSocket& ServerSocket::operator<<(const std::string& s) const {
    if(! Socket::send(s)){
        throw SocketException(" Could not write to socket");
    }

    return *this;
}

const ServerSocket& ServerSocket::operator >> (std::string& s) const{
    if(!Socket::recv(s)){
        throw SocketException ("Could not read from socket.");
    }
}


void ServerSocket::accept(ServerSocket& sock){
    if(! Socket::accept( sock )){
        throw SocketException ("Could not accept socket.");
    }
};