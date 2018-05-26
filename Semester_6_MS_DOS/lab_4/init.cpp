#include "mainwindow.h"

void Bubles::init(QVector<int> array, int gs){
    this->array_bubles=array;
    this->gs=gs;
    this->start();

    this->setPriority(NormalPriority);
}

void Heap::init(QVector<int> array, int gs){
    this->array_heap=array; //массив, который нужно отсортировать
    this->gs=gs; //номер графической сцены
    this->start(); //запуск потока

    this->setPriority(NormalPriority);
}

void Quick::init(QVector<int> array, int gs){
    this->array_quick=array;
    this->gs=gs;
    this->start();
    this->setPriority(NormalPriority);
}
