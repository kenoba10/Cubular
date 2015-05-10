#include "game.h"
#include "window.h"

int main()
{

    Game game;
    Window window(&game);

    window.run();

    return 0;

}
