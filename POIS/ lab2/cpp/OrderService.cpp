#include "pch.h"
#include "OrderService.h"

void OrderService::ShowTheatres() {
    for (int i = 0; i < theatres.size(); i++)
        cout << i + 1 << "." << theatres[i].GetName() << endl;
}

void OrderService::ShowPrice() {
    cout << "1. Äåòñêèé" << endl;
    cout << "2. Âçðîñëûé" << endl;
    cout << "3. Ñòóäåí÷åñêèé" << endl;
}

Theatre OrderService::ChooseTheatre() {
    cout << " Âûáåðèòå òåàòð: " << endl;
    ShowTheatres();
    int index;
    cin >> index;
    return theatres[index - 1];
}

Performance OrderService::ChoosePerformance(Theatre theatre) {
    cout << " Âûáåðèòå ñïåêòàêëü: " << endl;
    theatre.ShowAfisha();
    int index;
    cin >> index;
    return theatre.GetPerformance(index - 1);
}

string OrderService::ChoosePlace(Performance performance) {
    cout << " Âûáåðèòå ìåñòî: " << endl;
    performance.ShowPlaces();
    int index;
    cin >> index;
    return performance.GetPlace(index - 1);
}

int OrderService::ChoosePrice()
{
    cout << " Âûáåðèòå òèï áèëåòà: " << endl;
    ShowPrice();
    int index;
    cin >> index;
    return ticketPrices[index - 1];
}

Ticket OrderService::OrderTicket() {
    Theatre theatre = ChooseTheatre();
    Performance performance = ChoosePerformance(theatre);
    string place = ChoosePlace(performance);
    int price = ChoosePrice();

    Ticket ticket(performance, place, price);
    ticket.ShowInfo();

    theatre.StartPeroformance(ticket);
    return ticket;
}
