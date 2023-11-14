#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include "App.h"

class Menu {
public:
    Menu(App* app, const std::vector<std::string>& items);
    void render();
    void handleEvent(const SDL_Event& event);
    void performAction();
    bool quit() const { return quit_; }
    void setQuit(bool quit) { quit_ = quit; }

private:
    App* app_;
    const std::vector<std::string>& menuItems_;
    int selectedItem_;
    bool quit_ = false;
};

#endif
