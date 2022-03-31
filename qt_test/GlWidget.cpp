#include "GlWidget.h"

GlWidget::GlWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
}

GlWidget::~GlWidget()
{

}

void GlWidget::initializeGL()
{
    this->initializeOpenGLFunctions();    //为当前上下文初始化提供OpenGL函数解析

    timer = new QTimer();
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

void GlWidget::resizeGL(int w, int h)
{
    glViewport(0.0f, 0.0f, w, h);    //调整视口
}

void GlWidget::paintGL()
{
    static float r = 0.0, g = 0.0, b = 0.0;
    r += 0.01;
	g += 0.02;
	b += 0.03;
    if (r > 1)r = 0;
    if (g > 1)g = 0;
    if (b > 1)b = 0;
    glClearColor(r, g, b, 1.0f);    //清屏
    glClear(GL_COLOR_BUFFER_BIT);    //清除颜色缓冲
}