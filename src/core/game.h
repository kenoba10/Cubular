#ifndef GAME_H
#define GAME_H

class Game;

#include <iostream>

#include "window.h"
#include "shader.h"
#include "mesh.h"
#include "fileutils.h"
#include "osutils.h"

class Game
{

    public:
        Game();
        ~Game();
        void init();
        void update();
        void render();
        void term();
        void setWindow(Window* window);
    protected:
    private:
        Window* window;
        Shader* shader;
        Mesh* mesh;

};

#endif // GAME_H
