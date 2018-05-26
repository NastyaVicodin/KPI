#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QThread>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QTime>
#include <QTimer>
#include <QDebug>
//buble sort
class Bubles : public QThread
{
    Q_OBJECT
public:
    QVector<int> array_bubles;
    int gs;
    int finish = 0;
    int prior;
    bool is_paused = false;
    void resume();
    void run();
    void stop();
    void init(QVector<int> array,int gs);
    void init_s(QVector<int> array,int gs);
signals:
    void draw(int gs, QVector<int> array);
    void finished();
    void last();
};
//heap sort
class Heap: public QThread
{
    Q_OBJECT //макрос без которого не работает система слотов и сигналов
public:
    QVector<int> array_heap; //массив с элементами
    int gs; //номер сцены
    bool is_paused = false;
    int finish = 0;
    int prior;
    void resume();
    void run (); //здесь реализован собственно сам алгоритм
    void stop();
    void building_pyramid(int i, int count);//функция формирующая пирамиду из элементов
    void init(QVector<int> array,int gs);
    void init_s(QVector<int> array,int gs);
signals:
    void draw(int gs, QVector<int> array); //создаем сигнал, требующие перерисовать сцену
    void finished();
    void last();
};
//quick sort
class Quick: public QThread
{
    Q_OBJECT
public:
    QVector<int> array_quick;
    int gs;
    int prior;
    int finish = 0;
    bool is_paused = false;
    void resume();
    void sort(int l=0, int r=0);
    void run();
    void stop();
    void init(QVector<int> array,int gs);
    void init_s(QVector<int> array,int gs);
signals:
    void draw(int gs, QVector<int> array);
    void finished();
    void last();
};

class MainWindow : public QMainWindow
{
    int threads = 1;
    int pr_b = 0;
    int pr_h = 0;
    int pr_q = 0;
    int synch = 0;
    Q_OBJECT
    Quick *quick;
    Bubles *bubles;
    Heap *heap;
    QGridLayout *glMain;
    QWidget *wCenter;
    QVector<int> array;
    QGraphicsScene *gs1,*gs2,*gs3;
    QGraphicsView *gv1,*gv2,*gv3;
    QBrush brush;
    QPen pen;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void draw(int gs_s, QVector<int> array);
    void gen();
    void reset();
    void start();
    void start_syn();
    void start_s();
    void start_sl();
    void stop_b();
    void stop_h();
    void stop_q();
    void resume_b();
    void resume_h();
    void resume_q();
    void add_thread();
    void del_thread();
    void pr_bh();
    void pr_bn();
    void pr_bl();
    void pr_hh();
    void pr_hn();
    void pr_hl();
    void pr_qh();
    void pr_qn();
    void pr_ql();
};

#endif // MAINWINDOW_H
