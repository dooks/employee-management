#pragma once
#include <string>
#include "date.h"
#include "manager.h"
using std::string;

class Employee {
public:
  enum etype {
    EMPLOYEE = 0,
    PRODUCTION,
    SUPERVISOR,
    TEAMLEADER
  };

  Employee();

  // Mutators
  void setID(int id);
  void setName(string name);
  void setDate(int month, int day, int year);

  // Accessors 
  int      getID();
  string getName();
  string getDate();

protected:
  friend class Manager;
  etype m_type;
  string m_name;
  int    m_number;
  date   m_hire;
};

