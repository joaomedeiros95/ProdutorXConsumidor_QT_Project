#include "thread2.h"
#include <QMutex>
#include <qglobal.h>

Thread2::Thread2(QObject *parent) :
    QThread(parent)
{
}

void Thread2::run() {
    QMutex mutex;
    while (1) {
        sem2->P();
        mutex.lock();
        if(sem1->getContador() < 5)
            sem1->V();
        mutex.unlock();
        msleep(101);
    }
}

void Thread2::setSem1(Semaforo *sem)
{
    sem1 = sem;
}

void Thread2::setSem2(Semaforo *sem)
{
    sem2 = sem;
}
