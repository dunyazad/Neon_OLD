#pragma once

#include <Neon/GraphicsAPI/Shader/NeonShader.h>
#include <Neon/Core/NeonFile.h>

namespace Neon {

    NeonShader::NeonShader(const string& vertexPath, const string& fragmentPath)
    {
        NeonFile vertexFile;
        vertexFile.Open(vertexPath, false);

        if (vertexFile.isOpen() == false) {
            std::cout << "Failed to open vertex shader file" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string vertexSource = vertexFile.ReadAll();
        const char* vertexSourcePtr = vertexSource.c_str();

        NeonFile fragmentFile;
        fragmentFile.Open(fragmentPath, false);

        if (fragmentFile.isOpen() == false) {
            std::cout << "Failed to open fragment shader file" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string fragmentSource = fragmentFile.ReadAll();
        const char* fragmentSourcePtr = fragmentSource.c_str();

        // Compile the shaders
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSourcePtr, NULL);
        glCompileShader(vertexShader);
        checkCompileErrors(vertexShader, "VERTEX");

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSourcePtr, NULL);
        glCompileShader(fragmentShader);
        checkCompileErrors(fragmentShader, "FRAGMENT");

        // Link the shader program
        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);
        glLinkProgram(m_ID);
        checkCompileErrors(m_ID, "PROGRAM");

        // Delete the shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    NeonShader::~NeonShader()
    {
        glDeleteProgram(m_ID);
    }

    void NeonShader::use()
    {
        glUseProgram(m_ID);
    }

    void NeonShader::setInt(const string& name, int value)
    {
        glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
    }

    void NeonShader::setFloat(const string& name, float value)
    {
        glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
    }

    void NeonShader::checkCompileErrors(unsigned int shader, const string& type)
    {
        int success;
        char infoLog[1024];
        if (type == "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "Failed to compile shader of type " << type << std::endl;
                std::cout << infoLog << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "Failed to link shader program" << std::endl;
                std::cout << infoLog << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

}