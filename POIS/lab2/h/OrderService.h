#pragma once
#include <vector>
#include "Performance.h"
#include "Ticket.h"
#include "Theatre.h"

class OrderService {
private:
    vector<Theatre> theatres;
    int ticketPrices[3] = { 5, 20, 15 };

    void ShowTheatres();

    void ShowPrice();

    Theatre ChooseTheatre();

    Performance ChoosePerformance(Theatre theatre);

    string ChoosePlace(Performance performance);

    int ChoosePrice();

public:
    OrderService(vector<Theatre> theatres) : theatres(theatres) {}
    Ticket OrderTicket();
};