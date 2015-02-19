#pragma once
#include <string>
#include "date.h"
#include "manager.h"
using std::string;

class Employee {
  friend class Manager;
  Employee();
  ~Employee();
  void destroy();

protected:
  string m_name;
  int    m_number;
  date   m_hire;

public:
  static Employee* create();

  // Accessors
  void setID(int);
  void setName(string);
  void setDate(int, int, int);

  // Mutators
  int      getID() { return     m_number; }
  string getName() { return       m_name; }
  string getDate() { return m_hire.str(); }
};

