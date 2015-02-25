#pragma once
#include "employee.h"

class ProductionWorker : public Employee {
  int    m_shift;
  double m_payrate;

public:
  ProductionWorker();
  ProductionWorker(etype);
  virtual ~ProductionWorker();

  // Mutators
  void setShift(int);
  void setPayRate(double);
  virtual void setRandom();

  // Accessors
  int    getShift();
  double getPayRate();
};

// Derived class
#include "teamleader.h"
