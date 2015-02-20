#include <iostream>
#include "pager.h"
using namespace std;

Pager::Pager() {}

void Pager::drawSplashPage() {
  cout << "Splash Page." << endl;
}

void Pager::drawDelPage() {
  cout << "Employee Delete Page." << endl;
}

void Pager::drawAddPage() {
  cout << "Employee Add Page." << endl;
}

void Pager::drawViewPage() {
  cout << "Employee List Page." << endl;
}

void Pager::drawViewEmployee() {
  cout << "Employee View Page." << endl;
}
