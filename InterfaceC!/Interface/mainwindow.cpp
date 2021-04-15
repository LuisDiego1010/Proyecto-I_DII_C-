#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
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
    QStringList listcode = code.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    ui->terminal->setText(listcode[0]);
}
