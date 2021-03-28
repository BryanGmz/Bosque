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
    Planta(Ui::MainWindow *main);
    void setIdPlanta(int idPlanta);
    void setPidPlanta(int pidPlanta);
    void producirRamas(int numeroRamas, int numeroHojas, Ui::MainWindow *main, Planta *planta);
    void setMostrar(bool mostrar);
    void pintar(QLabel *lblPintar, QString color);
    void labelPintar(QString color);
    void cambioMuestras(bool bandera);
    int getIdPlanta();
    int getPidPlanta();
    void mostrarPlanta();
    vector<Rama> getRamas();
    int contadorRamas;

private:
    int idPlanta;
    int pidPlanta;
    bool mostrar;
    vector<Rama> ramas;
    Ui::MainWindow *main;
};

#endif // PLANTA_H
