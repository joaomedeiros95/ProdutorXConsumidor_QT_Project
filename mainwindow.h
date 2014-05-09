#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread1.h"
#include "thread2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Semaforo *sem1;
    Semaforo *sem2;
    Thread1 *thread1;
    Thread2 *thread2;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
    int pintados;
};

#endif // MAINWINDOW_H
