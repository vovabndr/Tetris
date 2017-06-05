#include <QDebug>
#include "state_rating.h"
#include "state.h"
#include "state_menu.h"
void Rating::readFile()
{
    std::ifstream file("file.txt");
    Record tmp;
    while (file >> tmp.name >> tmp.a)
        records.push_back(tmp); //  добавляем в конец вектора records  tmp
}
void Rating::QquickSort(std::vector<Record>& numbers, int left, int right)
{
    int pivot; // разрешающий элемент
    std:: string pv;
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left].a;
    pv= numbers[left].name;
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right].a >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left].a = numbers[right].a; // перемещаем элемент [right] на место разрешающего
            //
            numbers[left].name = numbers[right].name;
            //
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left].a <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right].a = numbers[left].a; // перемещаем элемент [left] на место [right]
            //
            numbers[left].name = numbers[right].name;
            //
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left].a = pivot; // ставим разрешающий элемент на место
   numbers[left].name = pv; // ставим разрешающий элемент на место

    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        QquickSort(numbers, left, pivot - 1);
    if (right > pivot)
        QquickSort(numbers, pivot + 1, right);
}



void Rating::paint(GameWidget *wind)  {

    QPainter painter(wind);
    painter.drawPixmap(QRect(0,0,800,600), background);
   // qDebug()<<records.size();

    if(q==false){readFile();q=true;}

    QquickSort(records,0  ,static_cast<int>( records.size()-1));
   // QquickSort(records,0  , records.size());

if(records.size()!=0){

    painter.setFont(QFont("Helvetica",32,QFont::Normal));
    if(records.size()!=0){
        for(int n=1,i=records.size()-1;i>=0 ;i--,n++)
        {
        painter.drawPixmap(QRect(160,57*n-45,500,80),QPixmap(":/button-1222589_960_720 copy 2.png"));
        painter.drawText(200,5+57*n,QString::number(n)+QString::fromStdString(records[i].name) + QString::number(records[i].a));
        }
    }
}
    painter.drawImage(660,70, buttons[3], 0, 0, 0, 0);

}
 void Rating::mouseClick(QMouseEvent* event, GameWidget* m)
{
    int x = event->pos().x();
    int y = event->pos().y();
    if(buttons[3].valid( x-640 , y-80 ))
        m->setCurrent(new MainMenu());
    event->accept();
}

 void Rating::key_press(GameWidget* widget,QKeyEvent* event)
 {
     if(event->key()==Qt::Key_Escape)
         widget->setCurrent(new MainMenu());
 }
