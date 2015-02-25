#pragma once
#include "manager.h"
#include "employee.h"

class Display {
  void displayEmployee(Employee*);         // Draws invidual employee
  void clearScreen();

public:
  Display();
  ~Display();
  void displaySplash();                    // Draws splash screen
  void displayPageHeader(int page_number); // Draws page header
  void displayPage(Manager::evector);      // Draw given vector of employees
  void displayPageFooter();                // Draw page footer
};
