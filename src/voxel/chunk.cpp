#include "chunk.h"

Chunk::Chunk(int x, int y, int z)
{
    
    this->x = x;
    this->y = y;
    this->z = z;

    mesh = nullptr;
    
    for(int i = 0; i < CHUNK_WIDTH * CHUNK_WIDTH * CHUNK_WIDTH; i++)
    {

        blocks[i] = nullptr;

    }
    
}

Chunk::~Chunk()
{

    for(int i = 0; i < CHUNK_WIDTH * CHUNK_WIDTH * CHUNK_WIDTH; i++)
    {

        delete blocks[i];

    }

    if(mesh != nullptr)
    {

        delete mesh;

    }

}

void Chunk::update()
{

    bool rebuild = this->rebuild;
    int blockAmount = getBlocks();

    GLfloat* vertices = new GLfloat[BLOCK_VERTICES * blockAmount];
    GLuint* indicies = new GLuint[BLOCK_INDICIES * blockAmount];
    
    int index = 0;

    for(int i = 0; i < CHUNK_WIDTH * CHUNK_WIDTH * CHUNK_WIDTH; i++)
    {

        Block* block = blocks[i];
        
        if(block != nullptr)
        {
        
            block->update();

            if(rebuild)
            {

                GLfloat* blockVertices = block->getVertices();
                GLuint* blockIndicies = block->getIndicies();

                for(int j = 0; j < BLOCK_VERTICES; j++)
                {

                    vertices[BLOCK_VERTICES * index + j] = blockVertices[j];

                }

                for(int j = 0; j < BLOCK_INDICIES; j++)
                {


                    indicies[BLOCK_INDICIES * index + j] = blockIndicies[j] + BLOCK_VERTICES / 3 * index;

                }

                delete[] blockIndicies;
                delete[] blockVertices;


            }
            
            index++;
        
        }

    }

    if(rebuild)
    {

        mesh = new Mesh(vertices, indicies, BLOCK_VERTICES * blockAmount, BLOCK_INDICIES * blockAmount);

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

    int modifiedX = (x + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    int modifiedY = (y + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    int modifiedZ = (z + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    
    int blockX = (modifiedX < 0.0f) ? -1 * modifiedX : modifiedX;
    int blockY = (modifiedY < 0.0f) ? -1 * modifiedY : modifiedY;
    int blockZ = (modifiedZ < 0.0f) ? -1 * modifiedZ : modifiedZ;
    
    return blocks[blockX * CHUNK_WIDTH * CHUNK_WIDTH + blockY * CHUNK_WIDTH + blockZ];

}

void Chunk::setBlock(int x, int y, int z, bool air)
{
    
    int modifiedX = (x + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    int modifiedY = (y + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    int modifiedZ = (z + CHUNK_WIDTH / 2) % CHUNK_WIDTH;
    
    int blockX = (modifiedX < 0.0f) ? -1 * modifiedX : modifiedX;
    int blockY = (modifiedY < 0.0f) ? -1 * modifiedY : modifiedY;
    int blockZ = (modifiedZ < 0.0f) ? -1 * modifiedZ : modifiedZ;
    
    if(!air)
    {
        
        Block* block = new Block(x, y, z);
        delete blocks[blockX * CHUNK_WIDTH * CHUNK_WIDTH + blockY * CHUNK_WIDTH + blockZ];
        blocks[blockX * CHUNK_WIDTH * CHUNK_WIDTH + blockY * CHUNK_WIDTH + blockZ] = block;
        
    }
    else
    {
        
        delete blocks[blockX * CHUNK_WIDTH * CHUNK_WIDTH + blockY * CHUNK_WIDTH + blockZ];
        blocks[blockX * CHUNK_WIDTH * CHUNK_WIDTH + blockY * CHUNK_WIDTH + blockZ] = nullptr;
        
    }

    markForRebuild();

}

int Chunk::getBlocks() const
{
    
    int blockAmount = 0;
    
    for(int i = 0; i < CHUNK_WIDTH * CHUNK_WIDTH * CHUNK_WIDTH; i++)
    {

        if(blocks[i] != nullptr)
        {
            
            blockAmount++;
            
        }

    }
    
    return blockAmount;
    
}

void Chunk::markForRebuild()
{

    rebuild = true;

}

bool Chunk::getGenerated() const
{
    
    return generated;
    
}

void Chunk::setGenerated(bool generated)
{
    
    this->generated = generated;
    
}

int Chunk::getX() const
{

    return x;

}

int Chunk::getY() const
{

    return y;

}

int Chunk::getZ() const
{

    return z;

}

void Chunk::setX(int x)
{

    this->x = x;

}

void Chunk::setY(int y)
{

    this->y = y;

}

void Chunk::setZ(int z)
{

    this->z = z;

}
