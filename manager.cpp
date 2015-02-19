#pragma once
#include <stdexcept>
#include <vector>
#include "manager.h"

Manager::list employees;

Manager::iter Manager::find(Employee* term) {
  for(Manager::iter i = list.begin(); i != list.end(); i++) {
    if(term == (*i))
      return i;
  }

  return list.end();
}

Manager::iter Manager::find(string term) {
  for(Manager::iter i = list.begin(); i != list.end(); i++) {
    if(term == (*i)->getName())
      return i;
  }

  return list.end();
}

Manager::iter Manager::find(int term) {
  for(Manager::iter i = list.begin(); i != list.end(); i++) {
    if(term == (*i)->getID())
      return i;
  }

  return list.end();
}
