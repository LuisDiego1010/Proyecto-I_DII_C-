/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QTextEdit *stdout;
    QTextEdit *terminal;
    QTextEdit *ApplicationLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 497);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RLVlabel = new QLabel(centralWidget);
        RLVlabel->setObjectName(QStringLiteral("RLVlabel"));
        RLVlabel->setGeometry(QRect(430, 20, 141, 17));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        RLVlabel->setFont(font);
        runbtn = new QPushButton(centralWidget);
        runbtn->setObjectName(QStringLiteral("runbtn"));
        runbtn->setGeometry(QRect(10, 10, 61, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        runbtn->setFont(font1);
        nextLinebtn = new QPushButton(centralWidget);
        nextLinebtn->setObjectName(QStringLiteral("nextLinebtn"));
        nextLinebtn->setGeometry(QRect(80, 10, 89, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        nextLinebtn->setFont(font2);
        AppLlabel = new QLabel(centralWidget);
        AppLlabel->setObjectName(QStringLiteral("AppLlabel"));
        AppLlabel->setGeometry(QRect(10, 370, 161, 17));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu Condensed"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        AppLlabel->setFont(font3);
        clearbtn = new QPushButton(centralWidget);
        clearbtn->setObjectName(QStringLiteral("clearbtn"));
        clearbtn->setGeometry(QRect(250, 370, 89, 25));
        clearbtn->setFont(font2);
        directionlabel = new QLabel(centralWidget);
        directionlabel->setObjectName(QStringLiteral("directionlabel"));
        directionlabel->setGeometry(QRect(350, 40, 67, 17));
        valuelabel = new QLabel(centralWidget);
        valuelabel->setObjectName(QStringLiteral("valuelabel"));
        valuelabel->setGeometry(QRect(430, 40, 61, 17));
        namelabel = new QLabel(centralWidget);
        namelabel->setObjectName(QStringLiteral("namelabel"));
        namelabel->setGeometry(QRect(500, 40, 67, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(570, 40, 67, 17));
        stdout = new QTextEdit(centralWidget);
        stdout->setObjectName(QStringLiteral("stdout"));
        stdout->setGeometry(QRect(10, 40, 321, 221));
        stdout->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        stdout->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        stdout->setTabChangesFocus(false);
        stdout->setLineWrapMode(QTextEdit::NoWrap);
        stdout->setReadOnly(false);
        terminal = new QTextEdit(centralWidget);
        terminal->setObjectName(QStringLiteral("terminal"));
        terminal->setGeometry(QRect(10, 270, 321, 91));
        terminal->setReadOnly(true);
        ApplicationLog = new QTextEdit(centralWidget);
        ApplicationLog->setObjectName(QStringLiteral("ApplicationLog"));
        ApplicationLog->setGeometry(QRect(10, 400, 321, 91));
        ApplicationLog->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "C! - IDE", Q_NULLPTR));
        RLVlabel->setText(QApplication::translate("MainWindow", "RAM LIVE VIEWER", Q_NULLPTR));
        runbtn->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        nextLinebtn->setText(QApplication::translate("MainWindow", "NEXT LINE", Q_NULLPTR));
        AppLlabel->setText(QApplication::translate("MainWindow", "APPLICATION LOG", Q_NULLPTR));
        clearbtn->setText(QApplication::translate("MainWindow", "CLEAR", Q_NULLPTR));
        directionlabel->setText(QApplication::translate("MainWindow", "Direction", Q_NULLPTR));
        valuelabel->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        namelabel->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Count Ref", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
