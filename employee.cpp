#include <string>
#include "date.h"
#include "manager.h"
#include "employee.h"
using std::string;

Employee::Employee() :
  m_name(""), m_number(0), m_hire(), m_type(EMPLOYEE) {
  // Do nothing
}

// Mutators
void Employee::setID(int id)        { m_number = id; }
void Employee::setName(string name) { m_name = name; }
void Employee::setDate(int month, int day, int year) {
  m_hire.setMonth(month);
  m_hire.setDay(day);
  m_hire.setYear(year);
}

// Accessors
int Employee::getID()      { return m_number;     }
string Employee::getName() { return m_name;       }
string Employee::getDate() { return m_hire.str(); }
