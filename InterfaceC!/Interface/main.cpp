#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Main for execute the interface
 * @param argc number of targeted strings for argv
 * @param argv represent the command line arguments specified by the program user
 * @return the aplication
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
