#include "pch.h"
#include "BalletDancer.h"

/*!
    \brief Implementation of the BalletDancer class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for playing.
*/

/*!
  \brief Play balletdancer role 
*/
void BalletDancer::Play() {
    cout << "Имя балерины: " << name << ", Роль: " << GetRole(); << endl;
}
