cmake_minimum_required(VERSION 3.12)
project(type-traits-jonathanprieto99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(type-traits-jonathanprieto99 node.h self_list.h traits_list.h main.cpp test/tester.cpp test/tester.h mock/mocker.cpp mock/mocker.h)