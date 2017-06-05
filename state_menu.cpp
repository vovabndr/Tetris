#include "state_menu.h"
#include "state_game.h"
#include "state_rating.h"
//#include "log.h"
void MainMenu::paint(GameWidget *wind) {
    QPainter painter(wind);
    painter.drawPixmap(QRect(0,0,800,600), background);

    for(int i=0;i<3;i++)
    painter.drawImage(270,240+100*i, buttons.at(i), 0, 0, 0, 0);

    painter.drawImage(220,110, buttons.at(4), 0, 0, 0, 0);

}

void MainMenu::mouseClick(QMouseEvent* event, GameWidget* m) {



    int x = event->pos().x();
    int y = event->pos().y();

    if(buttons[0].valid( x-270 , y-240 )) {
//        Log::getInstance().i("Game", "loading game");

        m->setCurrent(new state_game());
    //   Log::getInstance().i("game ", "succses");

    }
    if(buttons[1].valid( x-270 , y-340 )) {
//        Log::getInstance().i("Main menu", "loading rating");

        m->setCurrent(new Rating());
//        Log::getInstance().i("Rating ", "succses");

    }
    if(buttons[2].valid( x-270 , y-440 )) {
//        Log::getInstance().i("Main menu", "exiting");
        m->close();
    }
    event->accept();
}


void MainMenu::key_press(GameWidget* widget,QKeyEvent* event)
{

    if(event->key()==Qt::Key_Return)
        widget->setCurrent(new state_game());
    if(event->key()==Qt::Key_Escape)
        widget->close();
}
