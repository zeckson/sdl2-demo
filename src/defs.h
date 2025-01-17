//
// Created by Evgenii Shchepotev on 23.07.2023.
//

#ifndef SDL2_DEMO_DEFS_H
#define SDL2_DEMO_DEFS_H

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720
#define FPS            60
#define RENDER_DELAY   (1000 / FPS) // 1000 / 60 FPS = 16,6667 ms per one frame

#define PLAYER_WIDTH   100
#define PLAYER_HEIGHT  100
#define PLAYER_SPEED   (PLAYER_WIDTH / 4)

#define PLAYER_TEXTURE_PATH     "gfx/sambik.png"
#define ENEMY_TEXTURE_PATH      "gfx/tank.png"
#define FIREBALL_TEXTURE_PATH   "gfx/fireball.png"
#define FONT_PATH               "gfx/glitchgoblin.ttf"
#define DEFAULT_FONT_SIZE       24

enum Texture {
    PLAYER = 0,
    FIREBALL = 1,
    ENEMY = 2
};

#endif //SDL2_DEMO_DEFS_H
