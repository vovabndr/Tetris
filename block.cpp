#include "block.h"
#include "state_game.h"


Block::Block()
{
    pos_x=372;
    pos_y=20;

}

Block::Block(int Gx,int Gy)
{
    pos_x=Gx;
    pos_y=Gy;
}

int Block::x()
{
    return pos_x;
}
int Block::y()
{
    return pos_y;
}
