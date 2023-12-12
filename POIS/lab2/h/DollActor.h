#pragma once
#include "Actor.h"

class DollActor : public Actor {
public:

    DollActor(string name, string role) : Actor(name, role) {}

    void Play() override;
};