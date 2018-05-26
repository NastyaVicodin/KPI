#include "mainwindow.h"

void MainWindow::start_syn(){
    this->reset(); // восстанавливаем
    synch = 1;
    bubles->finish = 0;
    quick->finish = 0;
    heap->finish = 0;
    bubles->prior = pr_b;
    quick->prior = pr_q;
    heap->prior = pr_h;
            connect(quick,SIGNAL(finished()),this,SLOT(start_s()));
            connect(heap,SIGNAL(finished()),this,SLOT(start_s()));
            connect(bubles,SIGNAL(finished()),this,SLOT(start_s()));
            connect(quick,SIGNAL(last()),this,SLOT(start_sl()));
            connect(heap,SIGNAL(last()),this,SLOT(start_sl()));
            connect(bubles,SIGNAL(last()),this,SLOT(start_sl()));
    if (pr_b == 3){
        bubles->init(array,1);}
    if (threads >= 2 && pr_h == 3){
        heap->init(array,2);}
    if (threads == 3 && pr_q == 3){
        quick->init(array,3);}
    if (pr_b != 3 && pr_h != 3 && pr_q != 3)
        start_s();
}

void MainWindow::start_s(){
    if (bubles->finish == 0 && pr_b == 2)
    bubles->init_s(array,1); //передаем начальные параметры потоку работающему с алгоритмом пузырьковой сортировки
    if (threads >= 2 && heap->finish == 0 && pr_h == 2){
    heap->init_s(array,2);} //.... пирамидальной сортировки
    if (threads == 3 && quick->finish == 0 && pr_q == 2){
    quick->init_s(array,3);} //.... быстрой сортировки
    if (pr_b != 2 && pr_h != 2 && pr_q != 2)
        start_sl();
}

void MainWindow::start_sl(){
    if (bubles->finish == 0 && pr_b == 1)
    bubles->init_s(array,1); //передаем начальные параметры потоку работающему с алгоритмом пузырьковой сортировки
    if (threads >= 2 && heap->finish == 0 && pr_h == 1){
    heap->init_s(array,2);} //.... пирамидальной сортировки
    if (threads == 3 && quick->finish == 0 && pr_q == 1){
    quick->init_s(array,3);} //.... быстрой сортировки

}

void Bubles::init_s(QVector<int> array, int gs){
    this->array_bubles=array;
    this->gs=gs;
    if (finish == 0)
        this->start();
    this->setPriority(NormalPriority);
}

void Heap::init_s(QVector<int> array, int gs){
    this->array_heap=array; //массив, который нужно отсортировать
    this->gs=gs; //номер графической сцены
    if (finish == 0)
        this->start(); //запуск потока
    this->setPriority(NormalPriority);
}

void Quick::init_s(QVector<int> array, int gs){
    this->array_quick=array;
    this->gs=gs;
    if (finish == 0)
        this->start();
    this->setPriority(NormalPriority);
}
