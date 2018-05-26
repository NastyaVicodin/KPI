#include "mainwindow.h"

void MainWindow::stop_b(){
    bubles->stop();
}

void MainWindow::stop_h(){
    heap->stop();
}

void MainWindow::stop_q(){
    quick->stop();
}

void Bubles::stop(){
    is_paused = true;

}

void Heap::stop(){
    is_paused = true;
}

void Quick::stop(){
    is_paused = true;
}
