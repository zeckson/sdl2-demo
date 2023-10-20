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
    void Render();
    void HandleEvent(const SDL_Event& event);
    void PerformAction();
    bool Quit() const { return quit_; }
    void SetQuit(bool quit) { quit_ = quit; }

private:
    App* app_;
    const std::vector<std::string>& menuItems_;
    int selectedItem_;
    bool quit_ = false;
};

#endif
