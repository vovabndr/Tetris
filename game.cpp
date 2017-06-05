#include "game.h"
#include "widget.h"

Game::Game()
{}
void Game::run()
{
    gamewidget = new GameWidget();
    gamewidget->setFixedWidth(800);
    gamewidget->setFixedHeight(600);
    gamewidget->show();
}
