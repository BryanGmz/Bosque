#ifndef RAMA_H
#define RAMA_H

#include <vector>
#include "hoja.h"
#include "ui_mainwindow.h"

using namespace std;

class Rama
{
public:
    Rama();
    void producirHojas(int numeroHojas, int idRam, Ui::MainWindow *main);
    int getIdRama();
    int getIdPlanta();
    int getPidRama();
    //vector<Hoja> getHojas();
    void setIdRama(int idRama);
    void setIdPlanta(int idPlanta);
    void setPidRama(int pidRama);
    int contadorHojas;

private:
    int idRama;
    int idPlanta;
    int pidRama;
    vector<Hoja> hojas;
};

#endif // RAMA_H
