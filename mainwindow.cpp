#include "mainwindow.h" // подключение заголовочного файла MainWindow
#include "ui_mainwindow.h" // подключение файла с реализацией пользовательского интерфейса
#include <QVBoxLayout> // подключение класса QVBoxLayout для вертикального размещения виджетов
#include <QPushButton> // подключение класса QPushButton для создания кнопок



MainWindow::MainWindow(QWidget *parent):QWidget(parent) // определение конструктора класса MainWindow
{
    codec = QTextCodec::codecForName("UTF-8"); // установка кодека для поддержки русского языка
    this->setWindowTitle(codec->toUnicode("Счетчик")); // установка заголовка окна

    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this); // создание метки "Cчет по 1"
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this); // создание метки "Cчет по 5"

    edit1 = new Counter("0",this); // создание объекта класса Counter для счета по 1
    edit2 = new Counter("0",this); // создание объекта класса Counter для счета по 5

    calcbutton=new QPushButton("+1",this); // создание кнопки "+1"
    exitbutton=new QPushButton(codec->toUnicode("Выход"),this); // создание кнопки "Выход"

    QHBoxLayout *layout1 = new QHBoxLayout(); // создание горизонтального блока layout1
    layout1->addWidget(label1); // добавление метки label1 в блок layout1
    layout1->addWidget(label2); // добавление метки label2 в блок layout1

    QHBoxLayout *layout2 = new QHBoxLayout(); // создание горизонтального блока layout2
    layout2->addWidget(edit1); // добавление объекта edit1 в блок layout2
    layout2->addWidget(edit2); // добавление объекта edit2 в блок layout2

    QHBoxLayout *layout3 = new QHBoxLayout(); // создание горизонтального блока layout3
    layout3->addWidget(calcbutton); // добавление кнопки calcbutton в блок layout3
    layout3->addWidget(exitbutton); // добавление кнопки exitbutton в блок layout3

    QVBoxLayout *layout4 = new QVBoxLayout(this); // создание вертикального блока layout4
    layout4->addLayout(layout1); // добавление блока layout1 в блок layout4
    layout4->addLayout(layout2); // добавление блока layout2 в блок layout4
    layout4->addLayout(layout3); // добавление блока layout3 в блок layout4

    connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one())); // связь нажатия кнопки calcbutton со слотом add_one объекта edit1
    connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one())); // связь сигнала tick_signal объекта edit1 со слотом add_one объекта edit2
    connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close())); // связь нажатия кнопки exitbutton со слотом close() окна
}
