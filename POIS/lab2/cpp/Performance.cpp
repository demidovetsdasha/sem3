#include "pch.h"
#include "Performance.h"

/*!
    \brief Implementation of the Performmance class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for showing information and starting performances.
*/

/*!
  \brief Getter of Name
  \return Name
*/
string Performance::GetName() { return name; }
/*!
  \brief Getter of Date
  \return date
*/
string Performance::GetDate() { return date.GetDate(); }
/*!
  \brief Getter of Actors count
  \return actors count
*/
int Performance::GetActorsCount() { return actors.size(); }

/*!
  \brief Take place
  \return place
*/
string Performance::GetPlace(int i) { return places[i].GetPlace();
}

/*!
  \brief Show list avaible places
*/
void Performance::ShowPlaces() {
    /*for (int i = 0; i < places.size(); i++)
        if (places[i].IsEmpty()) 
            cout << "Ряд-Место: " << places[i].GetPlace() << endl;
*/
}

/*!
  \brief Overloading == operator
  \param performance other performance
  \return True if yes, False if no
*/
bool Performance::operator ==(Performance perfomance) {
    return (name == perfomance.GetName() && date.GetDate() == perfomance.GetDate()) ? true : false;
}

/*!
  \brief Start performance
*/
void Performance::Start()
{
    for (int i = 0; i < actors.size(); i++)
        actors[i].Play();
}

/*!
  \brief Add new actor
  \param actor new actor
*/
void Performance::AddActor(Actor actor) {
  if (std::find(actors.begin(), actors.end(), actor) == actors.end()) 
    actors.push_back(actor);
}

/*!
\brief Remove actor
\param actor removable actor
*/
void Performance::RemoveActor(Actor actor) {
  actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end());
}

/*!
\brief Initialize size of hall
\param row, place size
*/
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
