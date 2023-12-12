#pragma once
#include <string>
#include "Date.h"
#include <vector>
#include "Place.h"
#include "Actor.h"


using namespace std;

class Performance {
private:
    string name;
    Date date;
    vector<Actor> actors;
    vector<Place> places;
public:
    Performance(string name, Date date) : name(name), date(date) {}

    string GetName();
    string GetDate();
    int GetActorsCount();
    string GetPlace(int i);

    void ShowPlaces();

    bool operator ==(Performance perfomance);

    void Start();

    void AddActor(Actor actor);

    void RemoveActor(Actor actor);

    void CreatePlaces(int row, int place);
};