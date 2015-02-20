#pragma once
#include "manager.h"

class Pager {
public:
  enum dir {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };
  enum state {
    SPLASH,
    DEL,
    ADD,
    PAGE,
    VIEW
  };

  Pager();

  // Mutators
  void move(dir);

  // Accessors
  state getState();
  int   getCursor();
  int   getPage();

  // Member functions
  void drawSplashPage();
  void drawDelPage();
  void drawAddPage();
  void drawViewPage();
  void drawViewEmployee();
  int  waitInput();

private:
  state m_state;
  int   m_cursor;
  int   m_page;
};
