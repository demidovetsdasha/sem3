#include "pch.h"
#include "Theatre.h"

/*!
    \brief Implementation of the Opera class
    \author Dasha
    \version 1
    \date November 2023
    \details Contains a constructor; methods for start introdaction and showing information.
*/

/*!
    \brief Introduction output
*/
void Theatre::Introduction()
{
    cout << "Добро пожаловать в театр!" << endl;
}
/*!
    \brief Getter of Name
    \return Name
*/
string Theatre::GetName() { return name; }
Performance Theatre::GetPerformance(int i) { return performances[i];
}

/*!
    \brief Start of performance 
    \param ticket ticket of performance
*/
void Theatre::StartPeroformance(Ticket ticket) {
     Introduction();

     Performance performance = ticket.GetPerformance();

     performance.Start();
}

/*!
    \brief afisha output 
*/
void Theatre::ShowAfisha()
{
        for (int i = 0; i < performances.size(); i++)
            cout << i + 1 << "." << performances[i].GetName() << "  " << performances[i].GetDate() << endl;

}
