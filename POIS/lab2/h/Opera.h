#pragma once
#include  "Theatre.h"

class OperaTheatre : public Theatre {
public:
    OperaTheatre(string name, string adress, string director, vector<Performance> performances) : Theatre(name, adress, director, performances) {}

    void Introduction() override;
};
