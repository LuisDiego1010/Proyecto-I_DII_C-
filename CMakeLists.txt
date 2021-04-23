cmake_minimum_required(VERSION 3.17)
project(Proyecto_I_DII_C_)

set(CMAKE_CXX_STANDARD 20 )
set(CMAKE_CXX_STANDARD_REQUIRED  ON )
set(CMAKE_CXX_FLAGS -fPIC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QT_DEBUG_PLUGINS 1)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CMAKE_PREFIX_PATH ${CONAN_LIBS})
set(Qt5_DIR /usr/lib/x86_64-linux-gnu/qt5)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(Qt5Widgets_INCLUDE_DIRS ${CONAN_LIBS})
set (QT_DEFAULT_MAJOR_VERSION(5.15.2))
get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)


BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT (my_logger, src :: logger_mt)

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
        Server/Scope.cpp
        Server/Scope.h
        Server/Gcollector.cpp
        Server/Gcollector.h)
target_link_libraries(Server ${CONAN_LIBS})
add_executable(Client
        "InterfaceC!/Interface/main.cpp"
        InterfaceC!/Interface/mainwindow.cpp
        InterfaceC!/Interface/mainwindow.h
        InterfaceC!/Interface/Json_parser.cpp
        InterfaceC!/Interface/Json_parser.h
        InterfaceC!/Interface/mainwindow.ui
        InterfaceC!/Interface/socket_client.cpp
        InterfaceC!/Interface/socket_client.h
        )


target_link_libraries(Client ${CONAN_LIBS})
target_link_libraries(Client Qt5::Widgets Qt5::Gui)


add_executable(sizes "sizes/Type size.cpp")
