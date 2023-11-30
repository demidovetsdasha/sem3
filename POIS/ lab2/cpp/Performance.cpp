#include "pch.h"
#include "Performance.h"

string Performance::GetName() { return name; }
string Performance::GetDate() { return date.GetDate(); }
int Performance::GetActorsCount() { return actors.size(); }
string Performance::GetPlace(int i) { return places[i].GetPlace(); }

void Performance::ShowPlaces() {
    for (int i = 0; i < places.size(); i++)
        if (places[i].IsEmpty()) 
            cout << "Ряд-место: " << places[i].GetPlace() << endl;
}

bool Performance::operator ==(Performance perfomance) {
    return (name == perfomance.GetName() && date.GetDate() == perfomance.GetDate()) ? true : false;
}

void Performance::Start()
{
    for (int i = 0; i < actors.size(); i++)
        actors[i].Play();
}

void Performance::AddActor(Actor actor) {
    actors.push_back(actor);
}

void Performance::RemoveActor(Actor actor) {
    for (int i = 0; i < actors.size(); i++)
        if (actors[i] == actor) actors.erase(actors.begin() + i);
}

void Performance::CreatePlaces(int row, int place)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < place; j++)
        {
            Place place(i+1, j+1);
            place.Cancel();
            places.push_back(place);
        }
    }
}