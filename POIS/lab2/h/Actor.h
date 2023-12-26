#pragma once

#include <iostream>

using namespace std;

class Actor {
private:
    string name;
    string role;
public:
    Actor(string name, string role) : name(name), role(role) {}

    string GetName();
    string GetRole();


    bool operator ==(Actor actor);

    void virtual Play();
};
