#include "pch.h"
#include "Place.h"

void Place::Take() { isEmpty = false; }
void Place::Cancel() { isEmpty = true; }

string Place::GetPlace() {
    return to_string(row) + "--" + to_string(place);
}

bool Place::IsEmpty() { return isEmpty; }