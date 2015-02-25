#define NAME_FILE "names.txt"
#define MAX_NAMES 1000

#include <string>
#include <fstream>
#include "date.h"
#include "manager.h"
#include "employee.h"

// Static members
std::string* Employee::NAMES = NULL;
int Employee::NAMES_LENGTH = 0;
void Employee::INIT_NAMES() {
  std::string temp_names[MAX_NAMES];
  std::ifstream in_file(NAME_FILE);

  for(int i = 0; !in_file.eof(); i++) {
    getline(in_file, temp_names[i]);
    Employee::NAMES_LENGTH = i + 1;
  }

  NAMES = new std::string[NAMES_LENGTH];
  for(int i = 0; i < NAMES_LENGTH; i++ ) {
    NAMES[i] = temp_names[i];
  }

  in_file.close();
}


Employee::Employee() : m_name(""), m_number(0), m_hire(), m_type(EMPLOYEE) { }
Employee::Employee(etype type) : m_name(""), m_number(0), m_hire(), m_type(type) { }

Employee::~Employee() {}

// Mutators
void Employee::setID(int id)        { m_number = id; }
void Employee::setName(std::string name) { m_name = name; }
void Employee::setDate(int month, int day, int year) {
  m_hire.setMonth(month);
  m_hire.setDay(day);
  m_hire.setYear(year);
}

void Employee::setRandom() {
  // Random presets
  setID(rand() % 1000 + 1);
  setName(Employee::NAMES[rand() % (Employee::NAMES_LENGTH - 1)]);
  setDate(rand() % 12 + 1, rand() % 30 +  1, rand() % 4 + 2000);
}

// Accessors
etype Employee::getType() { return m_type;   }
int     Employee::getID() { return m_number; }
std::string Employee::getName() { return m_name;       }
std::string Employee::getDate() { return m_hire.str(); }
