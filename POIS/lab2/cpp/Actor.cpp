#include "pch.h"
#include "Actor.h"

/*!
    \brief Implementation of the Actor class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for playing. Operator == for comparing the fields of two actors.
*/

/*!
    \brief Getter of Name
    \return Name
*/
string Actor::GetName() { return name; }

/*!
    \brief Getter of Role
    \return Role
*/
string Actor::GetRole() { return role; }

/*!
  \brief Overloading == operator
  \param actor other actor
  \return True if yes, False if no
*/
bool Actor::operator ==(Actor actor)
{
    return (name == actor.GetName() && role == actor.GetRole()) ? true : false;
}

/*!
    \brief Play actor role
*/
void Actor::Play() {
    cout << "Имя актера: " << name << ", Роль: " << role << endl;
}