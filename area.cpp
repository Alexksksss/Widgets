#include <iostream>
#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));

    try{
        myline=new MyLine(80,100,50);
    }
    catch(std::bad_alloc const&){
        std::cout<<"Bad alloc in myline";
    }

    try{
        myrect=new MyRect(220,100,50);
    }
    catch(std::bad_alloc const&){
        std::cout<<"Bad alloc in myrect";
    }
    alpha=0;//угол поворота
}
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()//деструктор
{
    if(myline!=nullptr)
        delete myline;
    if(myrect!=nullptr)
        delete myrect;
}
