#pragma once
#include <vector>
#include <string>
using std::string;

class Employee; // Base class
class ShiftSupervisor; // Derived from Employee
class ProductionWorker; // Derived from Employee
class TeamLeader; // Derived from ProductionWorker

class Manager {
public:
  typedef std::vector<Employee*> evector;
  typedef std::vector<Employee*>::iterator iter;

  // Mutators
  static void destroy(iter);
  static iter add(Employee*);

  // Accessors
  static evector getPage(int, int); // Get evector of employees from first->last
  static Employee* getEmployee(iter); // Get detailed page of single employee

  // All searches return first item found to iterator
  static iter find(Employee*); // Search by employee pointer
  static iter find(string); // Search by name
  static iter find(int); // Search by employee number

private:
  // Do not create instance of this class
  Manager();
  Manager(Manager const&);

  static evector employees;
};
