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
  // Destroy at iterator
  employees.erase(it);
}

Manager::iter Manager::add(Employee* employee) {
  employees.push_back(employee);
  return --(employees.end());
}

// Accessors
Manager::evector Manager::getPage(int first, int last) {
  Manager::evector retval(employees.begin()+first, employees.end() - last);
  return retval;
}

// Search functions
Manager::iter Manager::find(Employee* term) {
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i))
      return i;
  }

  return employees.end();
}

Manager::iter Manager::find(string term) {
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i)->getName())
      return i;
  }

  return employees.end();
}

Manager::iter Manager::find(int term) {
  for(Manager::iter i = employees.begin(); i != employees.end(); i++) {
    if(term == (*i)->getID())
      return i;
  }

  return employees.end();
}
