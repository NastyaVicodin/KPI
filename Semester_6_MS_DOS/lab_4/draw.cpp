 #include "mainwindow.h"

void MainWindow::draw(int gs_s, QVector<int> array){
    QGraphicsScene *gs;
    switch(gs_s){   //выбираем сцену для соответствующего алгоритма и даем ей свои цвета
        case 1: gs=gs1;
            brush = QBrush(QColor(0,153,255));
            pen = QPen(QColor(0,153,255),0);
            break;
        case 2: gs=gs2;
            brush = QBrush(QColor(124,252,0));
            pen = QPen(QColor(124,252,0),0);
            break;
        case 3: gs=gs3;
            brush = QBrush(QColor(255,69,0));
            pen = QPen(QColor(255,69,0),0);
            break;
    }
    gs->clear();    //очищаем предыдущую сортировку
    int max=array[0];   //начальное условие для поиска максимального элемента в массиве (чтобы определить масштаб)
    for(int i=1;i<array.count();i++) if(array[i]>max)max=array[i]; //поиск максимального элемента
    int k=(gs->width()-10)/max; //вычисляем масштаб - ширина сцены минус запас 10px и делим это все на максимальное значение
    for(int i=0;i<array.count();i++){
        gs->addPolygon(QPolygon(QRect(5,i*10+5,k*array[i],5)),pen,brush); //рисуем прямоугольник
    }
}
