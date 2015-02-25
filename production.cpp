#include "production.h"

ProductionWorker::ProductionWorker() : Employee(PRODUCTION) { }
ProductionWorker::ProductionWorker(etype type = PRODUCTION) : Employee(type) { }
ProductionWorker::~ProductionWorker() { }

// Mutators
void ProductionWorker::setShift(int shift)        {   m_shift = shift;   }
void ProductionWorker::setPayRate(double payrate) { m_payrate = payrate; }
void ProductionWorker::setRandom() {
  // Random presets
  setID(rand() % 1000 + 1);
  setName(Employee::NAMES[rand() % (Employee::NAMES_LENGTH - 1)]);
  setDate(rand() % 12 + 1, rand() % 30 +  1, rand() % 4 + 2000); // Random presets
  setShift(rand() % 2);
  setPayRate((double) (rand() % 1000) / 10.0 + 15.00);
}


// Accessors
int    ProductionWorker::getShift()   { return m_shift;   }
double ProductionWorker::getPayRate() { return m_payrate; }
