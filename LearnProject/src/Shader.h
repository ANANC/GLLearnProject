#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Shader
{

public:
	string GetVertexShaderSource()
	{
		return LoadSource(VertextFileName);
	}

	string GetFragmentShaderSource()
	{
		return LoadSource(FragmentFileName);
	}

private:

	const string VertextFileName = "shader/vertexShaderSource.vert";
	const string FragmentFileName = "shader/fragmentShaderSource.vert";

	string LoadSource(string fileName)
	{
		string source;
		ifstream file_reader(fileName);
		if (file_reader.is_open())
		{
			while (file_reader.peek() != EOF)
			{
				string line;
				getline(file_reader, line, '\n');
				source += line;
			}
			file_reader.close();
		}
		return source;
	}
};