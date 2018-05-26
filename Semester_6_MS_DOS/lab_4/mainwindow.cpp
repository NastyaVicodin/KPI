#include "mainwindow.h"

void MainWindow::add_thread(){
    if (threads < 3)
    {
        threads++;
        reset();
    }
}

void MainWindow::del_thread(){
    if (threads >= 2){
        threads--;
    }
    if (threads == 2)
    {gs3->clear();}
    if (threads == 1)
    {gs2->clear();}

}

void MainWindow::pr_bh(){pr_b = 3;}
void MainWindow::pr_bn(){pr_b = 2;}
void MainWindow::pr_bl(){pr_b = 1;}
void MainWindow::pr_hh(){pr_h = 3;}
void MainWindow::pr_hn(){pr_h = 2;}
void MainWindow::pr_hl(){pr_h = 1;}
void MainWindow::pr_qh(){pr_q = 3;}
void MainWindow::pr_qn(){pr_q = 2;}
void MainWindow::pr_ql(){pr_q = 1;}

//window parameters
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Sort");
    this->setMinimumSize(800,500);
    this->setMaximumSize(800,500);
    glMain = new QGridLayout;
    wCenter = new QWidget;
    wCenter->setLayout(glMain);
    this->setCentralWidget(wCenter);
    bubles = new Bubles();
    heap = new Heap();
    quick = new Quick();

    QPushButton *pb=new QPushButton("Sort (asyn)");
    QPushButton *pb_syn=new QPushButton("Sort (syn)");
    QPushButton *pb_add=new QPushButton("Add thread");
    QPushButton *pb_del=new QPushButton("Delete thread");
    QPushButton *pb_gen = new QPushButton("Generate new array");
    QHBoxLayout *hb=new QHBoxLayout;

    hb->addStretch();
    hb->addWidget(pb_add);
    hb->addWidget(pb_del);
    hb->addWidget(pb);
    hb->addWidget(pb_syn);
    hb->addWidget(pb_gen);
    hb->addStretch();
    glMain->addLayout(hb,6,0);

    connect(pb_add,SIGNAL(clicked()),this,SLOT(add_thread()));
    connect(pb_del,SIGNAL(clicked()),this,SLOT(del_thread()));

    QHBoxLayout *hb_label=new QHBoxLayout;
    hb_label->addStretch(4);
    QLabel *lbl = new QLabel("Buble");
    hb_label->addWidget(lbl);
    hb_label->addStretch(7);
    hb_label->addWidget(new QLabel("Heap"));

    hb_label->addStretch(7);
    hb_label->addWidget(new QLabel("Quick"));
    hb_label->addStretch(4);
    glMain->addLayout(hb_label,0,0);

    int w=230,h=310;
    gs1=new QGraphicsScene(this);
    gs1->setSceneRect(0, 0, w, h);
    gv1=new QGraphicsView(gs1);
    gv1->setFixedHeight(gs1->height()+3);
    gv1->setFixedWidth(gs1->width()+3);

    gs2=new QGraphicsScene(this);
    gs2->setSceneRect(0, 0, w, h);
    gv2=new QGraphicsView(gs2);
    gv2->setFixedHeight(gs2->height()+3);
    gv2->setFixedWidth(gs2->width()+3);

    gs3=new QGraphicsScene(this);
    gs3->setSceneRect(0, 0, w, h);
    gv3=new QGraphicsView(gs3);
    gv3->setFixedHeight(gs3->height()+3);
    gv3->setFixedWidth(gs3->width()+3);

    QHBoxLayout *hb_gv=new QHBoxLayout;
    hb_gv->addStretch(5);
    hb_gv->addWidget(gv1);
    hb_gv->addStretch(5);
    hb_gv->addWidget(gv2);
    hb_gv->addStretch(5);
    hb_gv->addWidget(gv3);
    hb_gv->addStretch(5);
    glMain->addLayout(hb_gv,3,0);
    glMain->setRowStretch(2,0);

    QHBoxLayout *hp;
    QPushButton *prior_bh = new QPushButton("High");
    QPushButton *prior_hh = new QPushButton("High");
    QPushButton *prior_qh = new QPushButton("High");
    QPushButton *prior_bn = new QPushButton("Normal");
    QPushButton *prior_hn = new QPushButton("Normal");
    QPushButton *prior_qn = new QPushButton("Normal");
    QPushButton *prior_bl = new QPushButton("Low");
    QPushButton *prior_hl = new QPushButton("Low");
    QPushButton *prior_ql = new QPushButton("Low");
    hp=new QHBoxLayout;
    hp->addStretch(2);
    hp->addWidget(prior_bl);
    hp->addWidget(prior_bn);
    hp->addWidget(prior_bh);
    hp->addStretch(2);
    hp->addWidget(prior_hl);
    hp->addWidget(prior_hn);
    hp->addWidget(prior_hh);
    hp->addStretch(2);
    hp->addWidget(prior_ql);
    hp->addWidget(prior_qn);
    hp->addWidget(prior_qh);
    hp->addStretch(2);

    glMain->addLayout(hp,1,0);

    connect(prior_bh,SIGNAL(clicked()),this,SLOT(pr_bh()));
    connect(prior_bn,SIGNAL(clicked()),this,SLOT(pr_bn()));
    connect(prior_bl,SIGNAL(clicked()),this,SLOT(pr_bl()));
    connect(prior_hh,SIGNAL(clicked()),this,SLOT(pr_hh()));
    connect(prior_hn,SIGNAL(clicked()),this,SLOT(pr_hn()));
    connect(prior_hl,SIGNAL(clicked()),this,SLOT(pr_hl()));
    connect(prior_qh,SIGNAL(clicked()),this,SLOT(pr_qh()));
    connect(prior_qn,SIGNAL(clicked()),this,SLOT(pr_qn()));
    connect(prior_ql,SIGNAL(clicked()),this,SLOT(pr_ql()));

    QHBoxLayout *hs;
    QPushButton *pb_stop_b = new QPushButton("Stop");
    QPushButton *pb_resume_b = new QPushButton("Resume");
    QPushButton *pb_stop_h = new QPushButton("Stop");
    QPushButton *pb_resume_h = new QPushButton("Resume");
    QPushButton *pb_stop_q = new QPushButton("Stop");
    QPushButton *pb_resume_q = new QPushButton("Resume");

    hs=new QHBoxLayout;
    hs->addStretch(2);
    hs->addWidget(pb_stop_b);
    hs->addStretch();
    hs->addWidget(pb_resume_b);
    hs->addStretch(3);
    hs->addWidget(pb_stop_h);
    hs->addStretch();
    hs->addWidget(pb_resume_h);
    hs->addStretch(3);
    hs->addWidget(pb_stop_q);
    hs->addStretch();
    hs->addWidget(pb_resume_q);
    hs->addStretch(2);
    glMain->addLayout(hs,2,0);

    brush = QBrush(QColor(0,153,255));
    pen = QPen(QColor(0,153,255),0);
    this->gen();
    this->reset();

    connect(pb_gen,SIGNAL(clicked()),this,SLOT(gen()));
    connect(pb,SIGNAL(clicked()),this,SLOT(start()));
    connect(pb_syn,SIGNAL(clicked()),this,SLOT(start_syn()));
    connect(bubles,SIGNAL(draw(int,QVector<int>)),this,SLOT(draw(int,QVector<int>)));
    connect(heap,SIGNAL(draw(int,QVector<int>)),this,SLOT(draw(int,QVector<int>)));
    connect(quick,SIGNAL(draw(int,QVector<int>)),this,SLOT(draw(int,QVector<int>)));

    connect(pb_stop_b,SIGNAL(clicked()),this,SLOT(stop_b()));
    connect(pb_stop_h,SIGNAL(clicked()),this,SLOT(stop_h()));
    connect(pb_stop_q,SIGNAL(clicked()),this,SLOT(stop_q()));

    connect(pb_resume_b,SIGNAL(clicked()),this,SLOT(resume_b()));
    connect(pb_resume_h,SIGNAL(clicked()),this,SLOT(resume_h()));
    connect(pb_resume_q,SIGNAL(clicked()),this,SLOT(resume_q()));
}

MainWindow::~MainWindow()
{

}
