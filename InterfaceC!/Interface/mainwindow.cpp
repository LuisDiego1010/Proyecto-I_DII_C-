#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

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
    QString code = ui->stdout->toPlainText();
    QStringList listcode = code.split(QRegExp("[\n]"),QString::SkipEmptyParts);
    qInfo( "C Style Info Message" );
}
