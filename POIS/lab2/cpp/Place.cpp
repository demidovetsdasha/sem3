#include "pch.h"
#include "Place.h"

/*!
    \brief Implementation of the Place class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for showing information and working with places.
*/

/*!
\brief Take this place
*/
void Place::Take() { isEmpty = false; }

/*!
\brief Cancel taking place
*/
void Place::Cancel() { isEmpty = true; }

/*!
\brief Getter of Place
\return place
*/
string Place::GetPlace() {
    return to_string(row) + "--" + to_string(place);
}

/*!
\brief Place is empty or not
\return True if yes, False if no
*/
bool Place::IsEmpty() { return isEmpty; }