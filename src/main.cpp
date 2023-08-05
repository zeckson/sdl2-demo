#include "Game.h"

int main() {
    Game game(App::init("SDL2 Shooter", SCREEN_WIDTH, SCREEN_HEIGHT));

    //main game/app loop
    while (game.run()) {
    }

    game.exit();

    return 0;
}
