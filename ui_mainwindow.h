/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "pianowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSlope_test;
    QAction *actionSound_driver;
    QAction *actionPlay_happy_birsday;
    QAction *actionLoadPatch;
    QAction *actionSavevPatch;
    QAction *actionSavePatch;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    PianoWidget *pianoWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *switchTabButton;
    QMenuBar *menuBar;
    QMenu *menuTests;
    QMenu *menuSettings;
    QMenu *menuPlay;
    QMenu *menuPatch;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1102, 820);
        actionSlope_test = new QAction(MainWindow);
        actionSlope_test->setObjectName(QString::fromUtf8("actionSlope_test"));
        actionSound_driver = new QAction(MainWindow);
        actionSound_driver->setObjectName(QString::fromUtf8("actionSound_driver"));
        actionPlay_happy_birsday = new QAction(MainWindow);
        actionPlay_happy_birsday->setObjectName(QString::fromUtf8("actionPlay_happy_birsday"));
        actionLoadPatch = new QAction(MainWindow);
        actionLoadPatch->setObjectName(QString::fromUtf8("actionLoadPatch"));
        actionSavevPatch = new QAction(MainWindow);
        actionSavevPatch->setObjectName(QString::fromUtf8("actionSavevPatch"));
        actionSavePatch = new QAction(MainWindow);
        actionSavePatch->setObjectName(QString::fromUtf8("actionSavePatch"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pianoWidget = new PianoWidget(centralWidget);
        pianoWidget->setObjectName(QString::fromUtf8("pianoWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pianoWidget->sizePolicy().hasHeightForWidth());
        pianoWidget->setSizePolicy(sizePolicy);
        pianoWidget->setMaximumSize(QSize(16777215, 200));
        pianoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 222, 255);"));

        gridLayout->addWidget(pianoWidget, 2, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(134, 255, 162);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        switchTabButton = new QPushButton(centralWidget);
        switchTabButton->setObjectName(QString::fromUtf8("switchTabButton"));

        gridLayout->addWidget(switchTabButton, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1102, 21));
        menuTests = new QMenu(menuBar);
        menuTests->setObjectName(QString::fromUtf8("menuTests"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        menuPatch = new QMenu(menuBar);
        menuPatch->setObjectName(QString::fromUtf8("menuPatch"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuTests->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuPlay->menuAction());
        menuBar->addAction(menuPatch->menuAction());
        menuTests->addAction(actionSlope_test);
        menuSettings->addAction(actionSound_driver);
        menuPlay->addAction(actionPlay_happy_birsday);
        menuPatch->addAction(actionLoadPatch);
        menuPatch->addAction(actionSavePatch);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSlope_test->setText(QApplication::translate("MainWindow", "&Slope test", nullptr));
        actionSound_driver->setText(QApplication::translate("MainWindow", "&Sound driver", nullptr));
        actionPlay_happy_birsday->setText(QApplication::translate("MainWindow", "&Play happy birsday", nullptr));
        actionLoadPatch->setText(QApplication::translate("MainWindow", "&LoadPatch", nullptr));
        actionSavevPatch->setText(QApplication::translate("MainWindow", "SavevPatch", nullptr));
        actionSavePatch->setText(QApplication::translate("MainWindow", "&SavePatch", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Page", nullptr));
        switchTabButton->setText(QApplication::translate("MainWindow", "SwitchTab", nullptr));
        menuTests->setTitle(QApplication::translate("MainWindow", "&Tests", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "&Settings", nullptr));
        menuPlay->setTitle(QApplication::translate("MainWindow", "&Play", nullptr));
        menuPatch->setTitle(QApplication::translate("MainWindow", "P&atch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
