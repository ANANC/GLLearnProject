#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

class MyGL
{

private:
	Shader* shaderSource;

	//int vertexShader;
	//int fragmentShader;
	//int shaderProgram;
	unsigned int VBO, VAO, EBO;

	float vertices[12] = {
				0.5f, 0.5f, 0.0f,   // ÓÒÉÏ½Ç
				0.5f, -0.5f, 0.0f,  // ÓÒÏÂ½Ç
				-0.5f, -0.5f, 0.0f, // ×óÏÂ½Ç
				-0.5f, 0.5f, 0.0f   // ×óÉÏ½Ç
	};

	unsigned int indices[6] = {
				0, 1, 2,
				0, 2, 3
	};

public:

	MyGL()
	{
		shaderSource = new Shader();
		shaderSource->Create();
	}

	void Init();
	void LinkShader();
	void Draw();
	void Clean();

};
