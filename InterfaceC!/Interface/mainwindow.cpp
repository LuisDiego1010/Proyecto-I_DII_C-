#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
#include "Json_parser.h"
#include "socket_client.h"
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
    QStringList listcode = code.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    ui->terminal->setText(listcode[0]);

    QJsonDocument server_info= Socket.Comunicatte(Parser.qt_json(listcode[0]));
    std::cout<<"msg from server:"<<server_info.object().value("logger").toString().toUtf8().constData();
    ui->terminal->setText(server_info.object().value("logger").toString());
    ui->terminal->setText(listcode[0]);
    ui->terminal->setText(listcode[0]);

}
