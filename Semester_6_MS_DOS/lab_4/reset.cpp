#include "mainwindow.h"

void MainWindow::reset(){
    this->draw(1,array);
    if (threads >= 2){
        this->draw(2,array);
    }
    if (threads == 3){
    this->draw(3,array);}
}
