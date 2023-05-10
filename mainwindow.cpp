#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    codec = QTextCodec::codecForName("UTF-8");// смена кодировки для русского языка
    this->setWindowTitle(codec->toUnicode("Обработка событий"));
    area = new Area(this);
    btn = new QPushButton(codec->toUnicode("Завершить"),this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
}
