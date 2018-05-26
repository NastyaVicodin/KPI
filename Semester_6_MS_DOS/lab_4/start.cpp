#include "mainwindow.h"

void MainWindow::start(){

    bubles->init(array,1); //передаем начальные параметры потоку работающему с алгоритмом пузырьковой сортировки
    if (threads >= 2 ){
    heap->init(array,2);} //.... пирамидальной сортировки
    if (threads == 3 ){
    quick->init(array,3);} //.... быстрой сортировки
}
