#pragma once
#include <string>

using namespace std;

class Date
{
private:
    int hours;
    int minutes;
    int day;
    int month;
    int year;

public:
    Date(int hours, int minutes, int day, int month, int year) : hours(hours), minutes(minutes), day(day), month(month), year(year) {}

    string GetDate();

    bool operator ==(Date date);
};