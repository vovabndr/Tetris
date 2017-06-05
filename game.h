#ifndef GAME_H
#define GAME_H
#include "widget.h"
class Game
{
public:
        static Game &Instance()
        {
            static Game theSingleInstance;
            return theSingleInstance;
        }
        void run();
private:
        Game();
        Game(const Game& root);
        Game &operator=(const Game &root);
        GameWidget *gamewidget;
};
#endif // GAME_H
