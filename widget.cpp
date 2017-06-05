#include "widget.h"
#include <state.h>
#include <QTimer>
#include <QIcon>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    current = new LoadMenu;

    this->setWindowTitle("Tetris");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();


}
GameWidget::~GameWidget(){}
void GameWidget::paintEvent(QPaintEvent*) {
    current->paint(this);
}
void GameWidget::mouseReleaseEvent(QMouseEvent *event) {

    current->mouseClick(event, this);
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    current->key_press(this,event);
}

void GameWidget::timerEvent(QTimerEvent *event)
{
    current->time_wait(this,event);
}
