#ifndef STATE_H
#define STATE_H

#include <widget.h>
#include <game.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCoreApplication>


class State
{
public:
    State();

    QImage start_btn{":/kp4gnhuw.png"};
    QImage exit_btn{":/cihg17y.png"};
    QImage rating_btn{":/qjoze4mqch.png"};
    QImage back_btn{":/cjosg4a.png"};

    QPixmap loadBack{("://love_for_tetris_by_cookiemagik-2.jpg")};
    QPixmap background{("://8a3517809a86fef90d8a563719bb6f90ac08cdac.jpg")};
    QPixmap gameName{("://Tetris logo.png")};
    QPixmap logo{(":/logo.png")};
    QPainterPath kvadratik;
    QBrush colors[6]={Qt::red,Qt::yellow,Qt::green,Qt::blue,Qt::magenta,Qt::cyan};
    int length{0},x{0},size{50};
    bool ended{false};

    QVector <QImage> buttons;

   int frameNumber{0};
    virtual void paint(GameWidget*)=0;
    virtual void mouseClick(QMouseEvent*, GameWidget*)=0;
    virtual void key_press(GameWidget*,QKeyEvent*) =0 ;
    virtual void time_wait(GameWidget*,QTimerEvent *event)=0;


};

class LoadMenu : public State {

public:
    virtual void paint(GameWidget*);

    void mouseClick(QMouseEvent*, GameWidget*){}
    virtual void key_press(GameWidget*,QKeyEvent*){}
    virtual void time_wait(GameWidget*,QTimerEvent *){}
};




#endif // STATE_H
