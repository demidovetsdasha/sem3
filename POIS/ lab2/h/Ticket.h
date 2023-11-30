#pragma once
#include <string>
#include "Performance.h"

using namespace std;

class Ticket {
private:
    Performance performance;
    string place;
    double price;

public:
    Ticket(Performance performance, string place, int price) :performance(performance), place(place), price(price) {}

    Performance GetPerformance();

    void ShowInfo();
};