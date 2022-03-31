/********************************************************************************
** Form generated from reading UI file 'qt_test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_TEST_H
#define UI_QT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_testClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_testClass)
    {
        if (qt_testClass->objectName().isEmpty())
            qt_testClass->setObjectName(QString::fromUtf8("qt_testClass"));
        qt_testClass->resize(671, 510);
        centralWidget = new QWidget(qt_testClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qt_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_testClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 18));
        qt_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_testClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qt_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_testClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qt_testClass->setStatusBar(statusBar);

        retranslateUi(qt_testClass);

        QMetaObject::connectSlotsByName(qt_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_testClass)
    {
        qt_testClass->setWindowTitle(QApplication::translate("qt_testClass", "qt_test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qt_testClass: public Ui_qt_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_TEST_H
