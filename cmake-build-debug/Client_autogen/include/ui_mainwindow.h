/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *RLVlabel;
    QPushButton *runbtn;
    QPushButton *nextLinebtn;
    QLabel *AppLlabel;
    QPushButton *clearbtn;
    QLabel *directionlabel;
    QLabel *valuelabel;
    QLabel *namelabel;
    QLabel *label;
    QTextEdit *stdoutCode;
    QTextEdit *terminal;
    QTextEdit *ApplicationLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(653, 497);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RLVlabel = new QLabel(centralWidget);
        RLVlabel->setObjectName(QString::fromUtf8("RLVlabel"));
        RLVlabel->setGeometry(QRect(430, 20, 141, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        RLVlabel->setFont(font);
        runbtn = new QPushButton(centralWidget);
        runbtn->setObjectName(QString::fromUtf8("runbtn"));
        runbtn->setGeometry(QRect(10, 10, 61, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        runbtn->setFont(font1);
        nextLinebtn = new QPushButton(centralWidget);
        nextLinebtn->setObjectName(QString::fromUtf8("nextLinebtn"));
        nextLinebtn->setGeometry(QRect(80, 10, 89, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        nextLinebtn->setFont(font2);
        AppLlabel = new QLabel(centralWidget);
        AppLlabel->setObjectName(QString::fromUtf8("AppLlabel"));
        AppLlabel->setGeometry(QRect(10, 370, 161, 17));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        AppLlabel->setFont(font3);
        clearbtn = new QPushButton(centralWidget);
        clearbtn->setObjectName(QString::fromUtf8("clearbtn"));
        clearbtn->setGeometry(QRect(240, 370, 89, 25));
        clearbtn->setFont(font2);
        directionlabel = new QLabel(centralWidget);
        directionlabel->setObjectName(QString::fromUtf8("directionlabel"));
        directionlabel->setGeometry(QRect(350, 40, 67, 17));
        valuelabel = new QLabel(centralWidget);
        valuelabel->setObjectName(QString::fromUtf8("valuelabel"));
        valuelabel->setGeometry(QRect(430, 40, 61, 17));
        namelabel = new QLabel(centralWidget);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(500, 40, 67, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 40, 67, 17));
        stdoutCode = new QTextEdit(centralWidget);
        stdoutCode->setObjectName(QString::fromUtf8("stdoutCode"));
        stdoutCode->setGeometry(QRect(10, 40, 321, 221));
        stdoutCode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        stdoutCode->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        stdoutCode->setTabChangesFocus(false);
        stdoutCode->setLineWrapMode(QTextEdit::NoWrap);
        stdoutCode->setReadOnly(false);
        terminal = new QTextEdit(centralWidget);
        terminal->setObjectName(QString::fromUtf8("terminal"));
        terminal->setGeometry(QRect(10, 270, 321, 91));
        terminal->setReadOnly(true);
        ApplicationLog = new QTextEdit(centralWidget);
        ApplicationLog->setObjectName(QString::fromUtf8("ApplicationLog"));
        ApplicationLog->setGeometry(QRect(10, 400, 321, 91));
        ApplicationLog->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "C! - IDE", nullptr));
        RLVlabel->setText(QApplication::translate("MainWindow", "RAM LIVE VIEWER", nullptr));
        runbtn->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        nextLinebtn->setText(QApplication::translate("MainWindow", "NEXT LINE", nullptr));
        AppLlabel->setText(QApplication::translate("MainWindow", "APPLICATION LOG", nullptr));
        clearbtn->setText(QApplication::translate("MainWindow", "CLEAR", nullptr));
        directionlabel->setText(QApplication::translate("MainWindow", "Direction", nullptr));
        valuelabel->setText(QApplication::translate("MainWindow", "Value", nullptr));
        namelabel->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label->setText(QApplication::translate("MainWindow", "Count Ref", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
