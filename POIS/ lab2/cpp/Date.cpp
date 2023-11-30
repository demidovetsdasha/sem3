#include "pch.h"
#include "Date.h"

string Date::GetDate() {
    return to_string(hours) + ":" + to_string(minutes) + "\t" + to_string(day) + "." + to_string(month) + "." + to_string(year);
}

bool Date::operator ==(Date date) {
    return (hours == this->hours && minutes == this->minutes && day == this->day && month == this->month && year == this->year) ? true : false;
}