#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include "rama.h"
#include "ui_mainwindow.h"

using namespace std;

class Planta
{

public:
    Planta();
    void setIdPlanta(int idPlanta);
    void setPidPlanta(int pidPlanta);
    void producirRamas(int numeroRamas, int numeroHojas, Ui::MainWindow *main);
    int getIdPlanta();
    int getPidPlanta();
    //vector<Rama> getRamas();
    int contadorRamas;

private:
    int idPlanta;
    int pidPlanta;
    vector<Rama> ramas;

};

#endif // PLANTA_H
