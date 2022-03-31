#include "HelloTriangle.h"
#include <qDebug>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

HelloTriangleWidget::HelloTriangleWidget(QWidget* parent)
	: QOpenGLWidget(parent)
{
}

HelloTriangleWidget::~HelloTriangleWidget()
{
	delete timer;
	glDeleteProgram(shaderProgram);
}

void HelloTriangleWidget::initializeGL()
{
	this->initializeOpenGLFunctions();    //Ϊ��ǰ�����ĳ�ʼ���ṩOpenGL��������

	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
	}
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};

	unsigned int VBO;
	VAO.create();
	if (!VAO.isCreated()) {
		qDebug() << "vao is not created.";
	}
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	VAO.bind();

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	VAO.release();

	glDeleteBuffers(1, &VBO);

	timer = new QTimer();
	timer->setInterval(33);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start();
}

void HelloTriangleWidget::resizeGL(int w, int h)
{
	glViewport(0.0f, 0.0f, w, h);    //�����ӿ�
}

void HelloTriangleWidget::paintGL()
{
	// render
	// ------
	static float r = 0.0, g = 0.0, b = 0.0;
	r += 0.01;
	g += 0.02;
	b += 0.03;
	if (r > 1)r = 0;
	if (g > 1)g = 0;
	if (b > 1)b = 0;
	glClearColor(r, g, b, 1.0f);    //����
	glClear(GL_COLOR_BUFFER_BIT);

	// draw our first triangle
	glUseProgram(shaderProgram);
	VAO.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	VAO.release();
}