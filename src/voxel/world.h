#ifndef WORLD_H
#define WORLD_H

class World;

#define WORLD_WIDTH 262144
#define CHUNK_WIDTH 16

#include <sstream>
#include <map>
#include <math.h>

#include "../core/math3d.h"
#include "chunk.h"
#include "block.h"

class World
{

    public:
        World();
        ~World();
        void update();
        void render();
        Chunk* getChunk(int x, int y, int z);
        Block* getBlock(int x, int y, int z);
        void setBlock(int x, int y, int z, bool air = false);
    protected:
    private:
        std::map<std::string, Chunk*> chunks;

};

#endif // WORLD_H
