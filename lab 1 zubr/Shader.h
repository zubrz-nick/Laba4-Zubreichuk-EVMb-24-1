#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glew-2.1.0/include/GL/glew.h"
using namespace std;
class Shader
{
public:
    int ID;

    Shader(const char* vertexPath, const char* fragmentPath)
    {
        string vertexCode;
        ifstream vShaderFile;
        vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        try
        {
            vShaderFile.open(vertexPath);
            stringstream vShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            vShaderFile.close();
            vertexCode = vShaderStream.str();
        }
        catch (ifstream::failure& e)
        {
            cout << "ERROR::SHADER::VERTEX::FILE_NOT_SUCCESFULLY_READ: " << e.what() << endl;
        }
        const char* vShaderCode = vertexCode.c_str();

  
        string fragmentCode;
        ifstream fShaderFile;
        fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        try
        {
            fShaderFile.open(fragmentPath);
            stringstream fShaderStream;
            fShaderStream << fShaderFile.rdbuf();
            fShaderFile.close();
            fragmentCode = fShaderStream.str();
        }
        catch (ifstream::failure& e)
        {
            cout << "ERROR::SHADER::FRAGMENT::FILE_NOT_SUCCESFULLY_READ: " << e.what() << endl;
        }
        const char* fShaderCode = fragmentCode.c_str();


        int vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");


        int fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");


        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

    }

    void use() const
    {
        glUseProgram(ID);
    }

    void setVec4(const string& name, float r, float g, float b, float a) const
    {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), r, g, b, a);
    }

private:

    void checkCompileErrors(unsigned int shader, string type)
    {
        GLint success;
        GLchar infoLog[1024];

        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"<< infoLog << "\n" << endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n"<< endl;
            }
        }
    }
};

#endif