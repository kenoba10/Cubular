#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{

    voxelEngine = new VoxelEngine(window);

}

void Game::update()
{

    voxelEngine->update();

}

void Game::render()
{

    voxelEngine->render(window->getWidth(), window->getHeight());

}

void Game::term()
{

    delete voxelEngine;

}

void Game::setWindow(Window* window)
{

    this->window = window;

}
