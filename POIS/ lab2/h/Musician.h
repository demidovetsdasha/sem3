#pragma once
#include "Actor.h"

class Musician : public Actor {
public:
    string instrument;

    Musician(string name, string instrument) : Actor(name, instrument), instrument(instrument) {}

    void Play() override;
};