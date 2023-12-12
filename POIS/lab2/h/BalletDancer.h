#pragma once
#include "Actor.h"

class BalletDancer : public Actor {
public:

    BalletDancer(string name, string role) : Actor(name, role) {}

    void Play() override;
};