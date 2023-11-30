#include "pch.h"
#include "Ticket.h"

Performance Ticket::GetPerformance() { return performance; }

void Ticket::ShowInfo() {
    cout << "\nСпектакль: " << performance.GetName() << "\nДaтa : " << performance.GetDate() << "\nМесто : " << place << "\nЦeнa : " << price << "\n";
}
