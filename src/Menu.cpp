#include "Menu.h"
#include "App.h"

Menu::Menu(App *app): app_(app), menuItems_(*(new std::vector<std::string>({"Restart", "Quit"}))), selectedItem_(0) {}

void Menu::render(SDL_Renderer* pRenderer) {
    auto renderer_ = pRenderer;

    for (int i = 0; i < menuItems_.size(); i++) {
        if (i == selectedItem_) {
            SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        } else {
            SDL_SetRenderDrawColor(renderer_, 100, 100, 100, 255);
        }

        SDL_Rect itemRect = {app_->width / 4, app_->height / 4 + i * 50, app_->width / 2, 40};
        SDL_RenderFillRect(renderer_, &itemRect);

        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = app_->fontRenderer->renderSolidText(menuItems_[i].c_str(), textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);

        int textWidth = textSurface->w;
        int textHeight = textSurface->h;
        SDL_FreeSurface(textSurface);

        SDL_Rect textRect = {app_->width / 2 - textWidth / 2, itemRect.y + itemRect.h / 2 - textHeight / 2, textWidth, textHeight};
        SDL_RenderCopy(renderer_, textTexture, nullptr, &textRect);
        SDL_DestroyTexture(textTexture);
    }
}

void Menu::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                selectedItem_ = (selectedItem_ - 1 + menuItems_.size()) % menuItems_.size();
                break;
            case SDLK_DOWN:
                selectedItem_ = (selectedItem_ + 1) % menuItems_.size();
                break;
            case SDLK_RETURN:
            case SDLK_SPACE:
                performAction();
                break;
            case SDLK_ESCAPE:
                this->notify(Action::RESUME);
                break;
        }
    }
}

void Menu::performAction() {
    if (selectedItem_ == 0) {
        this->notify(Action::RESTART);
    } else if (selectedItem_ == 1) {
        this->notify(Action::QUIT);
    }
}
