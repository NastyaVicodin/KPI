#include "mainwindow.h"

void Bubles::run(){
    qRegisterMetaType<QVector<int> >("QVector<int>");
    bool change;
    do{
        change=false;
        if (is_paused == false){
            for(int i=0; i<array_bubles.count()-1;i++){
                emit draw(gs,array_bubles);
                if(array_bubles[i]>array_bubles[i+1]){
                    int temp=array_bubles[i+1];
                    array_bubles[i+1]=array_bubles[i];
                    array_bubles[i]=temp;
                    change=true;
                   usleep(50000);
                }
            }
        }
    }while(change==true);
    finish = 1;
    if (prior == 3)
        emit finished();
    else
        emit last();
}

void Heap::building_pyramid(int i, int count){
    int child;
    int new_elem=array_heap[i];
    if (is_paused == false){
    while(i<=count/2){
        child=2*i;
        if(child<count && array_heap[child]<array_heap[child+1])child++;
        if(new_elem>=array_heap[child]) break;
        array_heap[i]=array_heap[child];
        i=child;
    }
    array_heap[i]=new_elem;
    emit draw(gs,array_heap); //требуем перерисовать сцену
    usleep(50000);} //задерживаем, чтобы замедлить процесс сортировки
}

void Heap::run(){
    qRegisterMetaType<QVector<int> >("QVector<int>");

    for(int i=array_heap.count()/2;i>=0;i--){
        building_pyramid(i,array_heap.count()-1);
    }
    for(int i=array_heap.count()-1;i>0;i--){
        int temp=array_heap[i];
        array_heap[i]=array_heap[0];
        array_heap[0]=temp;
        building_pyramid(0,i-1);
    }
    finish = 1;
    if (prior == 3)
        emit finished();
    else
        emit last();
}

void Quick::run() {
    qRegisterMetaType<QVector<int> >("QVector<int>");
    this->sort();
    finish = 1;
    if (prior == 3)
        emit finished();
    else
        emit last();
}

void Quick::sort(int l, int r) {
    qRegisterMetaType<QVector<int> >("QVector<int>");
    emit draw(gs,array_quick);
    if(r==0) r=array_quick.count()-1;
    int i = l;
    int j = r;
    int x = array_quick[(l+r)/2];
    do {
        if (is_paused == false){
        while (array_quick[i]<x)i++;
        while (array_quick[j]>x)j--;
        if(i<=j){
            if(array_quick[i]>array_quick[j]){
                int temp=array_quick[i];
                array_quick[i]=array_quick[j];
                array_quick[j]=temp;
            }
            i++;
            j--;
        }
        emit draw(gs,array_quick);
        usleep(50000);}
    }while(i<=j);
    if(i<r)sort(i,r);
    if(j>l)sort(l,j);
}
