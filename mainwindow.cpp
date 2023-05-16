#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");//кодек для поддержки русского
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));//установка заголовка

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    // Создаем метку для ввода числа и устанавливаем ее свойства
    inputLabel = new QLabel(codec->toUnicode("Введите число:"),this);

    // Создаем поле ввода числа и устанавливаем его свойства, также создаем валидатор для проверки корректности ввода
    inputEdit = new QLineEdit("",this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    // Создаем метку для вывода результата и устанавливаем ее свойства
    outputLabel = new QLabel(codec->toUnicode("Результат:"), this);

    // Создаем поле вывода результата и устанавливаем его свойства
    outputEdit = new QLineEdit("",this);

    // Создаем кнопки "Следующее" и "Выход" и устанавливаем их свойства
    nextButton = new QPushButton(codec->toUnicode("Следующее"), this);
    exitButton = new QPushButton(codec->toUnicode("Выход"), this);

    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();//пружина

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();
    //сигналы-слоты
    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));
}

void MainWindow::begin(){
    inputEdit->clear();// очистка поля
    nextButton->setEnabled(false);// делает кнопку "Следующее" недоступной
    nextButton->setDefault(false);// убирает "Следующее" из области выбора по умолчанию
    inputEdit->setEnabled(true);// делает поле ввода доступным для ввода
    outputLabel->setVisible(false); // скрывает надпись "Результат"
    outputEdit->setVisible(false); // скрывает поле вывода результата
    outputEdit->setEnabled(false); // делает поле вывода результата недоступным для изменения
    inputEdit->setFocus(); // устанавливает фокус на поле ввода
}
void MainWindow::calc(){
    bool Ok=true; //флаг для проверки правильности ввода
    float r,a; //переменные для вычислений
    QString str=inputEdit->text(); //считываем текст из поля ввода
    a=str.toDouble(&Ok); //конвертируем строку в число
    if (Ok) //если конвертация прошла успешно
    {
        r=a*a; //вычисляем квадрат числа
        str.setNum(r); //конвертируем результат в строку
        outputEdit->setText(str); //выводим результат в поле вывода
        inputEdit->setEnabled(false); //делаем поле ввода неактивным
        outputLabel->setVisible(true); //делаем метку вывода видимой
        outputEdit->setVisible(true); //делаем поле вывода видимым
        nextButton->setDefault(true); //делаем кнопку "Следующее" активной по умолчанию
        nextButton->setEnabled(true); //делаем кнопку "Следующее" активной
        nextButton->setFocus(); //устанавливаем фокус на кнопку "Следующее"
    }
    else
    if (!str.isEmpty())//если в поле ввода что-то есть
    {
        QMessageBox msgBox(QMessageBox::Information, codec->toUnicode("Возведение в квадрат."),
                codec->toUnicode("Введено неверное значение."), QMessageBox::Ok); //выводим сообщение об ошибке
        msgBox.exec();
    }
    else {
        QMessageBox msgBox(QMessageBox::Information, codec->toUnicode("Возведение в квадрат."),
            codec->toUnicode("Введена пустая строка."), QMessageBox::Ok); //выводим сообщение об ошибке
        msgBox.exec();
    }

}

