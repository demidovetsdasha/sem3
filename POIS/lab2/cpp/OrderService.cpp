#include "pch.h"
#include "OrderService.h"

/*!
    \brief Implementation of the OrderService class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for showing information and ordering tickets.
*/

/*!
  \brief Show list of avaible Theatres
*/
void OrderService::ShowTheatres() {
    for (int i = 0; i < theatres.size(); i++)
        cout << i + 1 << "." << theatres[i].GetName() << endl;
}

/*!
  \brief Show possible ticket price types
*/
void OrderService::ShowPrice() {
    cout << "1. Детский - 5 руб" << endl;
    cout << "2. Взрослый - 20 руб" << endl;
    cout << "3. Студенческий - 15 руб" << endl;
}

/*!
  \brief Choosing theatre
  \return theatre
*/
Theatre OrderService::ChooseTheatre() {
    cout << " Выберите театр: " << endl;
    ShowTheatres();
    int index;
    cin >> index;

    while (index > theatres.size())
    {
        cout << "Выберите снова!" << endl;
        cin.clear();
        cin >> index;
    }


    return theatres[index - 1];
}

/*!
  \brief Choosing performance
  \return performnce
*/
Performance OrderService::ChoosePerformance(Theatre theatre) {
    cout << " Выберите спектакль: " << endl;
    theatre.ShowAfisha();
    int index;
    cin >> index;
    return theatre.GetPerformance(index - 1);
}

/*!
  \brief Choosing Place (String format)
  \return place
*/
string OrderService::ChoosePlace(Performance performance) {
    cout << " Выберите место: " << endl;
    performance.ShowPlaces();
    int index;
    cin >> index;
    return performance.GetPlace(index - 1);
}

/*!
  \brief Choosing Price
  \return price index
*/
int OrderService::ChoosePrice()
{
    cout << " Выберите тип билета: " << endl;
    ShowPrice();
    int index;
    cin >> index;
    return ticketPrices[index - 1];
}

/*!
  \brief Order Ticket to visiting performance
  \return ticket
*/
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