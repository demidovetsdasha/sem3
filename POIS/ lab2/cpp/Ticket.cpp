#include "pch.h"
#include "Ticket.h"

Performance Ticket::GetPerformance() { return performance; }

void Ticket::ShowInfo() {
    cout << "\n���������: " << performance.GetName() << "\n�a�a : " << performance.GetDate() << "\n�e�a : " << price << "\n";
}