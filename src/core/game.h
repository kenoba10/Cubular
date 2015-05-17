#ifndef GAME_H
#define GAME_H

class Game;

#include "window.h"
#include "voxelengine.h"

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
        VoxelEngine* voxelEngine;

};

#endif // GAME_H
