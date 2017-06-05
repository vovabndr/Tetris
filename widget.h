#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
     GameWidget(QWidget *parent = 0);
    ~GameWidget();

     void setCurrent(class State* m) {
         current = m;
     }

     virtual void paintEvent(QPaintEvent*);
     virtual void mouseReleaseEvent(QMouseEvent*);
     virtual void keyPressEvent(QKeyEvent *);
     virtual void timerEvent(QTimerEvent *event);

public :
    QTimer* timer;
    class State *current;
    QPainter* painter;

};
#endif // WIDGET_H

