/* Lab 3 - Dylan Lotivio
 * Demonstrate Employee class and (children) implementations
 *
 * Psuedocode:
 *
 * Define globals
 * -- Seed RNG
 * -- Main quit flag
 * -- State flag
 *    0 - Splash page
 *    1 - Main loop (paging)
 *    2 - Quitting / garbage collection
 *
 * Define global structures
 * -- Input   - Handles user input
 * -- Display - Handles drawing to the screen
 * -- Manager - Keeps track of Employee obj, and all children
 * -- Pager   - Keeps track of paging structure
 *
 * Create random employees
 *  switch(random type)
 *    case employee:
 *      create new   employee object
 *    case production:
 *      create new production object
 *    case supervisor:
 *      create new supervisor object
 *    case teamleader:
 *      create new teamleader object
 * Randomize new employee
 * Add employee to manager
 *
 * Initialize pager length to size of list of employees
 *
 * Main loop - while quit is false
 *  switch(program state)
 *    case SPLASH:
 *      Display splash screen
 *      switch user input
 *        case Any key
 *          change state to VIEWPAGE
 *    case VIEWPAGE:
 *      Create temporary list of employees from Manager
 *        based on current page values
 *      Display page header
 *      Display page list from temporary list
 *      Display page footer
 *
 *      switch user input
 *        case P or p:
 *          Move page previous
 *        case N or n:
 *          Move page next
 *        case Q or q:
 *          change state to QUIT
 *    case QUIT:
 *      set quit flag to true
 */
#define DEBUG
#define PAGE_SIZE 5

#ifdef DEBUG
  #define NUM_RAND_EMPLOYEES 50
#endif

// Core modules
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

// Employee modules
#include "employee.h"   // Base class

// Interactive modules
#include "pager.h"
#include "display.h"
#include "input.h"

int main() {
  // Globals
  srand((unsigned) time(NULL)); // Seed RNG
  bool quit = 0;
  int state = 0;  //  0 - Splash page
                  //  1 - Viewing pages
                  // -1 - Quitting

  // Initialize global program structures
  Input     input; // Handles sanitizing user input
  Display display; // Handles displaying to cout, and clearing
  Manager manager; // Stores newly created employee objects
  Employee::INIT_NAMES(); // Initialize random name list
  Pager pager(PAGE_SIZE); // Stores list and page information
  Manager::evector current_page; // Stores list of employees of current page

  for(int i = 0; i < NUM_RAND_EMPLOYEES; i++) {
    Employee* temp;
    switch((etype) rand() % 4) {
      case EMPLOYEE: // Random employee
        temp = new Employee;
        break;
      case PRODUCTION: // Random production worker
        temp = new ProductionWorker;
        break;
      case SUPERVISOR: // Random supervisor
        temp = new ShiftSupervisor;
        break;
      case TEAMLEADER: // Random teamleader
        temp = new TeamLeader;
        break;
      default:
        temp = new Employee	;
    }
    temp->setRandom();
    manager.add(temp);
  }

  // Initialize pager length
  pager.setLength(manager.getSize());

  // Main loop
  while(!quit) {
    switch(state) {
      case 0: // Splash screen
        // Display program header and additional information
        display.displaySplash();
        switch(input.getCh()) {
          case '\0':
          default:
            // Any key to continue...
            state = 1; // Viewing state
        }
        break;
      case 1: // Viewing pages
        // Create temporary list of employeees on page
        current_page = manager.getRange( pager.getPageFirst(), pager.getPageLast() );
        display.displayPageHeader( pager.getPageNumber() );
        // Display temporary list
        display.displayPage( current_page );
        display.displayPageFooter();

        switch(input.getCh()) {
          case 'p':
          case 'P': // Previous page
            pager.movePage(Pager::UP);
            break;
          case 'n':
          case 'N': // Next page
            pager.movePage(Pager::DOWN);
            break;
          case 'q':
          case 'Q':
            state = -1; // QUIT
          default:
            // Do nothing
            break;
        }
        break;
      case -1: // Quit
        cout << "Quitting..\n";
        quit = true;
        break;
    }
  }

  cin.ignore();
  cout << "Press enter to exit...\n";
  cin.get();
  return 0;
}
