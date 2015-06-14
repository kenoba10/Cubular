#ifndef CHUNK_H
#define CHUNK_H

class Chunk;

#include <sstream>
#include <map>
#include <list>

#include "world.h"
#include "block.h"

class Chunk
{

    public:
        Chunk();
        ~Chunk();
        void update();
        void render();
        Block* getBlock(int x, int y, int z);
        void setBlock(int x, int y, int z, bool air);
        void markForRebuild();
    protected:
    private:
        std::map<std::string, Block*> blocks;
        Mesh* mesh;
        bool rebuild;

};

#endif // CHUNK_H
