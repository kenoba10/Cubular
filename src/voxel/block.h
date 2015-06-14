#ifndef BLOCK_H
#define BLOCK_H

class Block;

#define BLOCK_VERTICES 24
#define BLOCK_INDICIES 36

#include "../rendering/mesh.h"

class Block
{

    public:
        Block();
        Block(int x, int y, int z);
        ~Block();
        void update();
        GLfloat* getVertices() const;
        GLuint* getIndicies() const;
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
    protected:
    private:
        int x;
        int y;
        int z;

};

#endif // BLOCK_H
