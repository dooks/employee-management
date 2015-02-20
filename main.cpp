/* Lab 3 - Dylan Lotivio
 * Demonstrate Employee class and (children) implementations
 *
 * Psuedocode:
 * // Read files and create employee objects
 * Open binary file "employee.db"
 *
 * While not end of file
 *  Store header (for type of employee)
 *  if header is null
 *    break
 *  Switch line header
 *    // Instance management statically handled within class
 *    case Employee:
 *      create new Employee
 *    case ProductionWorker:
 *      create new ProductionWorker
 *    case ShiftSupervisor:
 *      create new ShiftSupervisor
 *    case TeamLeader:
 *      create new TeamLeader
 *
 * Display program header and additional information
 *
 * Initialize current_page to 0
 * Initialize cursor to 0
 *
 * Main loop:
 *    switch pager state
 *      case SPLASH:
 *        Draw splash page
 *        If user presses |enter|
 *          change state to PAGE
 *      case PAGE:
 *        Draw current page with current cursor
 *        switch user input:
 *          case UP:
 *            move cursor up
 *          case DOWN:
 *            move cursor down
 *          case LEFT:
 *            move cursor left
 *          case RIGHT:
 *            move cursor right
 *          case A or a:
 *            change state to ADD
 *          case D or d:
 *            change state to DEL
 *          case ENTER:
 *            if employee at cursor
 *              change state to VIEW
 *          case ESC:
 *            change state to QUIT
 *      case VIEW:
 *        Draw page for employee at cursor
 *        If user presses |ESC| or |ENTER|
 *          change state to PAGE
 *      case ADD:
 *      case DEL:
 *      case QUIT:
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "employee.h"
#include "pager.h"

int main() {
  // Read files and create employee objects
  // Open binary file "employee.db"
  ifstream inFile("employee.db", ios::in | ios::binary);

  if(!inFile) { cout << "Could not open file.\n" << endl; }
  else {
    // Check if file is empty
    inFile.seekg(0, ios::end);
    if(inFile.tellg() == 0) { cout << "File is empty.\n" << endl; }
    else {
      // While not end of file
      do {
        //  Store header (for type of employee)
        Employee::etype header;
        inFile.read(reinterpret_cast<char*>(header), sizeof(Employee::etype));

        // Critical TODO: exception handling
        //if(!header) { break; }
        if(inFile.fail()) break;

        Employee* temp = NULL;
        switch(header) {
          case Employee::EMPLOYEE:
            temp = new Employee(); // Constructor handles ptr management
            Manager::add(temp);
            break;
            //    case ProductionWorker:
            //      create new ProductionWorker
            //    case ShiftSupervisor:
            //      create new ShiftSupervisor
            //    case TeamLeader:
            //      create new TeamLeader
          default:
            break;
        }
      } while(!inFile.eof());
    }
  }


  // Initialize pager
  Pager pager;
  // Display program header and additional information
  pager.drawSplashPage();

  // Main loop
  while(1) {
    switch(pager.getState()) {
      case Pager::SPLASH:
        break;
      case Pager::PAGE:
        break;
      case Pager::VIEW:
        break;
      case Pager::DEL:
        break;
      case Pager::ADD:
        break;
    }
    break;
  }

  cout << "Press enter to exit...\n";
  cin.get();
  return 0;
}
