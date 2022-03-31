#pragma once

#ifndef __HELLO_TRIANGLE_H__
#define __HELLO_TRIANGLE_H__

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QOpenGLVertexArrayObject>

class HelloTriangleWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    HelloTriangleWidget(QWidget* parent = 0);
    ~HelloTriangleWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QTimer* timer;
    unsigned int shaderProgram;
    QOpenGLVertexArrayObject VAO;
};

#endif // WIDGET_H