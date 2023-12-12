#include "pch.h"
#include "Ticket.h"

/*!
    \brief Implementation of the Ticket class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; method for showing ticket information.
*/

/*!
\brief Getter of Performance
\return performance
*/
Performance Ticket::GetPerformance() { return performance; }

/*!
\brief Show information about performance
*/
void Ticket::ShowInfo() {
    cout << "\n���������: " << performance.GetName() << "\n�a�a : " << performance.GetDate() << "\n����� : " << place << "\n�e�a : " << price << "\n";
}