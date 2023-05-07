#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "area.h"
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    MainWindow();
};


#endif // MAINWINDOW_H
