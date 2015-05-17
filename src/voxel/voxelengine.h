#ifndef VOXELENGINE_H
#define VOXELENGINE_H

class VoxelEngine;

#include "math3d.h"
#include "shader.h"
#include "world.h"
#include "fileutils.h"
#include "osutils.h"

class VoxelEngine
{

    public:
        VoxelEngine();
        ~VoxelEngine();
        void update();
        void render(float windowWidth, float windowHeight);
    protected:
    private:
        Shader* shader;
        World* world;

};

#endif // VOXELENGINE_H
