#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";


class MyGL
{

private:
	int vertexShader;
	int fragmentShader;
	int shaderProgram;
	unsigned int VBO, VAO, EBO;

	float vertices[12] = {
				0.5f, 0.5f, 0.0f,   // срио╫г
				0.5f, -0.5f, 0.0f,  // сроб╫г
				-0.5f, -0.5f, 0.0f, // вСоб╫г
				-0.5f, 0.5f, 0.0f   // вСио╫г
	};

	unsigned int indices[6] = {
				0, 1, 2,
				0, 2, 3
	};

public:
	void Init();
	void Shader();
	void Clean();

};
