#include "voxelengine.h"

VoxelEngine::VoxelEngine(Window* window)
{

    this->window = window;
    shader = new Shader(readFromFile(getInstallPath() + "assets/shaders/basicVS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicGS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicFS.glsl"));
    player = new Player(window);
    world = new World(player);

}

VoxelEngine::~VoxelEngine()
{

    delete world;
    delete player;
    delete shader;

}

void VoxelEngine::update()
{

    player->update();
    world->update();

}

void VoxelEngine::render(float windowWidth, float windowHeight)
{

    shader->bind();

    Matrix4 projectionMatrix;
    projectionMatrix.createPerspective(70.0f, windowWidth / windowHeight, 0.1f, 256.0f);
    shader->setUniform("projection", projectionMatrix);

    Matrix4 viewMatrix;
    viewMatrix = player->getViewMatrix();
    shader->setUniform("view", viewMatrix);

    world->render();

    shader->unbind();

}
