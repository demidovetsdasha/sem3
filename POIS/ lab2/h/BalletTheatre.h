#pragma once
#include "Theatre.h"

class BalletTheatre : public Theatre {
public:
    BalletTheatre(string name, string adress, string director, vector<Performance> performances) : Theatre(name, adress, director, performances) {}

    void Introduction() override;
};