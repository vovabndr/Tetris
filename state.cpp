#include "state.h"
#include "state_game.h"
#include "state_menu.h"
#include "log.h"
#include <iostream>
#include <QPainter>
#include <QRect>
#include <QTimer>
#include<QPainterPath>
#include "widget.h"

State::State()
{
        buttons.push_back(QImage(":/button-1222589_960_720.png").scaled(270, 150,Qt::KeepAspectRatio)); // 0 - start
        buttons.push_back(QImage(":/button-1222589_960_720 2.png").scaled(270, 150,Qt::KeepAspectRatio)); // 1 - rating
        buttons.push_back(QImage(":/button-1222589_960_720 3.png").scaled(270, 150,Qt::KeepAspectRatio)); // 2 - exit
        buttons.push_back(QImage(":/cjosg4a.png")); // 3 - back
        buttons.push_back(QImage(":/jinwhie.png").scaled(static_cast<int>(269.*1.3), static_cast<int>(72.*1.3),Qt::KeepAspectRatio));//menu
}

void LoadMenu::paint(GameWidget *wind) {


    length=frameNumber;
    if(length%size==0)
    {
            kvadratik.moveTo(length,size);
            kvadratik.lineTo(length,500);
            kvadratik.lineTo(length+size,500);
            kvadratik.lineTo(length+size,size+500);
            kvadratik.lineTo(length,size+500);
    }
    QPainter paint(wind);
    paint.drawPixmap(QRect(0,0,800,600), loadBack);
    paint.drawPixmap(QRect(140,0,500,200), gameName);

    if(not ended)
    {
        paint.fillPath(kvadratik, colors[x%6]);
        x++;
    }
    frameNumber++;

    if (frameNumber == 800){
       Log::getInstance().i("LoadMenu", "Opening main menu");

        wind->setCurrent( new MainMenu());
    }
}




