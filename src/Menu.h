#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>
#include <vector>
#include "App.h"
#include "Action.h"

class Menu: public Subject {
public:
    explicit Menu(App* app);
    void render(SDL_Renderer* pRenderer);
    void handleEvent(const SDL_Event& event);
    void performAction();
    bool isActive() const { return active_; }
    void setActive(bool active) { active_ = active; }

private:
    App* app_;
    const std::vector<std::string>& menuItems_;
    int selectedItem_;
    bool active_ = false;
};

#endif
