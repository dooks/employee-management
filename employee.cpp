#include <string>
#include "date.h"
#include "manager.h"
#include "employee.h"
using std::string;

Employee::Employee() : m_name(""), m_number(0), m_hire(0) {}

Employee* Employee::create() {
  Employee* retval = new Employee();
  Manager::list.push_back(retval);
  return retval;
}

void Employee::setID(int id) {
  m_number = id;
}

void Employee::setName(string name) {
  m_number = m_name;
}

void Employee::setID(int month, int day, int year) {
  m_hire.month = month;
  m_hire.day   = day;
  m_hire.year  = year;
}
