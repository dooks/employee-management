#include <iostream>
#include "pager.h"
using namespace std;

Pager::Pager() {}

Pager::state Pager::getState() { return m_state; }
int Pager::getCursor()         { return m_cursor; }
int Pager::getPage()           { return m_page; }

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
