cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp ServerSocket.cpp ServerSocket.h SocketException.h Socket.cpp Socket.h simple_server_main.cpp)
