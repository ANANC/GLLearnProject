#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

class MyGL
{

private:
	int vertexShader;
	int fragmentShader;
	int shaderProgram;
	unsigned int VBO, VAO, EBO;

	float vertices[12] = {
				0.5f, 0.5f, 0.0f,   // ���Ͻ�
				0.5f, -0.5f, 0.0f,  // ���½�
				-0.5f, -0.5f, 0.0f, // ���½�
				-0.5f, 0.5f, 0.0f   // ���Ͻ�
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
