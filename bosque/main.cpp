#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    system("rm -f ./Salida.txt");
    QApplication a(argc, argv);
    MainWindow w;
    w.agregarLbl();
    w.show();
    return a.exec();
}
