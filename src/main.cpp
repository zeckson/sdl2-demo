#include "Game.h"

int main() {
    Game game("SDL2 Shooter");

    game.init();

    //main game/app loop
    while (game.run()) {
    }

    game.exit();

    return 0;
}
