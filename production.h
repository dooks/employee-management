#pragma once
#include "employee.h"

class ProductionWorker : public Employee {
  ProductionWorker();
  int      m_shift;
  double m_payrate;

public:
  // Accessors
  int          getShift();
  double     getPayRate();

  // Mutators
  void      setShift(int);
  void setPayRate(double);
};

class TeamLeader : public ProductionWorker {
  ProductionWorker();
  double m_bonus;
  int    m_req_hours;
  int    m_num_hours;

public:
  // Accessors
};
