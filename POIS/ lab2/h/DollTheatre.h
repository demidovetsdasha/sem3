#pragma once
#include "Theatre.h"

class DollTheatre : public Theatre {
public:
    DollTheatre(string name, string adress, string director, vector<Performance> performances) : Theatre(name, adress, director, performances) {}

    void Introduction() override;
};