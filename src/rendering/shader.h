#ifndef SHADER_H
#define SHADER_H

class Shader;

#include <iostream>
#include <string>
#include <GL/glew.h>

#include "math3d.h"

class Shader
{

    public:
        Shader(std::string vs, std::string gs, std::string fs);
        ~Shader();
        void bind();
        void unbind();
        void setUniform(std::string name, int value);
        void setUniform(std::string name, float value);
        void setUniform(std::string name, Vector2 value);
        void setUniform(std::string name, Vector3 value);
        void setUniform(std::string name, Vector4 value);
        void setUniform(std::string name, Matrix3 value);
        void setUniform(std::string name, Matrix4 value);
    protected:
    private:
        GLuint shader;

};

#endif // SHADER_H
