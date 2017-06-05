#include "state_game.h"
#include "state.h"
#include "state_menu.h"
#include "state_rating.h"
#include "widget.h"
#include "log.h"
#include <iostream>
#include <QTime>
#include <QVector>
#include <QColor>
#include <QDebug>

state_game::state_game()
{
     colors.push_back(Qt::red); //0
     colors.push_back(Qt::green);//1
     colors.push_back(Qt::blue);//2
     colors.push_back(Qt::yellow);//3
     colors.push_back(Qt::magenta);//4
     colors.push_back(Qt::cyan);//5
     colors.push_back(Qt::lightGray);//6
     colors.push_back(QColor(255, 153, 0));//7
     figures.push_back(nex_figure());
  //   figures.push_back(nex_figure());
     b.pos_x+=270;b.pos_y+=200;

}

void state_game::paint(GameWidget *wind) {
    QPainter painter(wind);
    painter.drawPixmap(QRect(0,0,800,600), background);
    painter.drawImage(640,80, buttons.at(3), 0, 0, 0, 0);
    painter.fillRect(QRect(260,20,size,size*2), Qt::black /*colors.at(tim%7)*/);
    painter.fillRect(QRect(610,180,side*6,side*6), Qt::white);
    painter.setPen(Qt::white);
    for (int i=0;i<=10;i++)
    painter.drawLine(260+i*side, 20, 260+i*side, 20+560);
    for (int i=0;i<=20;i++)
    painter.drawLine(260, 20+i*side, 260+side*10, 20+i*side);
    painter.setFont(QFont("Helvetica",32,QFont::Normal));
    painter.drawPixmap(QRect(50,140,150,100),QPixmap(":/button-1222589_960_720 copy 2.png"));
    painter.drawText(60,200,"Score  \n"+QString::number(lines));

    if(lose==false){
    set_chords(&block,&block1,&block2,&block3,rund);
    block_road(&block,&block1,&block2,&block3,rund);

    painter.fillRect(QRect( block.x(),block.y(), side-1,side-1), colors.at(get_my_color(rund)));
    painter.fillRect(QRect(block1.x(),block1.y(),side-1,side-1), colors.at(get_my_color(rund)));
    painter.fillRect(QRect(block2.x(),block2.y(),side-1,side-1), colors.at(get_my_color(rund)));
    painter.fillRect(QRect(block3.x(),block3.y(),side-1,side-1), colors.at(get_my_color(rund)));

    set_chords(&b,&b1,&b2,&b3,figures.at(count));
    painter.fillRect(QRect( b.x(),b.y(), side-1,side-1), colors.at(get_my_color(figures.at(count))));
    painter.fillRect(QRect(b1.x(),b1.y(),side-1,side-1), colors.at(get_my_color(figures.at(count))));
    painter.fillRect(QRect(b2.x(),b2.y(),side-1,side-1), colors.at(get_my_color(figures.at(count))));
    painter.fillRect(QRect(b3.x(),b3.y(),side-1,side-1), colors.at(get_my_color(figures.at(count))));
    }

for(int i=19;i>0;i--) erase_line(i);
    if(blocks.size()!=0)
    for(size_t i=0 , n=blocks.size() ;i<n; i++){
        if(erase[i]==false and blocks[i]->x()<=512 and lose==false)
         painter.fillRect(QRect(blocks[i]->x(),blocks[i]->y(),27,27), colors.at(block_color.at(i)  ));
         if(blocks[i]->y()<=20) {
               lose=true;
               if(anykey==0)
                    painter.drawPixmap(QRect(60,25,650,350),QPixmap(":/button-1222589_960_720 copy 2.png"));
                    painter.drawText(270,150,"Enter your name: ");
                    painter.drawText(320,220,name);
                    //
                    //
               if(anykey==1)
                    painter.drawPixmap(QRect(0,0,800,600),QPixmap(":/Mljuegos0.png"));
               if(anykey==2)
                    {
                    if(wr==false){writeFile(name.toStdString(),lines);wr=true;}
                    wind->setCurrent(new Rating());
               }}}
    if (tim%(10+ 200-((lines+1)*5))==0 and lose==false and pause==false)moving();tim++;
}

void state_game::set_chords(Block *block,Block *block1,Block *block2,Block *block3, int i)
{
    if (i==0)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y();

        block2->pos_x=block->x();
        block2->pos_y=block->y()-side;

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()-side;
    }
    if (i==1)
    {
        block1->pos_x=block->x()+side*3;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side*2;
        block3->pos_y=block->y();
    }
    if (i==2)
    {

        block1->pos_x=block->x();
        block1->pos_y=block->y()+side*3;

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side*2;

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side;
    }
   //l
    if (i==3)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y()+side*2;

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side*2;
    }
    if (i==4)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side;
    }
    if (i==5)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()+side*2;
    }
    if (i==6)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y()-side;

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side*2;
        block3->pos_y=block->y();
    }
    //j
    if (i== 7)
    {
        block1->pos_x=block->x()-side;
        block1->pos_y=block->y()+side;

        block2->pos_x=block->x();
        block2->pos_y=block->y()-side;

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side;
    }
    if (i== 8)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y();

        block2->pos_x=block->x();
        block2->pos_y=block->y()-side;

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y();
    }
    if (i== 9)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y();

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side*2;
    }
    if (i==10)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side*2;
        block3->pos_y=block->y()+side;
    }
    //s
    if (i==11)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y()-side;

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()-side;
    }
    if (i==12)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y()+side*2;

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()+side;
    }
    //z
    if (i==13)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y()+side;

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()+side;
    }
    if (i==14)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y()-side;

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x();
        block3->pos_y=block->y()+side;
    }
    //T
    if (i==15)
    {

        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()-side;
    }
    if (i==16)
    {
        block1->pos_x=block->x()+side;
        block1->pos_y=block->y();

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x();
        block3->pos_y=block->y()-side;
    }
    if (i==17)
    {
        block1->pos_x=block->x()+side*2;
        block1->pos_y=block->y();

        block2->pos_x=block->x()+side;
        block2->pos_y=block->y();

        block3->pos_x=block->x()+side;
        block3->pos_y=block->y()+side;
    }
    if (i==18)
    {
        block1->pos_x=block->x()-side;
        block1->pos_y=block->y();

        block2->pos_x=block->x();
        block2->pos_y=block->y()+side;

        block3->pos_x=block->x();
        block3->pos_y=block->y()-side;
    }
}
void state_game::block_road(Block *block,Block *block1,Block *block2,Block *block3,int numb){
        if(block->pos_y==552 or block1->pos_y==552 or block2->pos_y==552 or block3->pos_y==552)
            pushing(block,block1,block2,block3,numb);
         if(blocks.size()!=0)
         for(size_t i=0 , n=blocks.size() ;i<n; i++){
                 if(erase[i]==false)

            if(     (block->y()== blocks[i]->y()-side and  block->x()==blocks[i]->x())  or
                    (block1->y()==blocks[i]->y()-side and block1->x()==blocks[i]->x())  or
                    (block2->y()==blocks[i]->y()-side and block2->x()==blocks[i]->x())  or
                    (block3->y()==blocks[i]->y()-side and block3->x()==blocks[i]->x()))
                pushing(block,block1,block2,block3,numb);
         }
}
void state_game::pushing(Block *, Block *, Block *, Block *, int i)
{
    blocks.push_back(new Block( block.pos_x, block.pos_y)); erase.push_back(false); block_color.push_back(get_my_color(i));
    blocks.push_back(new Block(block1.pos_x,block1.pos_y)); erase.push_back(false); block_color.push_back(get_my_color(i));
    blocks.push_back(new Block(block2.pos_x,block2.pos_y)); erase.push_back(false); block_color.push_back(get_my_color(i));
    blocks.push_back(new Block(block3.pos_x,block3.pos_y)); erase.push_back(false); block_color.push_back(get_my_color(i));
    rund= figures.at(count);figures.push_back(nex_figure());count++;
    block.pos_x=block.start();
    block.pos_y=20;
    set_chords(&block,&block1,&block2,&block3,i);
}
void state_game::erase_line(int line)
{
    line=(line*side)+20;
    int count=0;
    if(blocks.size()!=0){

    for(size_t i=0 , n=blocks.size() ;i<n; i++)
       if(blocks[i]->y()==line) count++;

    if (count>=10)
    {
        for(size_t i=0 , n=blocks.size() ;i<n; i++)
        {
            if(blocks[i]->y()==line)
            {
                erase[i]=true;
                blocks[i]->pos_y+=500;
            }
            if(blocks[i]->y()<line)
            blocks[i]->pos_y+=side;
        }
        lines++;}
    }
}
int  state_game::get_my_color(int ch)
{
    if(ch==0) return 3;
    if(ch==1 or ch==2) return 5; //I
    if(ch>=3 and ch<=6) return 7;//l
    if(ch>=7 and ch<=10) return 2;//J
    if(ch>=11 and ch<=12) return 1;//S
    if(ch>=13 and ch<=14) return 0;//Z
    if(ch>=15 and ch<=18) return 4;
}
bool state_game::canImove()
{
    if(block.x()>512)  return false; if(block.x()<260)  return false;
    if(block1.x()>512) return false; if(block1.x()<260) return false;
    if(block2.x()>512) return false; if(block2.x()<260) return false;
    if(block3.x()>512) return false; if(block3.x()<260) return false;
    return true;
}
int  state_game::nex_figure()
{
    return qrand()%18;
}
void state_game::mouseClick(QMouseEvent* event, GameWidget* m)
{
    int x = event->pos().x();
    int y = event->pos().y();
    if(buttons.at(3).valid( x-640 , y-80 )) {
        m->setCurrent(new MainMenu());
   }
    event->accept();
}
void state_game::key_press(GameWidget* widget,QKeyEvent* event)
{
    if(event->key()==Qt::Key_Escape) {

        widget->setCurrent(new MainMenu());
    }
    if (!pause){
    if(event->key()==Qt::Key_Up  and block.pos_y<560-side)
        {
            moving();
        }
    if(event->key()==Qt::Key_Down){
    x++;
       if(rund==1 or rund==2 ){rund=(x%2)+1;}//I
       if(rund>=3 and rund<=6 ){ rund=(x%4)+3;}//l
       if(rund>=7 and rund<=10 ){  rund=(x%4)+7;}//J
       if(rund>=11 and rund<=12 ){ rund=(x%2)+11;}//S
       if(rund>=13 and rund<=14 ){ rund=(x%2)+13;}//Z
       if(rund>=15 and rund<=18 ){ rund=(x%4)+15;} //T

    }
    if(event->key()==Qt::Key_Right and (block.pos_x<512 and block1.pos_x<512))
        {
        block.pos_x+=side;
        }
    if(event->key()==Qt::Key_Left and block.pos_x>260 and block1.pos_x>260)
        {
        block.pos_x-=side;
        }
    }
    if(event->key()==Qt::Key_P )
        {
            if(pause==false) pause =true; else pause =false;
        }
    if (lose){
        if(event->key()==Qt::Key_Return and lose==true ){anykey++;}
        if (event->key()==Qt::Key_Delete) name.resize(name.size()-1);
        else if (event->key()) name.push_back((event->key()));
       }
}
void state_game::writeFile(std::string name, int a)
{
    std::ofstream out;
        out.open("file.txt", std::ios::app);
        out<<name<<' '<<a<<std::endl;
        out.close();
}
