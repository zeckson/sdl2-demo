//
// Created by Evgenii Shchepotev on 15.11.2023.
//

#ifndef SDL2_DEMO_ACTION_H
#define SDL2_DEMO_ACTION_H

#include <vector>


enum class Action {
    PAUSE,
    RESUME,
    RESTART,
    QUIT
};

class ActionListener {
public:
    virtual void performAction(Action action) = 0;

    // Virtual destructor (recommended in abstract classes)
    virtual ~ActionListener() {}
};

class Subject {
public:
    void addListener(ActionListener *listener);

    void removeListener(ActionListener *listener);

    void notify(Action action);

private:
    std::vector<ActionListener *> listeners;
};


#endif //SDL2_DEMO_ACTION_H
