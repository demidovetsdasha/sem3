#include "pch.h"
#include "Actor.h"
#include "Musician.h"
#include "BalletDancer.h"
#include "DollActor.h"
#include "Date.h"
#include "Place.h"
#include "Performance.h"
#include "Ticket.h"
#include "Theatre.h"
#include "Opera.h"
#include "BalletTheatre.h"
#include "DollTheatre.h"
#include "OrderService.h"
#include <iostream>

using namespace std;

TEST(TheatreTest, ActorsTest) {
    Actor actor1("Катя", "Рамона");
    Musician actor2("Петя", "Арфа");
    DollActor actor3("Лена", "Момо");
    BalletDancer actor4("Вася", "Лебедь");

    EXPECT_EQ(actor1.GetName(), "Катя");
    EXPECT_EQ(actor1.GetRole(), "Рамона");
    EXPECT_EQ(actor3.GetName(), "Лена");
    EXPECT_EQ(actor3.GetRole(), "Момо");
    EXPECT_EQ(actor4.GetName(), "Вася");
    EXPECT_EQ(actor4.GetRole(), "Лебедь");
    EXPECT_EQ(actor2.GetName(), "Петя");
    EXPECT_EQ(actor2.GetRole(), "Арфа");
}

TEST(TheatreTest, DateTest) {
    Date date1(19, 00, 31, 07, 2024);
    Date date2(19, 00, 31, 07, 2024);

    EXPECT_EQ(date1.GetDate(), date2.GetDate());
}

TEST(TheatreTest, PlaceTest) {
    Place place1(1, 4);

    place1.Take();

    EXPECT_FALSE(place1.IsEmpty());

    place1.Cancel();

    EXPECT_TRUE(place1.IsEmpty());
}

TEST(TheatreTest, PerformanceTest)
{
    Actor actor1("Катя", "Рамона");
    Musician actor2("Петя", "Арфа");
    DollActor actor3("Лена", "Момо");
    BalletDancer actor4("Вася", "Лебедь");
    Date date(10, 10, 5, 12, 2023);

    Performance performance("Все и сразу", date);
    performance.CreatePlaces(1, 1);

    EXPECT_EQ(performance.GetName(), "Все и сразу");
    EXPECT_EQ(performance.GetDate(), date.GetDate());

    performance.AddActor(actor1);
    performance.AddActor(actor2);
    performance.AddActor(actor3);
    performance.AddActor(actor4);

    EXPECT_EQ(performance.GetActorsCount(), 4);

    performance.RemoveActor(actor1);

    EXPECT_EQ(performance.GetActorsCount(), 3);
}

TEST(TheatreTest, TheatresTest) {
    Date date(10, 10, 5, 12, 2023);
    Performance performance("Все и сразу", date);
    performance.CreatePlaces(1, 1);

    vector<Performance> perfomances;
    perfomances.push_back(performance);

    Theatre theatre1("Большой театр", "ул. Розовая, 31", "Романов", perfomances);
    OperaTheatre theatre2("Оперный театр", "ул. Красочная, 1", "Добровольский", perfomances);
    DollTheatre theatre3("Кукольный театр", "ул. Цветочнная, 4", "Кирилов", perfomances);
    BalletTheatre theatre4("Баллетный театр", "ул. Дворовая, 7", "Моринов", perfomances);

    EXPECT_EQ(theatre1.GetName(), "Большой театр");
    EXPECT_EQ(theatre3.GetName(), "Кукольный театр");
    EXPECT_EQ(theatre4.GetName(), "Баллетный театр");
    EXPECT_EQ(theatre2.GetName(), "Оперный театр");
}

TEST(TheatreTest, TicketAndOrderServiceTest)
{
    setlocale(LC_ALL, "Rus");

    Date date(10, 10, 5, 12, 2023);
    Performance performance("Все и сразу", date);
    performance.CreatePlaces(2, 2);

    vector<Performance> perfomances;
    perfomances.push_back(performance);

    Theatre theatre("Большой театр", "ул. Розовая, 31", "Романов", perfomances);
    vector<Theatre> theatres;
    theatres.push_back(theatre);

    OrderService orderService(theatres);

    Ticket ticket = orderService.OrderTicket();

    EXPECT_EQ(ticket.GetPerformance().GetName(), performance.GetName());
}