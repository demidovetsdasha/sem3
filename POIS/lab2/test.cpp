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
    Actor actor1("����", "������");
    Musician actor2("����", "����");
    DollActor actor3("����", "����");
    BalletDancer actor4("����", "������");

    EXPECT_EQ(actor1.GetName(), "����");
    EXPECT_EQ(actor1.GetRole(), "������");
    EXPECT_EQ(actor3.GetName(), "����");
    EXPECT_EQ(actor3.GetRole(), "����");
    EXPECT_EQ(actor4.GetName(), "����");
    EXPECT_EQ(actor4.GetRole(), "������");
    EXPECT_EQ(actor2.GetName(), "����");
    EXPECT_EQ(actor2.GetRole(), "����");
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
    Actor actor1("����", "������");
    Musician actor2("����", "����");
    DollActor actor3("����", "����");
    BalletDancer actor4("����", "������");
    Date date(10, 10, 5, 12, 2023);

    Performance performance("��� � �����", date);
    performance.CreatePlaces(1, 1);

    EXPECT_EQ(performance.GetName(), "��� � �����");
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
    Performance performance("��� � �����", date);
    performance.CreatePlaces(1, 1);

    vector<Performance> perfomances;
    perfomances.push_back(performance);

    Theatre theatre1("������� �����", "��. �������, 31", "�������", perfomances);
    OperaTheatre theatre2("������� �����", "��. ���������, 1", "�������������", perfomances);
    DollTheatre theatre3("��������� �����", "��. ����������, 4", "�������", perfomances);
    BalletTheatre theatre4("��������� �����", "��. ��������, 7", "�������", perfomances);

    EXPECT_EQ(theatre1.GetName(), "������� �����");
    EXPECT_EQ(theatre3.GetName(), "��������� �����");
    EXPECT_EQ(theatre4.GetName(), "��������� �����");
    EXPECT_EQ(theatre2.GetName(), "������� �����");
}

TEST(TheatreTest, TicketAndOrderServiceTest)
{
    setlocale(LC_ALL, "Rus");

    Date date(10, 10, 5, 12, 2023);
    Performance performance("��� � �����", date);
    performance.CreatePlaces(2, 2);

    vector<Performance> perfomances;
    perfomances.push_back(performance);

    Theatre theatre("������� �����", "��. �������, 31", "�������", perfomances);
    vector<Theatre> theatres;
    theatres.push_back(theatre);

    OrderService orderService(theatres);

    Ticket ticket = orderService.OrderTicket();

    EXPECT_EQ(ticket.GetPerformance().GetName(), performance.GetName());
}