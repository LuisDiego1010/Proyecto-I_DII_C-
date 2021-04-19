#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "socket_client.h"
#include "Json_parser.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Socket_Client Socket= Socket_Client();
    Json_parser Parser=Json_parser();

private slots:
    void on_runbtn_clicked();

private:
    Ui::MainWindow *ui{};
};

#endif // MAINWINDOW_H
