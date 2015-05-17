#ifndef BLOCK_H
#define BLOCK_H

class Block;

#include "math3d.h"
#include "mesh.h"

class Block
{

    public:
        Block();
        Block(int x, int y, int z);
        ~Block();
        void update();
        void render();
        void updateMesh();
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
    protected:
    private:
        Mesh* mesh;
        int x;
        int y;
        int z;

};

#endif // BLOCK_H
