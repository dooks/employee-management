#pragma once
#include <string>
#include "date.h"
#include "manager.h"
using std::string;

class Employee {
  friend class Manager;

  enum etype {
    EMPLOYEE = 0,
    PRODUCTION,
    SUPERVISOR,
    TEAMLEADER
  };
  etype m_type;

protected:
  string m_name;
  int    m_number;
  date   m_hire;

public:
  Employee();

  // Mutators
  void setID(int id);
  void setName(string name);
  void setDate(int month, int day, int year);

  // Accessors 
  int      getID();
  string getName();
  string getDate();
};

