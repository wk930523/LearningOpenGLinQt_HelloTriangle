#include "qt_test.h"

qt_test::qt_test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->opengl_widget = new HelloTriangleWidget(this);
    this->opengl_widget->setGeometry(this->geometry());
    this->lab = new QLabel("Hello,World!", this);
    this->lab->setGeometry(10, 20, 100, 20);
    this->button = new QPushButton("test", this);
    this->button->setGeometry(10, 40, 100, 20);
	QObject::connect(this->button, &QPushButton::clicked, this, &qt_test::onButtonClick);
}

void qt_test::onButtonClick()
{
    static int i = 0;
    this->lab->setText(QString::number(i++));
}