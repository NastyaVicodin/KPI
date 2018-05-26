#include "mainwindow.h"

void MainWindow::gen(){
    qsrand(QDateTime::currentMSecsSinceEpoch()); //чтобы при каждом запуске программы генерировались разные числа
    array.clear(); //очищаем наш массив
    for(int i=1;i<=30;i++)array<<(qrand()%100); //генерируем 30 чисел от 0 до 100
    this->reset();
}
