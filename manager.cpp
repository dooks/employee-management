#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "manager.h"
#include "employee.h"

// Constructors
Manager::Manager() {}
Manager::~Manager() {
  // Destroy employee objects...
  for(Manager::iter it = employees.begin(); it != employees.end(); it++) {
    delete (*it);
    (*it) = NULL;
  }
  employees.clear();
}


// Mutators
void Manager::destroy(Manager::iter it) {
  employees.erase(it);
}

Manager::iter Manager::add(Employee* employee) {
  employees.push_back(employee);
  return --(employees.end()); // Iterator to last element
}

// Accessors
int Manager::getSize() {
  return employees.size();
}

Manager::evector Manager::getRange(int first, int last) {
  Manager::evector retval;
  bool invalid = false;

  try {
    employees.at(first); // Check if indices exists
    employees.at( last);
  } catch(const std::out_of_range& err) {
    //std::cerr << "Out of range error!" << err.what() << std::endl;
    err.what();
    invalid = true;
  }

  if(!invalid) {
    // This causes undefined behavior if bounds are not valid!!!!
    // No exception can be thrown for this constructor
    retval = Manager::evector(employees.begin()+first, employees.begin() + last);
  }

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

Manager::iter Manager::find(std::string term) {
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
