#include "block.h"

Block::Block()
{

    Block(0, 0, 0);

}

Block::Block(int x, int y, int z)
{

    this->x = x;
    this->y = y;
    this->z = z;

    updateMesh();

}

Block::~Block()
{

    updateMesh();
    delete mesh;

}

void Block::update()
{

}

void Block::render()
{

    mesh->draw();

}

void Block::updateMesh()
{

    GLfloat vertices[12] = {-0.5f + x, -0.5f + y, 0.5f + z, -0.5f + x, 0.5f + y, 0.5f + z, 0.5f + x, 0.5f + y, 0.5f + z, 0.5f + x, -0.5f + y, 0.5f + z};
    GLuint indicies[6] = {0, 1, 2, 0, 2, 3};

    mesh = new Mesh(vertices, indicies, 4, 6);

}

int Block::getX() const
{

    return x;

}

int Block::getY() const
{

    return y;

}

int Block::getZ() const
{

    return z;

}

void Block::setX(int x)
{

    this->x = x;

}

void Block::setY(int y)
{

    this->y = y;

}

void Block::setZ(int z)
{

    this->z = z;

}
