#pragma once
#include <iostream>
#include <string>
using std::string;

struct date {
  typedef unsigned int  dint;
  typedef unsigned char dbyte;
  dint  year;
  dbyte month;
  dbyte day;

public:
  date(int);

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
  friend date operator+(const date&, const date&);
  friend date operator-(const date&, const date&);
  friend date operator+(const date&, const int);
  friend date operator-(const date&, const int);
};
