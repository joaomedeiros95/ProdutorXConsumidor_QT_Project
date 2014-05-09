#include "thread1.h"
#include <QMutex>
#include <iostream>

Thread1::Thread1(QObject *parent) :
    QThread(parent)
{
}

void Thread1::run() {
    QMutex mutex;
    while (1) {
        sem1->P();
        mutex.lock();
        if(sem2->getContador() < 5)
            sem2->V();
        mutex.unlock();
        msleep(100);
    }
}

void Thread1::setSem1(Semaforo *sem)
{
    sem1 = sem;
}

void Thread1::setSem2(Semaforo *sem)
{
    sem2 = sem;
}


