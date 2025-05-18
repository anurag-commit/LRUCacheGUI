/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditKey;
    QLineEdit *lineEditValue;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonPut;
    QPushButton *buttonGet;
    QTableWidget *tableCache;
    QLabel *labelRemoved;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEditKey = new QLineEdit(centralwidget);
        lineEditKey->setObjectName("lineEditKey");

        horizontalLayout_2->addWidget(lineEditKey);

        lineEditValue = new QLineEdit(centralwidget);
        lineEditValue->setObjectName("lineEditValue");

        horizontalLayout_2->addWidget(lineEditValue);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonPut = new QPushButton(centralwidget);
        buttonPut->setObjectName("buttonPut");

        horizontalLayout->addWidget(buttonPut);

        buttonGet = new QPushButton(centralwidget);
        buttonGet->setObjectName("buttonGet");

        horizontalLayout->addWidget(buttonGet);


        verticalLayout->addLayout(horizontalLayout);

        tableCache = new QTableWidget(centralwidget);
        tableCache->setObjectName("tableCache");

        verticalLayout->addWidget(tableCache);

        labelRemoved = new QLabel(centralwidget);
        labelRemoved->setObjectName("labelRemoved");

        verticalLayout->addWidget(labelRemoved);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonPut->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        buttonGet->setText(QCoreApplication::translate("MainWindow", "buttonGet", nullptr));
        labelRemoved->setText(QCoreApplication::translate("MainWindow", "Last removed key: None", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
