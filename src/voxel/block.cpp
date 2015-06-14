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

}

Block::~Block()
{

}

void Block::update()
{

}

GLfloat* Block::getVertices() const
{

    return new GLfloat[BLOCK_VERTICES] {-0.5f + x, -0.5f + y, 0.5f + z, -0.5f + x, 0.5f + y, 0.5f + z, 0.5f + x, 0.5f + y, 0.5f + z, 0.5f + x, -0.5f + y, 0.5f + z, -0.5f + x, -0.5f + y, -0.5f + z, -0.5f + x, 0.5f + y, -0.5f + z, 0.5f + x, 0.5f + y, -0.5f + z, 0.5f + x, -0.5f + y, -0.5f + z};

}

GLuint* Block::getIndicies() const
{

    return new GLuint[BLOCK_INDICIES] {0, 1, 2, 0, 2, 3, 5, 1, 0, 5, 0, 4, 2, 6, 7, 2, 7, 3, 7, 4, 0, 3, 7, 0, 1, 5, 6, 1, 6, 2, 6, 5, 4, 7, 6, 4};

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
