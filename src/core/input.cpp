#include "input.h"

Input::Input(GLFWwindow* window)
{

    this->window = window;

}

Input::~Input()
{

}

bool Input::getKey(unsigned int key) const
{

    return glfwGetKey(window, key) == GLFW_PRESS;

}

bool Input::getKeyDown(unsigned int key) const
{

    return (glfwGetKey(window, key) == GLFW_PRESS) && !keysDown[key];

}

bool Input::getKeyUp(unsigned int key) const
{

    return (glfwGetKey(window, key) == GLFW_RELEASE) && keysDown[key];

}

bool Input::getMouseButton(unsigned int button) const
{

    return glfwGetMouseButton(window, button) == GLFW_PRESS;

}

bool Input::getMouseButtonDown(unsigned int button) const
{

    return (glfwGetMouseButton(window, button) == GLFW_PRESS) && !mousebuttonsDown[button];

}

bool Input::getMouseButtonUp(unsigned int button) const
{

    return (glfwGetMouseButton(window, button) == GLFW_RELEASE) && mousebuttonsDown[button];

}

int Input::getMouseX() const
{

    double x;
    double y;

    glfwGetCursorPos(window, &x, &y);

    return x;

}

int Input::getMouseY() const
{

    double x;
    double y;

    glfwGetCursorPos(window, &x, &y);

    return y;

}

void Input::setKey(unsigned int key, bool enabled)
{

    keysDown[key] = enabled;

}

void Input::setMouseButton(unsigned int button, bool enabled)
{

    mousebuttonsDown[button] = enabled;

}

void Input::setMouseX(int x)
{

    glfwSetCursorPos(window, x, getMouseY());

}

void Input::setMouseY(int y)
{

    glfwSetCursorPos(window, getMouseX(), y);

}

void Input::setCursor(bool enabled)
{

    glfwSetInputMode(window, GLFW_CURSOR, enabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);

}
