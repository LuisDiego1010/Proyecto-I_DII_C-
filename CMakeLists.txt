cmake_minimum_required(VERSION 3.17)
project(Proyecto_I_DII_C_)

set(CMAKE_CXX_STANDARD 14 )
set(CMAKE_CXX_FLAGS )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_executable(Server
        "Server/Main Server.cpp"
        Server/Parser.cpp
        Server/Parser.h
        Server/Llist.cpp
        Server/Llist.h
        Server/MemoryController.cpp
        Server/MemoryController.h
        Server/LNode.cpp
        Server/LNode.h
        Server/Gcollector.cpp
        Server/Gcollector.h)
target_link_libraries(Server ${CONAN_LIBS})
add_executable(Client
        "Client/Main Client.cpp" )
add_executable(sizes "sizes/Type size.cpp")
target_link_libraries(Client ${CONAN_LIBS})
