#ifndef WINDOW_H
#define WINDOW_H

class Window;

#define TICKS_PER_SECOND 40

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "input.h"
#include "game.h"

class Window
{

    public:
        Window(Game* game);
        ~Window();
        void run();
        int getWidth() const;
        int getHeight() const;
        Input& getInput() const;
        bool getRunning() const;
        void setInput(const Input& input);
        void setRunning(bool running);
    protected:
    private:
        GLFWwindow* window;
        Input* input;
        Game* game;
        double lastTickTime;
        bool running;
        void init();
        void update();
        void render();
        void term();
        void initGL();

};

#endif // WINDOW_H
