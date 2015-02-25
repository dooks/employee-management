#include <sstream>
#include "date.h"
using std::stringstream;
using std::ostream;

// Constructor
date::date()
  : m_year(0), m_month(0), m_day(0) {
  // Empty contructor
}
// Mutators
void date::setYear(int year) { m_year = year; }
void date::setMonth(int month) { m_month = month; }
void date::setDay(int day) { m_day = day; }

// Accessors
int date::getYear()  { return (int) m_year;  }
int date::getMonth() { return (int) m_month; }
int date::getDay()   { return (int) m_day;   }

string date::str() {
  stringstream ss;
  ss << m_month << "-" << m_day << "-" << m_year;
  return ss.str();
}

ostream& operator<<(ostream& ss, const date& self) {
  // Promote datatypes to integers for printing
  ss << self.m_month << "-" << self.m_day << "-" << self.m_year;
  return ss;
}

// Operators
// Unused... no need to define
