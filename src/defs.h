//
// Created by Evgenii Shchepotev on 23.07.2023.
//

#ifndef SDL2_DEMO_DEFS_H
#define SDL2_DEMO_DEFS_H

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720
#define RENDER_DELAY   16 // 1000 / 60 FPS = 16,6667 ms per one frame
#define PLAYER_TEXTURE_PATH "gfx/spaceship.png"
#define FIREBALL_TEXTURE_PATH "gfx/fireball.png"

enum Texture {
    PLAYER = 0,
    FIREBALL = 1
};

#endif //SDL2_DEMO_DEFS_H
