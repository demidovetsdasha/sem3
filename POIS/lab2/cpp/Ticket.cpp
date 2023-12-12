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
    cout << "\nÑïåêòàêëü: " << performance.GetName() << "\nÄaòa : " << performance.GetDate() << "\nÌåñòî : " << place << "\nÖeía : " << price << "\n";
}