#ifndef VOXELENGINE_H
#define VOXELENGINE_H

class VoxelEngine;

#include "../core/window.h"
#include "../core/math3d.h"
#include "../rendering/shader.h"
#include "player.h"
#include "world.h"
#include "../utils/fileutils.h"
#include "../utils/osutils.h"

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
