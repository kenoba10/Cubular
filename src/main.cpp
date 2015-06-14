#include "core/game.h"
#include "core/window.h"

int main()
{

    Game game;
    Window window(&game);

    window.run();

    return 0;

}
