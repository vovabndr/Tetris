#include "game.h"
#include "widget.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    Game::Instance().run();
    return a.exec();
}
