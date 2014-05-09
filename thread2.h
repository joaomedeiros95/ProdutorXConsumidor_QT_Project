#ifndef THREAD2_H
#define THREAD2_H

#include <QThread>
#include "semaforo.h"

class Thread2 : public QThread
{
    Q_OBJECT
public:
    explicit Thread2(QObject *parent = 0);
    void run();
    void setSem1(Semaforo *sem);
    void setSem2(Semaforo *sem);
    Semaforo *sem1;
    Semaforo *sem2;

private:

public slots:

};

#endif // THREAD2_H
