#ifndef VOXELENGINE_H
#define VOXELENGINE_H

class VoxelEngine;

#include "window.h"
#include "math3d.h"
#include "shader.h"
#include "player.h"
#include "world.h"
#include "fileutils.h"
#include "osutils.h"

class VoxelEngine
{

    public:
        VoxelEngine(Window* window);
        ~VoxelEngine();
        void update();
        void render(float windowWidth, float windowHeight);
    protected:
    private:
        Window* window;
        Shader* shader;
        Player* player;
        World* world;

};

#endif // VOXELENGINE_H
