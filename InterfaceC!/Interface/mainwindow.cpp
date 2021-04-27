#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
#include "Json_parser.h"
#include "socket_client.h"

using namespace std;

QStringList listcode;
int count;
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
    listcode = code2.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    QString length = QString::number(listcode.length());
    ::count=0;
    ui->ApplicationLog->setText("1");
    ui->ApplicationLog->setText("2");
    ui->ApplicationLog->setText("3");
}

void MainWindow::on_nextLinebtn_clicked()
{
    if (::count<=::listcode.length()){
        QJsonDocument server_info= Socket.Comunicatte(Parser.qt_json(listcode[::count]));
        std::cout<<"msg from server:"<<server_info.object().value("logger").toString().toUtf8().constData();
        ui->terminal->setText(server_info.object().value("logger").toString());
        ::count++;
    }

}
