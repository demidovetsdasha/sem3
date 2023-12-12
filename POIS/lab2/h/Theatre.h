#pragma once
#include <string>
#include <vector>
#include "Performance.h"
#include "Ticket.h"

using namespace std;

class Theatre {
private:
    string name;
    string address;
    string director;
    vector<Performance> performances;

protected:
    void virtual Introduction();
public:
    Theatre(string name, string address, string director, vector<Performance> performances) :name(name), address(address), director(director), performances(performances) {}

    string GetName();
    Performance GetPerformance(int i);

    void StartPeroformance(Ticket ticket);

    void ShowAfisha();
};