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

void VoxelEngine::update(float windowWidth, float windowHeight)
{

    player->update();
    
    shader->bind();

    Matrix4 projectionMatrix;
    projectionMatrix.createPerspective(70.0f, windowWidth / windowHeight, 0.1f, 256.0f);
    shader->setUniform("projection", projectionMatrix);

    Matrix4 viewMatrix;
    viewMatrix = player->getViewMatrix();
    shader->setUniform("view", viewMatrix);

    shader->unbind();
    
    player->getFrustum().setProjectionMatrix(projectionMatrix);
    player->getFrustum().setViewMatrix(viewMatrix);
    player->getFrustum().calculateFrustum();
    
    world->update();

}

void VoxelEngine::render()
{

    shader->bind();

    world->render();

    shader->unbind();

}
