#ifndef HOJA_H
#define HOJA_H

#include "ui_mainwindow.h"
#include <QWidget>
#include <QLabel>

using namespace std;

class Hoja {

public:
    Hoja();
    Hoja(Ui::MainWindow *main);
    void producirHoja();
    void pintar(QLabel *lblPintar, QString color);
    int getIdRama();
    int getIdHoja();
    int getPidHoja();
    void setIdRama(int idRama);
    void setIdHoja(int idHoja);

private:
    int idHoja;
    int idRama;
    int pidHoja;
    Ui::MainWindow *main;
};

#endif // HOJA_H
