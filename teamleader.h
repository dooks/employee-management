#pragma once
#include "employee.h"
#include "production.h"

class TeamLeader : public ProductionWorker {
  double m_bonus;
  int    m_hours;

public:
  TeamLeader();
  TeamLeader(etype);
  virtual ~TeamLeader();

  // Mutators
  void setBonus(double);
  void setHours(int);
  virtual void setRandom();

  // Accessors
  double getBonus();
  int    getHours();
};
