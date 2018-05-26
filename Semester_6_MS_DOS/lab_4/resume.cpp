#include "mainwindow.h"

void MainWindow::resume_b(){
    bubles->resume();
}

void MainWindow::resume_h(){
    heap->resume();
}

void MainWindow::resume_q(){
    quick->resume();
}

void Bubles::resume(){
    is_paused = false;
    this->start();
    this->setPriority(NormalPriority);
}

void Heap::resume(){
    is_paused = false;
    this->start();
    this->setPriority(NormalPriority);
}

void Quick::resume(){
    is_paused = false;
    this->start();
    this->setPriority(NormalPriority);
}
