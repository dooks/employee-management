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
 * Main loop:
 *  =Display current page of employee data
 *  If none:
 *    =Open employee add screen
 *
 *  switch user input
 *    case up:
 *      Move cursor up
 *    case down:
 *      Move cursor down
 *    case enter or space:
 *      =Open employee details
 *    case 'A' or 'a':
 *      =Open employee add screen
 *    case 'D' or 'd':
 *      =Open employee delete screen
 *    case esc:
 *      exit program
 */
#include <iostream>
using namespace std;

#include "employee.h"

int main() {
}
