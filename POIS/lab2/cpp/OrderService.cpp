#include "pch.h"
#include "OrderService.h"

/*!
    \brief Implementation of the OrderService class
    \author Dasha
    \version 1.1
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
  \param index index of the theatre
  \return theatre
*/
Theatre OrderService::ChooseTheatre(int index) {
    //cout << " Театры: " << endl;
    //ShowTheatres();

    return theatres[index - 1];
}

/*!
  \brief Choosing performance
  \param theatre choosed theatre,index index of performance in Afisha
  \return performnce
*/
Performance OrderService::ChoosePerformance(Theatre theatre, int index) {
    //cout << " Афиша спектаклей: " << endl;
    //theatre.ShowAfisha();
    return theatre.GetPerformance(index - 1);
}

/*!
  \brief Choosing Place (String format)
  \param performance choosed performance,index index of the place in the hall
  \return place
*/
string OrderService::ChoosePlace(Performance performance, int index) {
    //cout << " Свободные места: " << endl;
    //performance.ShowPlaces();
    return performance.GetPlace(index - 1);
}

/*!
  \brief Choosing Price
  \param index index of the ticket type
  \return price index
*/
int OrderService::ChoosePrice(int index)
{
    //cout << " Типы билетов: " << endl;
    //ShowPrice();
    return ticketPrices[index - 1];
}

/*!
  \brief Order Ticket to visiting performance
  \return ticket
*/
Ticket OrderService::OrderTicket(int theatreIndex, int performanceIndex, int placeIndex, int priceIndex) {
    Theatre theatre = ChooseTheatre(theatreIndex);
    Performance performance = ChoosePerformance(theatre, performanceIndex);
    string place = ChoosePlace(performance, placeIndex);
    int price = ChoosePrice(priceIndex);

    Ticket ticket(performance, place, price);
    ticket.ShowInfo();

    theatre.StartPerformance(ticket);
    return ticket;
}
