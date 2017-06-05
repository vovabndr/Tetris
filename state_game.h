#ifndef STATE_GAME_H
#define STATE_GAME_H
#include "state.h"
#include "block.h"
#include <QVector>
#include <fstream>
#include <string>
#include <vector>
#include <string>



class state_game : public State {

private:
    int change{0};
    int side{28};
    int size=side*10;
    int x{0};
    int rund{qrand()%18};
    int lines{4};
    int count{0};
    bool lose{false};
    bool pause{false};
    bool wr{false};
    int anykey{0};
    long long tim=0;
    QString name="";

    Block block;
    Block block1;
    Block block2;
    Block block3;

    Block b,b1,b2,b3;
    QVector <Block*> blocks;
    QVector <bool> erase;
    QVector< QBrush> colors;
    QVector <int> block_color;
    QVector <int> figures;

    int nex_figure();
    void set_chords(Block *,Block *,Block *,Block *,int);
    void pushing(Block *,Block *,Block *,Block *, int i);
    int get_my_color(int);
    bool canImove();
    void block_road(Block *, Block *, Block *, Block * , int);
    void moving(){block.pos_y+=side;}
    void erase_line(int line);
    void writeFile(std::string name, int a);


public:
    state_game();
    ~state_game();
    virtual void paint(GameWidget*);
    virtual void mouseClick(QMouseEvent*, GameWidget*);
    virtual void key_press(GameWidget*,QKeyEvent*);
    virtual void time_wait(GameWidget*, QTimerEvent *){}

};
#endif // STATE_GAME_H
