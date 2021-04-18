#-------------------------------------------------
#
# Project created by QtCreator 2021-04-10T23:12:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        Json_parser.cpp \
        main.cpp \
        mainwindow.cpp \
        socket_client.cpp
LIBS += \
        -lboost_system\

HEADERS += \
        Json_parser.h \
        mainwindow.h \
        socket_client.h

FORMS += \
        mainwindow.ui



unix:!macx: LIBS += -L$$PWD/../../../../.conan/data/zmqpp/4.2.0/_/_/package/526382e62919e595b7a1be9560a68e5e3ba1d5b8/lib/ -lzmqpp-static

INCLUDEPATH += $$PWD/../../../../.conan/data/zmqpp/4.2.0/_/_/package/526382e62919e595b7a1be9560a68e5e3ba1d5b8/include/zmqpp
DEPENDPATH += $$PWD/../../../../.conan/data/zmqpp/4.2.0/_/_/package/526382e62919e595b7a1be9560a68e5e3ba1d5b8/include/zmqpp

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../.conan/data/zmqpp/4.2.0/_/_/package/526382e62919e595b7a1be9560a68e5e3ba1d5b8/lib/libzmqpp-static.a

unix:!macx: LIBS += -L$$PWD/../../../../.conan/data/zeromq/4.3.3/_/_/package/4a4500bdf9b12024d2cf6e38334aa40f7cabc37c/lib/ -lzmq

INCLUDEPATH += $$PWD/../../../../.conan/data/zeromq/4.3.3/_/_/package/4a4500bdf9b12024d2cf6e38334aa40f7cabc37c/include
DEPENDPATH += $$PWD/../../../../.conan/data/zeromq/4.3.3/_/_/package/4a4500bdf9b12024d2cf6e38334aa40f7cabc37c/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../.conan/data/zeromq/4.3.3/_/_/package/4a4500bdf9b12024d2cf6e38334aa40f7cabc37c/lib/libzmq.a



unix:!macx: LIBS += -lzmqpp-static
