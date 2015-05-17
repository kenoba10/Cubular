#include "voxelengine.h"

VoxelEngine::VoxelEngine()
{

    shader = new Shader(readFromFile(getInstallPath() + "assets/shaders/basicVS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicGS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicFS.glsl"));
    world = new World();

}

VoxelEngine::~VoxelEngine()
{

    delete world;
    delete shader;

}

void VoxelEngine::update()
{

    world->update();

}

void VoxelEngine::render(float windowWidth, float windowHeight)
{

    shader->bind();

    Matrix4 projectionMatrix;
    projectionMatrix.createPerspective(70.0f, windowWidth / windowHeight, 0.1f, 512.0f);
    shader->setUniform("projection", projectionMatrix);

    world->render();

    shader->unbind();

}
