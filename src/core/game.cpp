#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{

    std::cout << "Initializing!\n";

    GLfloat vertices[9] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f};
    GLuint indicies[6] = {0, 1, 2};

    shader = new Shader(readFromFile(getInstallPath() + "assets/shaders/basicVS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicGS.glsl"), readFromFile(getInstallPath() + "assets/shaders/basicFS.glsl"));
    mesh = new Mesh(vertices, indicies, 3, 3);

}

void Game::update()
{

    std::cout << "Updating!\n";

}

void Game::render()
{

    std::cout << "Rendering!\n";

    shader->bind();

    mesh->draw();

    shader->unbind();

}

void Game::term()
{

    std::cout << "Terminating!\n";

}

void Game::setWindow(Window* window)
{

    this->window = window;

}
