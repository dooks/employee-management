#include "employee.h"

class ShiftSupervisor : public Employee {
  double m_salary;
  double  m_bonus;

public:
  double  getBonus();
  double getSalary();

  void    setBonus();
  void   setSalary();
};
