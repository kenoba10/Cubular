#include "chunk.h"

Chunk::Chunk()
{

}

Chunk::~Chunk()
{

}

void Chunk::update()
{

    for(auto iterator : blocks)
    {

        iterator.second.update();

    }

}

void Chunk::render()
{

    for(auto iterator : blocks)
    {

        iterator.second.render();

    }

}

Block* Chunk::getBlock(int x, int y, int z)
{

    std::stringstream blockName;
    blockName << x << std::endl << y << std::endl << z;

    if(blocks.find(blockName.str()) == blocks.end())
    {

        return nullptr;

    }

    return &blocks[blockName.str()];

}

void Chunk::setBlock(int x, int y, int z)
{

    std::stringstream blockName;
    blockName << x << std::endl << y << std::endl << z;

    Block block(x, y, z);

    blocks[blockName.str()] = block;

}
