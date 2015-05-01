#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"

class Window
{

    public:
        Window(Game* game);
        ~Window();
        void run();
        bool getRunning() const;
        void setRunning(const bool& running);
    protected:
    private:
        GLFWwindow* window;
        Game* game;
        bool running;
        void init();
        void update();
        void render();
        void term();
        void initGL();

};

#endif // WINDOW_H
