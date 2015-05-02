#ifndef GAME_H
#define GAME_H

class Game;

#include <iostream>

#include "window.h"

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

};

#endif // GAME_H
