#ifndef STATE_MENU_H
#define STATE_MENU_H
#include "state.h"
class MainMenu : public State {

public:
     void paint(GameWidget*);
     void mouseClick(QMouseEvent*, GameWidget*);
     virtual void key_press(GameWidget*,QKeyEvent*);
     virtual void time_wait(GameWidget*,QTimerEvent *){}


};
#endif // STATE_MENU_H
