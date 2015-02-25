#define TAB 5 // Default spacer

#include <iostream>
#include <iomanip>
#include "display.h"
#include "manager.h"
#include "employee.h"
using namespace std;

// Constructors
Display::Display()  {}
Display::~Display() {}

void Display::displayEmployee(Employee* employee) {
  cout << setfill('-') << setw(TAB) << right << "";
  cout << setw(TAB*4)  << left << employee->getName();
  cout << setfill('-') << setw(TAB) << right << "" << setfill(' ');
  cout << endl;

  cout << setw(TAB*3) << right << "ID: " << employee->getID() << endl;
  cout << setw(TAB*3) << right << "Hire Date: " << employee->getDate() << endl;

  switch(employee->getType()) {
    case EMPLOYEE:
      cout << setw(TAB*3) << right << "Type: " << "Employee" << endl;
      break;
    case PRODUCTION: {
        ProductionWorker* tmp = (ProductionWorker*) employee;
        cout << setw(TAB*3) << right << "Type: " << "Production Worker" << endl;
        cout << setw(TAB*3) << right << "Shift: " <<
          ((tmp->getShift() == 1) ? "Night" : "Day") << endl;
        cout << setprecision(2) << fixed;
        cout << setw(TAB*3) << right << "Pay Rate: " << "$" << tmp->getPayRate() << endl;
      }
      break;
    case SUPERVISOR: {
        ShiftSupervisor* tmp = (ShiftSupervisor*) employee;
        cout << setw(TAB*3) << right << "Type: " << "Shift Supervisor" << endl;
        cout << setprecision(2) << fixed;
        cout << setw(TAB*3) << right << "Salary: " << "$" << tmp->getSalary() << endl;
        cout << setw(TAB*3) << right <<  "Bonus: " << "$" << tmp->getBonus() << endl;
      }
      break;
    case TEAMLEADER: {
        TeamLeader* tmp = (TeamLeader*) employee;
        cout << setw(TAB*3) << right << "Type: " << "Team Leader" << endl;
        cout << setw(TAB*3) << right << "Shift: " <<
          ((tmp->getShift() == 1) ? "Night" : "Day") << endl;
        cout << setprecision(2) << fixed;
        cout << setw(TAB*3) << right << "Pay Rate: " << "$" << tmp->getPayRate() << endl;
        cout << setw(TAB*3) << right << "Monthly Bonus: " << "$" << tmp->getBonus() << endl;
        cout << setw(TAB*3) << right << "Training Hours: " << "$" << tmp->getHours() << endl;
      }
      break;
    default:
      break;
  }

  cout << endl;
}

void Display::clearScreen() { system("CLS"); } // System dependent...


// Public methods
void Display::displaySplash() {
  clearScreen();
  cout << "Lab 3 - Dylan Lotivio"   << endl;
  cout << "Objects and inheritance" << endl;
  cout << "Press enter to continue..." << endl;
}

void Display::displayPageHeader(int page_number) {
  clearScreen();
  cout << setw(TAB) << right << "Page " << page_number;
  cout << endl << endl;
}

void Display::displayPage(Manager::evector list) {
  // Display evector table
  for(Manager::iter it = list.begin(); it != list.end(); it++) {
    displayEmployee((*it));
  }

}

void Display::displayPageFooter() {
  // Display usage instructions
  cout << endl;
  cout << setfill('=') << setw(TAB*2) << "" << setfill(' ') << endl;
  cout << "'p': Previous page\n";
  cout << "'n': Next page\n";
  cout << "'q': Quit\n";
  cout << " $ : ";
}
