#include "supervisor.h"

ShiftSupervisor::ShiftSupervisor() : Employee(SUPERVISOR) { }
ShiftSupervisor::ShiftSupervisor(etype type = SUPERVISOR) : Employee(type) { }
ShiftSupervisor::~ShiftSupervisor() { }

// Mutators
void ShiftSupervisor::setSalary(double salary) { m_salary = salary; }
void ShiftSupervisor::setBonus(double bonus) { m_bonus = bonus; }
void ShiftSupervisor::setRandom() {
  // Random presets
  setID(rand() % 1000 + 1);
  setName(Employee::NAMES[rand() % (Employee::NAMES_LENGTH - 1)]);
  setDate(rand() % 12 + 1, rand() % 30 +  1, rand() % 4 + 2000);
  setSalary((double)(rand() % 80000)/10 + 24000);
  setBonus((double) (rand() % 10000)/10 + 200);
}


// Accessors
double ShiftSupervisor::getSalary() { return m_salary; }
double ShiftSupervisor::getBonus()  { return m_bonus;  }
