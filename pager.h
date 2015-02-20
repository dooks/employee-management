#pragma once
#include "manager.h"

class Pager {
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
    EMPLOYEE
  };
  int m_cursor;
  int m_current_page;

public:
  Pager();
  void update();
  void move(dir);

  void drawSplashPage();
  void drawDelPage();
  void drawAddPage();
  void drawViewPage();
  void drawViewEmployee();
  int  waitInput();
};
