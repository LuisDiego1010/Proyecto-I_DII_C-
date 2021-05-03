
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "socket_client.h"
#include "Json_parser.h"
namespace Ui {
class MainWindow;
}
/**
 * @brief Class that contains a window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
/**
 * @brief Constructor and destructor class
 */
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Socket_Client Socket= Socket_Client();
    Json_parser Parser=Json_parser();
    void set_text(QJsonDocument);

private slots:
    void on_runbtn_clicked();

    void on_nextLinebtn_clicked();

private:
    Ui::MainWindow *ui{};
};

#endif // MAINWINDOW_H
