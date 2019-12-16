#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader
{

public:

	const char* vShaderCode;
	const char* fShaderCode;
	unsigned int ID;
	unsigned int vertexShader;
	unsigned int fragmentShader;

	void Create()
	{
		vShaderCode = LoadSource(VertextFileName);
		fShaderCode = LoadSource(FragmentFileName);

		Init();
	}

	void Use()
	{
		glUseProgram(ID);
	}

	// utility uniform functions
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

private:
	const string VertextFileName = "shader/vertexShaderSource.vert";
	const string FragmentFileName = "shader/fragmentShaderSource.vert";

	const char* LoadSource(string filePath)
	{
		ifstream file_reader(filePath);
		if (file_reader.is_open())
		{
			file_reader.open(filePath);
			std::stringstream shaderStream;
			// read file's buffer contents into streams
			shaderStream << file_reader.rdbuf();
			// close file handlers
			file_reader.close();
			// convert stream into string
			string shaderStr = shaderStream.str();
			return shaderStr.c_str();
		}
		else
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		return NULL;
	}

	void Init()
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vShaderCode, NULL);
		glCompileShader(vertexShader);
		checkCompileErrors(vertexShader, "VERTEX");

		// fragment Shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
		glCompileShader(fragmentShader);
		checkCompileErrors(fragmentShader, "FRAGMENT");

		// shader Program
		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);
		checkCompileErrors(ID, "PROGRAM");

		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}


	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}
};