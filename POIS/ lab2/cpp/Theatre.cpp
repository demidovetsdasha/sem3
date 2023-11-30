#include "pch.h"
#include "Theatre.h"

void Theatre::Introduction()
{
    cout << "Добро пожаловать в театр!" << endl;
}

string Theatre::GetName() { return name; }
Performance Theatre::GetPerformance(int i) { return performances[i]; }

void Theatre::StartPeroformance(Ticket ticket) {
     Introduction();

     Performance performance = ticket.GetPerformance();

     performance.Start();
}

void Theatre::ShowAfisha()
{
        for (int i = 0; i < performances.size(); i++)
            cout << i + 1 << "." << performances[i].GetName() << "  " << performances[i].GetDate() << endl;

}