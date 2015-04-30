#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window
{

    public:
        Window();
        ~Window();
        void run();
        bool getRunning() const;
        void setRunning(const bool& running);
    protected:
    private:
        GLFWwindow* window;
        bool running;
        void init();
        void update();
        void render();
        void term();

};

#endif // WINDOW_H
