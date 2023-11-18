//
// Created by Evgenii Shchepotev on 15.11.2023.
//

#include "Action.h"

void Subject::removeListener(ActionListener *listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void Subject::addListener(ActionListener *listener) {
    listeners.push_back(listener);
}

void Subject::notify(Action action) {
    for (ActionListener* listener : listeners) {
        listener->performAction(action);
    }
}
