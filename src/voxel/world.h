#ifndef WORLD_H
#define WORLD_H

class World;

#define CHUNK_WIDTH 16

#include <map>
#include <array>
#include <math.h>

#include "../core/math3d.h"
#include "player.h"
#include "chunk.h"
#include "block.h"

class World
{

    public:
        World(Player* player);
        ~World();
        void update();
        void render();
        Chunk* getChunk(int x, int y, int z);
        void setChunk(int x, int y, int z);
        Block* getBlock(int x, int y, int z);
        void setBlock(int x, int y, int z, bool air = false);
    protected:
    private:
        Player* player;
        std::map<std::array<int, 3>, Chunk*> chunks;
        void generate(Chunk& chunk);
        bool isInViewFrustum(const Chunk& chunk) const;

};

#endif // WORLD_H
