#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
    class MainWindow; // объявление класса MainWindow в пространстве имен Ui
}

class Counter:public QLineEdit // определение класса Counter, наследующего QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0): // конструктор класса Counter
    QLineEdit(contents,parent){} // вызов конструктора базового класса
signals:
    void tick_signal(); // объявление сигнала tick_signal
public slots:
    void add_one() // объявление слота add_one
    {
        QString str=text(); // получение текста из поля ввода
        int r=str.toInt(); // преобразование текста в число
        if (r!=0 && r%5 ==0) // генерация сигнала tick_signal, если число не равно 0 и делится на 5 без остатка
            emit tick_signal();
        r++;
        str.setNum(r); // преобразование числа в строку
        setText(str); // установка нового значения поля ввода
    }
};

class MainWindow: public QWidget{ // определение класса MainWindow, наследующего QWidget
    Q_OBJECT
protected:
    QTextCodec *codec; // указатель на объект QTextCodec для поддержки русского языка
    QLabel *label1, *label2; // указатели на объекты QLabel для отображения текста
    Counter *edit1, *edit2; // указатели на объекты Counter для ввода чисел
    QPushButton *calcbutton; // указатель на объект QPushButton для кнопки "+1"
    QPushButton *exitbutton; // указатель на объект QPushButton для кнопки "Выход"
public:
    MainWindow(QWidget *parent = 0); // конструктор класса MainWindow
};

#endif // MAINWINDOW_H



