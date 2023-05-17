#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>

class Figura
{
protected:
    int x,y,halflen,dx,dy;
    virtual void draw(QPainter *Painter)=0;
public:
    Figura(int X,int Y,int Halflen):
    x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
    virtual ~Figura(){}
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
    //virtual ~MyLine() {} // Виртуальный деструктор
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
    //virtual ~MyRect() {} // Виртуальный деструктор
};

#endif // FIGURA_H
