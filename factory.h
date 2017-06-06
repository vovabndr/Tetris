#ifndef FACTORY_H
#define FACTORY_H

#include <block.h>

class Factory_Block
{
  public:
    virtual Block *createBlock(int , int pos_y) = 0;
};

class Block_Factory: public Factory_Block
{
  public:
    Block* createBlock_o(int , int )
    {
      return new Block;
    }
};




#endif // FACTORY_H
