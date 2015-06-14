#include "world.h"

World::World()
{

    for(int i = -8; i < 8; i++)
    {

        for(int j = -8; j < 0; j++)
        {

            for(int k = -8; k < 8; k++)
            {

                setBlock(i, j, -k);

            }

        }

    }

}

World::~World()
{

    std::map<std::string, Chunk*>::iterator it = chunks.begin();

    while(it != chunks.end())
    {

        delete it->second;
        chunks.erase(it++);

    }

}

void World::update()
{

    for(std::map<std::string, Chunk*>::iterator it = chunks.begin(); it != chunks.end(); it++)
    {

        it->second->update();

    }

}

void World::render()
{

    for(std::map<std::string, Chunk*>::iterator it = chunks.begin(); it != chunks.end(); it++)
    {

        it->second->render();

    }

}

Chunk* World::getChunk(int x, int y, int z)
{

    float modifiedX = (float)x / (float)CHUNK_WIDTH;
    float modifiedY = (float)y / (float)CHUNK_WIDTH;
    float modifiedZ = (float)z / (float)CHUNK_WIDTH;

    int chunkX = (modifiedX < 0.0f) ? ceil(modifiedX - 0.5f) : floor(modifiedX + 0.5f);
    int chunkY = (modifiedY < 0.0f) ? ceil(modifiedY - 0.5f) : floor(modifiedY + 0.5f);
    int chunkZ = (modifiedZ < 0.0f) ? ceil(modifiedZ - 0.5f) : floor(modifiedZ + 0.5f);

    std::stringstream chunkName;
    chunkName << chunkX << std::endl << chunkY << std::endl << chunkZ;

    if(chunks.find(chunkName.str()) == chunks.end())
    {

        chunks[chunkName.str()] = new Chunk();

    }

    return chunks[chunkName.str()];

}

Block* World::getBlock(int x, int y, int z)
{

    return getChunk(x, y, z)->getBlock(x, y, z);

}

void World::setBlock(int x, int y, int z, bool air)
{

    getChunk(x, y, z)->setBlock(x, y, z, air);

}
