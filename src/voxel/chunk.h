#ifndef CHUNK_H
#define CHUNK_H

class Chunk;

#include <array>

#include "world.h"
#include "block.h"

class Chunk
{

    public:
        Chunk(int x, int y, int z);
        ~Chunk();
        void update();
        void render();
        Block* getBlock(int x, int y, int z);
        void setBlock(int x, int y, int z, bool air);
        int getBlocks() const;
        void markForRebuild();
        bool getGenerated() const;
        void setGenerated(bool generated);
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
    protected:
    private:
        Mesh* mesh;
        std::array<Block*, CHUNK_WIDTH * CHUNK_WIDTH * CHUNK_WIDTH> blocks;
        bool generated;
        bool rebuild;
        int x;
        int y;
        int z;

};

#endif // CHUNK_H
