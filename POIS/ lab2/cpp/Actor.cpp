#include "pch.h"
#include "Actor.h"

string Actor::GetName() { return name; }
string Actor::GetRole() { return role; }


bool Actor::operator ==(Actor actor)
{
    return (name == actor.GetName() && role == actor.GetRole()) ? true : false;
}

void Actor::Play() {
    cout << "Имя актера: " << name << ", Роль: " << role << endl;
}