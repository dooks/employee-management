#pragma once
#include <vector>
#include <string>
using std::string;

class Employee; // Base class
class ShiftSupervisor; // Derived from Employee
class ProductionWorker; // Derived from Employee
class TeamLeader; // Derived from ProductionWorker

/*
 * Keeps track of handling Employee objects
 * Can search for individual employees, or return a range
 */
class Manager {
public:
  typedef std::vector<Employee*> evector;
  typedef std::vector<Employee*>::iterator iter;

  Manager();
  ~Manager();

  // Mutators
  void destroy(iter);
  iter add(Employee*);

  // Accessors
  int       getSize();          // Return size of employees vector
  evector   getRange(int, int); // Get evector of employees from first->last
  Employee* getEmployee(iter);

  // All searches return first item found to iterator
  iter find(Employee*); // Search by employee pointer
  iter find(string); // Search by name
  iter find(int); // Search by employee number

private:
  evector employees;
};
