#ifndef STATE_RATING_H
#define STATE_RATING_H
#include "state_menu.h"
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
struct Record {
    std::string name;
    int a;
};
class Rating : public State {
public:

    void readFile();
    bool q=false;
    std::vector<Record> records;
    void QquickSort(std::vector<Record>& numbers, int left, int right);


    virtual void paint(GameWidget*) ;
    virtual void mouseClick(QMouseEvent*, GameWidget*);
    virtual void key_press(GameWidget*,QKeyEvent*);
    virtual void time_wait(GameWidget*,QTimerEvent *){}

};
#endif // STATE_RATING_H
