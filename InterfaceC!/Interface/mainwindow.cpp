#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
#include "Json_parser.h"
#include "socket_client.h"

using namespace std;

QStringList listcode;
int count;
QJsonDocument server_info;
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
    QString code = ui->editorCode->toPlainText();
    QString code2= code;
    listcode = code2.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    QString length = QString::number(listcode.length());
    ::count=0;
    ui->ApplicationLog->append("1");
    ui->ApplicationLog->append("2");
}

void MainWindow::on_nextLinebtn_clicked()
{
    ui->ApplicationLog->append("Hello");
    if (::count<=::listcode.length()){
        server_info= Socket.Comunicatte(Parser.qt_json(listcode[::count]));
        std::cout<<"msg from server:"<<server_info.object().value("logger").toString().toUtf8().constData();
        ui->tstdout->setText(server_info.object().value("logger").toString());
        ::count++;
    }
    QJsonObject informationInterface=server_info.object();
    QJsonValue memory=informationInterface.value("Memory");
    QJsonValue out=informationInterface.value("out");
    QJsonValue logger=informationInterface.value("logger");
    QString memoryS=memory.toString();
    QString outS=out.toString();
    QString loggerS=logger.toString();
    ui->ramliveviewer->append(memoryS);
    ui->tstdout->append(outS);
    ui->ApplicationLog->append(loggerS);
}
