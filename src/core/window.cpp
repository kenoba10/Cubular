#include "window.h"

void sizeCallback(GLFWwindow* window, int width, int height)
{

    glViewport(0, 0, width, height);

}

Window::Window(Game* game)
{

    this->game = game;
    
    lastTickTime = 0.0;
    
    running = false;

    this->game->setWindow(this);

}

Window::~Window()
{

}

void Window::run()
{

    init();

    running = true;

    while(running)
    {

        if((glfwGetTime() - lastTickTime) >= (1.0 / TICKS_PER_SECOND))
        {
            
            lastTickTime = glfwGetTime();
            
            update();
            
        }
        
        render();

        if(glfwWindowShouldClose(window))
        {

            running = false;

        }

    }

    term();

}

int Window::getWidth() const
{

    int width;
    int height;

    glfwGetFramebufferSize(window, &width, &height);

    return width;

}

int Window::getHeight() const
{

    int width;
    int height;

    glfwGetFramebufferSize(window, &width, &height);

    return height;

}

Input& Window::getInput() const
{

    return *input;

}

bool Window::getRunning() const
{

    return running;

}

void Window::setInput(const Input& input)
{

    *(this->input) = input;

}

void Window::setRunning(bool running)
{

    this->running = running;

}

void Window::init()
{

    glfwInit();

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    glfwWindowHint(GLFW_DECORATED, GL_TRUE);
    glfwWindowHint(GLFW_FOCUSED, GL_TRUE);
    glfwWindowHint(GLFW_AUTO_ICONIFY, GL_TRUE);
    glfwWindowHint(GLFW_FLOATING, GL_FALSE);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_ACCUM_RED_BITS, 0);
    glfwWindowHint(GLFW_ACCUM_GREEN_BITS, 0);
    glfwWindowHint(GLFW_ACCUM_BLUE_BITS, 0);
    glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, 0);
    glfwWindowHint(GLFW_AUX_BUFFERS, 0);
    glfwWindowHint(GLFW_SAMPLES, 0);
    glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
    glfwWindowHint(GLFW_STEREO, GL_FALSE);
    glfwWindowHint(GLFW_SRGB_CAPABLE, GL_FALSE);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_NO_ROBUSTNESS);
    glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_ANY_RELEASE_BEHAVIOR);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1080, 720, "Cubular", nullptr, nullptr);
    input = new Input(window);

    glfwSetFramebufferSizeCallback(window, sizeCallback);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    glewInit();
    initGL();

    game->init();

}

void Window::update()
{

    glfwPollEvents();

    game->update();

    for(unsigned int i = 0; i < NUM_KEYS; i++)
    {

        input->setKey(i, glfwGetKey(window, i) == GLFW_PRESS);

    }

    for(unsigned int i = 0; i < NUM_MOUSEBUTTONS; i++)
    {

        input->setMouseButton(i, glfwGetMouseButton(window, i) == GLFW_PRESS);

    }

}

void Window::render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game->render();

    glfwSwapBuffers(window);

}

void Window::term()
{

    game->term();

    delete input;

    glfwDestroyWindow(window);

    glfwTerminate();

}

void Window::initGL()
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);

    glDepthFunc(GL_LESS);

}
