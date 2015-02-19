#pragma once
#include <vector>
#include <string>
#include "employee.h"
using std::vector;

class Employee; // Base class
class ShiftSupervisor; // Derived from Employee
class ProductionWorker; // Derived from Employee
class TeamLeader; // Derived from ProductionWorker

class Manager {
  static list employees;

public:
  typedef vector<Employee*> list;
  typedef vector<Employee*>::iterator iter;

  // Creation
  static void list destroy(iter);
  static void Employee add(Employee*);

  static list getPage(int, int);
  static Employee* getEmployee(iter);

  // All searches return first item found to iterator
  static iter find(Employee*); // Search by employee pointer
  static iter find(string); // Search by name
  static iter find(int); // Search by employee number
};
