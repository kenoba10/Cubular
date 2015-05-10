#ifndef MESH_H
#define MESH_H

class Mesh;

#include <GL/glew.h>

class Mesh
{

    public:
        Mesh(GLfloat vertices[], GLuint indicies[], GLsizei vertexCount, GLsizei indexCount);
        ~Mesh();
        void draw();
    protected:
    private:
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        GLsizei vertexCount;
        GLsizei indexCount;

};

#endif // MESH_H
