#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QtCore>
#include <QDebug>
#include "sobre.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread1 = new Thread1(this);
    thread2 = new Thread2(this);

    pintados = 0;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen penblack(Qt::black);

    penblack.setWidth(3);
    paint.setPen(penblack);

    paint.drawLine (QPointF (15, 30), QPointF (65, 30));
    paint.drawLine (QPointF (65, 30), QPointF (65, 80));
    paint.drawLine (QPointF (15, 80), QPointF (65, 80));
    paint.drawLine (QPointF (15, 30), QPointF (15, 80));

    paint.drawLine (QPointF (65, 30), QPointF (115, 30));
    paint.drawLine (QPointF (115, 30), QPointF (115, 80));
    paint.drawLine (QPointF (65, 80), QPointF (115, 80));
    paint.drawLine (QPointF (65, 30), QPointF (65, 80));

    paint.drawLine (QPointF (115, 30), QPointF (165, 30));
    paint.drawLine (QPointF (165, 30), QPointF (165, 80));
    paint.drawLine (QPointF (115, 80), QPointF (165, 80));
    paint.drawLine (QPointF (115, 30), QPointF (115, 80));

    paint.drawLine (QPointF (165, 30), QPointF (215, 30));
    paint.drawLine (QPointF (215, 30), QPointF (215, 80));
    paint.drawLine (QPointF (165, 80), QPointF (215, 80));
    paint.drawLine (QPointF (165, 30), QPointF (165, 80));

    paint.drawLine (QPointF (215, 30), QPointF (265, 30));
    paint.drawLine (QPointF (265, 30), QPointF (265, 80));
    paint.drawLine (QPointF (215, 80), QPointF (265, 80));
    paint.drawLine (QPointF (215, 30), QPointF (215, 80));

    for(int i = 1; i <= sem2->getContador(); i++) {
        paint.fillRect((i - 1) * 50 + 15, 30, 50, 50, Qt::red);
    }

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sem1 = new Semaforo(1234, 5, IPC_CREAT|0600);
    sem2 = new Semaforo(1235, 0, IPC_CREAT|0600);

    thread1->setSem1(sem1);
    thread1->setSem2(sem2);

    thread2->setSem1(sem1);
    thread2->setSem2(sem2);

    thread1->start(QThread::HighestPriority);
    thread2->start(QThread::LowestPriority);

    while(!thread1->isFinished()) {
        QCoreApplication::processEvents();
        qDebug() << pintados << "Semaforo1: " << sem1->getContador() << "Semaforo2: " << sem2->getContador();
        sleep(1);
    }
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
