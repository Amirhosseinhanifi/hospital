#include "game.hpp"

int main ()
{
    game gameO;

    while (gameO.is_full () == false)
    {
        gameO.update ();
        gameO.Render ();
    }

    return 0;
}