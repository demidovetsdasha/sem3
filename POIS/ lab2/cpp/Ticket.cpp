#include "pch.h"
#include "Ticket.h"

Performance Ticket::GetPerformance() { return performance; }

void Ticket::ShowInfo() {
    cout << "\nÑïåêòàêëü: " << performance.GetName() << "\nÄaòa : " << performance.GetDate() << "\nÖeía : " << price << "\n";
}