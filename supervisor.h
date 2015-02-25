#pragma once
#include "employee.h"

class ShiftSupervisor : public Employee {
  double  m_bonus;
  double m_salary;

public:
  ShiftSupervisor();
  ShiftSupervisor(etype);
  virtual ~ShiftSupervisor();

  // Mutators
  void  setBonus(double);
  void setSalary(double);
  virtual void setRandom();

  // Accessors
  double  getBonus();
  double getSalary();
};
