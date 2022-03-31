#pragma once

#include <QtWidgets/QMainWindow>
#include <Qlabel>
#include <QPushButton>
#include <Qopenglwidget>
#include "ui_qt_test.h"
#include "GlWidget.h"
#include "HelloTriangle.h"

class qt_test : public QMainWindow
{
    Q_OBJECT

public:
    qt_test(QWidget *parent = Q_NULLPTR);
    void onButtonClick();

private:
    Ui::qt_testClass ui;
    QLabel* lab;
    QPushButton* button;

    HelloTriangleWidget* opengl_widget;
};
