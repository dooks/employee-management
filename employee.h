#pragma once
#include <string>
#include <fstream>
#include "date.h"
#include "manager.h"
using std::string;
using std::ifstream;
using std::ofstream;

enum etype { EMPLOYEE = 0, PRODUCTION, SUPERVISOR, TEAMLEADER };

/* Employee Base Class */
class Employee {
protected:
  friend class Manager;
  etype  m_type;
  string m_name;
  int    m_number;
  date   m_hire;

  static string* NAMES;
  static int     NAMES_LENGTH;

public:
  Employee();
  Employee(etype);
  virtual ~Employee();

  // Mutators
  static void INIT_NAMES();

  virtual void setRandom();
  void setID(int id);
  void setName(string name);
  void setDate(int month, int day, int year);

  // Accessors 
  int      getID();
  etype  getType();
  string getName();
  string getDate();
};

// Derived types
#include "production.h"
#include "supervisor.h"
