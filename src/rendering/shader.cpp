#include "shader.h"

Shader::Shader(std::string vs, std::string gs, std::string fs)
{

    shader = glCreateProgram();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* vsArray[1];
    vsArray[0] = vs.c_str();

    const GLchar* gsArray[1];
    gsArray[0] = gs.c_str();

    const GLchar* fsArray[1];
    fsArray[0] = fs.c_str();

    glShaderSource(vertexShader, 1, vsArray, nullptr);
    glShaderSource(geometryShader, 1, gsArray, nullptr);
    glShaderSource(fragmentShader, 1, fsArray, nullptr);

    glCompileShader(vertexShader);

    GLint vertexShaderResult;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexShaderResult);

    if(vertexShaderResult == GL_FALSE)
    {

        int length;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);

        GLchar error[length];
        glGetShaderInfoLog(vertexShader, length, &length, error);

        std::cerr << error + '\n';

    }

    glCompileShader(geometryShader);

    GLint geometryShaderResult;
    glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &geometryShaderResult);

    if(geometryShaderResult == GL_FALSE)
    {

        int length;
        glGetShaderiv(geometryShader, GL_INFO_LOG_LENGTH, &length);

        GLchar error[length];
        glGetShaderInfoLog(geometryShader, length, &length, error);

        std::cerr << error + '\n';

    }

    glCompileShader(fragmentShader);

    GLint fragmentShaderResult;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentShaderResult);

    if(fragmentShaderResult == GL_FALSE)
    {

        int length;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);

        GLchar error[length];
        glGetShaderInfoLog(fragmentShader, length, &length, error);

        std::cerr << error + '\n';

    }

    glAttachShader(shader, vertexShader);
    glAttachShader(shader, geometryShader);
    glAttachShader(shader, fragmentShader);

    glLinkProgram(shader);
    glValidateProgram(shader);

    glDeleteShader(fragmentShader);
    glDeleteShader(geometryShader);
    glDeleteShader(vertexShader);

}

Shader::~Shader()
{

    glDeleteProgram(shader);

}

void Shader::bind()
{

    glUseProgram(shader);
}

void Shader::unbind()
{

    glUseProgram(0);

}

void Shader::setUniform(std::string name, int value)
{

    glUniform1i(glGetUniformLocation(shader, name.c_str()), value);

}

void Shader::setUniform(std::string name, float value)
{

    glUniform1f(glGetUniformLocation(shader, name.c_str()), value);

}

void Shader::setUniform(std::string name, Vector2 value)
{

    glUniform2f(glGetUniformLocation(shader, name.c_str()), value.getX(), value.getY());

}

void Shader::setUniform(std::string name, Vector3 value)
{

    glUniform3f(glGetUniformLocation(shader, name.c_str()), value.getX(), value.getY(), value.getZ());

}

void Shader::setUniform(std::string name, Vector4 value)
{

    glUniform4f(glGetUniformLocation(shader, name.c_str()), value.getX(), value.getY(), value.getZ(), value.getW());

}

void Shader::setUniform(std::string name, Matrix3 value)
{

    glUniformMatrix3fv(glGetUniformLocation(shader, name.c_str()), 1, GL_FALSE, value.getValues());

}

void Shader::setUniform(std::string name, Matrix4 value)
{

    glUniformMatrix4fv(glGetUniformLocation(shader, name.c_str()), 1, GL_FALSE, value.getValues());

}
