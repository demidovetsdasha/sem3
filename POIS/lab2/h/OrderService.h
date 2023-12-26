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

    Theatre ChooseTheatre(int index);

    Performance ChoosePerformance(Theatre theatre, int index);

    string ChoosePlace(Performance performance, int index);

    int ChoosePrice(int index);

public:
    OrderService(vector<Theatre> theatres) : theatres(theatres) {}
    Ticket OrderTicket(int theatreIndex, int performanceIndex, int placeIndex, int priceIndex);
};
