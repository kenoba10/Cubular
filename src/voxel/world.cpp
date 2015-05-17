#include "world.h"

World::World()
{

    setBlock(0, 0, -5);
    setBlock(1, 1, -4);

}

World::~World()
{

}

void World::update()
{

    for(auto iterator : chunks)
    {

        iterator.second.update();

    }

}

void World::render()
{

    for(auto iterator : chunks)
    {

        iterator.second.render();

    }

}

Chunk* World::getChunk(int x, int y, int z)
{

    int chunkX = round(x / CHUNK_WIDTH);
    int chunkY = round(y / CHUNK_WIDTH);
    int chunkZ = round(z / CHUNK_WIDTH);

    std::stringstream chunkName;
    chunkName << chunkX << std::endl << chunkY << std::endl << chunkZ;

    if(chunks.find(chunkName.str()) == chunks.end())
    {

        chunks[chunkName.str()] = Chunk();

    }

    return &chunks[chunkName.str()];

}

Block* World::getBlock(int x, int y, int z)
{

    return getChunk(x, y, z)->getBlock(x, y, z);

}

void World::setBlock(int x, int y, int z)
{

    getChunk(x, y, z)->setBlock(x, y, z);

}
