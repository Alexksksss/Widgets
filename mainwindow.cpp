#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");//кодек для поддержки русского
    this->setWindowTitle(codec->toUnicode("Счетчик"));//установка заголовка

    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);

    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);

    calcbutton=new QPushButton("+1",this);
    exitbutton=new QPushButton(codec->toUnicode("Выход"),this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1);
    layout1->addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);

    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    // связь сигнала нажатия кнопки и слота закрытия окна
    connect(calcbutton,SIGNAL(clicked(bool)), edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()), edit2,SLOT(add_one()));
    connect(exitbutton,SIGNAL(clicked(bool)), this,SLOT(close()));
}
