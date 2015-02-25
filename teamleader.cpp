#include "employee.h"
#include "production.h"

class ProductionWorker;

TeamLeader::TeamLeader() : ProductionWorker(TEAMLEADER) { }
TeamLeader::TeamLeader(etype type = TEAMLEADER) : ProductionWorker(type) { }
TeamLeader::~TeamLeader() { }

// Mutators
void TeamLeader::setBonus(double bonus) { m_bonus = bonus; }
void TeamLeader::setHours(int    hours) { m_hours = hours; }
void TeamLeader::setRandom() {
  // Random presets
  setID(rand() % 1000 + 1);
  setName(Employee::NAMES[rand() % (Employee::NAMES_LENGTH - 1)]);
  setDate(rand() % 12 + 1, rand() % 30 +  1, rand() % 4 + 2000);
  setShift(rand() % 2);
  setPayRate((double) (rand() % 1000) / 10.0 + 15.00);
  setBonus((double) (rand() % 5000) / 10.0 + 200.00);
  setHours((rand() % 60) + 120);
}


// Accessors
double TeamLeader::getBonus() { return m_bonus; }
int    TeamLeader::getHours() { return m_hours; }

