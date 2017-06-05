#ifndef BLOCK_H
#define BLOCK_H


#include <QPainter>
#include <QColor>
#include <cmath>

class Block: QObject
{
Q_OBJECT
public:

    Block();
    Block(int Gx,int Gy);
    ~Block(){}
    int x();
    int y();
    int start(){return 372;}
    int pos_x,pos_y;

};


#endif // BLOCK_H
