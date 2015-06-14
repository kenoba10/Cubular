#include "chunk.h"

Chunk::Chunk()
{

    mesh = nullptr;

}

Chunk::~Chunk()
{

    std::map<std::string, Block*>::iterator it = blocks.begin();

    while(it != blocks.end())
    {

        delete it->second;
        blocks.erase(it++);

    }

    if(mesh != nullptr)
    {

        delete mesh;

    }

}

void Chunk::update()
{

    bool rebuild = this->rebuild;

    GLfloat* vertices = new GLfloat[BLOCK_VERTICES * blocks.size()];
    GLuint* indicies = new GLuint[BLOCK_INDICIES * blocks.size()];

    int index = 0;

    for(std::map<std::string, Block*>::iterator it = blocks.begin(); it != blocks.end(); it++)
    {

        it->second->update();

        if(rebuild)
        {

            GLfloat* blockVertices = it->second->getVertices();
            GLuint* blockIndicies = it->second->getIndicies();

            for(int i = 0; i < BLOCK_VERTICES; i++)
            {

                vertices[BLOCK_VERTICES * index + i] = blockVertices[i];

            }

            for(int i = 0; i < BLOCK_INDICIES; i++)
            {


                indicies[BLOCK_INDICIES * index + i] = blockIndicies[i] + BLOCK_VERTICES / 3 * index;

            }

            delete[] blockIndicies;
            delete[] blockVertices;

            index++;


        }

    }

    if(rebuild)
    {

        mesh = new Mesh(vertices, indicies, BLOCK_VERTICES * blocks.size(), BLOCK_INDICIES * blocks.size());

        this->rebuild = false;

    }

    delete[] indicies;
    delete[] vertices;

}

void Chunk::render()
{

    if(mesh != nullptr)
    {

        mesh->draw();

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

    return blocks[blockName.str()];

}

void Chunk::setBlock(int x, int y, int z, bool air)
{

    std::stringstream blockName;
    blockName << x << std::endl << y << std::endl << z;
    
    if(!air)
    {
        
        Block* block = new Block(x, y, z);
        blocks[blockName.str()] = block;
        
    }
    else
    {
        
        blocks.erase(blocks.find(blockName.str()));
        
    }

    markForRebuild();

}

void Chunk::markForRebuild()
{

    rebuild = true;

}
