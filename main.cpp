#include "game.h"
#include "widget.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game::Instance().run();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return a.exec();
}
