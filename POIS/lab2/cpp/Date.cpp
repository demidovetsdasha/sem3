#include "pch.h"
#include "Date.h"

/*!
    \brief Implementation of the Date class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for showing information. Operator == for comparing the fields of two dates.
*/

/*!
  \brief Getter of Date
  \return date
*/
string Date::GetDate() {
    return to_string(hours) + ":" + to_string(minutes) + "\t" + to_string(day) + "." + to_string(month) + "." + to_string(year);
}

/*!
  \brief Overloading == operator
  \param date other date
  \return True if yes, False if no
*/
bool Date::operator ==(Date date) {
    return (hours == this->hours && minutes == this->minutes && day == this->day && month == this->month && year == this->year) ? true : false;
}