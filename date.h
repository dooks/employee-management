#pragma once
#include <iostream>
#include <string>
using std::string;

/*
 * Date object
 * Creates a structure that allows access for human readable date
 */
class date {
  int  m_year;
  int m_month;
  int m_day;

public:
  date();

  // Accessors
  int getYear();
  int getMonth();
  int getDay();
  string str();

  // Mutators
  void setYear(int);
  void setMonth(int);
  void setDay(int);

  // Cout operator
  friend std::ostream& operator<<(std::ostream&, const date&);

  // Arithmetic operators
  // date + date
  // Unused...
  friend date operator+(const date&, const date&);
  friend date operator-(const date&, const date&);
  friend date operator+(const date&, const int);
  friend date operator-(const date&, const int);
};
