#include "mainwindow.h"
#include <QApplication>


/**
  Mauro Miguel Anastacio Montaño
              3CV5

  Estructuras y Bases de Datos

            QT5

gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

  **/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    return a.exec();
}
