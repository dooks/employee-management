#include <stdexcept>
#include <vector>
#include <string>
using std::string;

#include "manager.h"
#include "employee.h"

// Static variable Definitions
Manager::evector Manager::employees;


// Mutators
void Manager::destroy(Manager::iter it) {
  employees.erase(it);
}

Manager::iter Manager::add(Employee* employee) {
  employees.push_back(employee);
  return --(employees.end()); // Iterator to last element
}

// Accessors
Manager::evector Manager::getPage(int first, int last) {
  Manager::evector retval(employees.begin()+first, employees.begin() + last);
  // TODO: exception handling
  // CRITICAL
  return retval;
}

// Search functions
Manager::iter Manager::find(Employee* term) {
  // Search by employee's pointer
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i))
      return i;
  }

  return employees.end();
}

Manager::iter Manager::find(string term) {
  // Search by name
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i)->getName())
      return i;
  }

  return employees.end();
}

Manager::iter Manager::find(int term) {
  // Search by employee number
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i)->getID())
      return i;
  }

  return employees.end();
}
