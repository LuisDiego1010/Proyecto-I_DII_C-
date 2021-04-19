#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
#include "Json_parser.h"
#include "socket_client.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runbtn_clicked()
{
    QString code = ui->stdoutCode->toPlainText();
    QString code2= code;
    QStringList listcode = code2.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    QString length = QString::number(listcode.length());
    for (int count=0; count==(listcode.length()+1); count++){
        QJsonDocument server_info= Socket.Comunicatte(Parser.qt_json(listcode[count]));
        std::cout<<"msg from server:"<<server_info.object().value("logger").toString().toUtf8().constData();
        ui->terminal->setText(server_info.object().value("logger").toString());
    }
    //Mandar_todo


    //QJsonDocument server_info= Socket.Comunicatte(Parser.qt_json(listcode[0]));
    //std::cout<<"msg from server:"<<server_info.object().value("logger").toString().toUtf8().constData();
    //ui->terminal->setText(server_info.object().value("logger").toString());

}
