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
    Rama(Ui::MainWindow *main);
    void producirHojas(int numeroHojas, int idRam, Ui::MainWindow *main, Rama *rama);
    int getIdRama();
    int getIdPlanta();
    int getPidRama();
    vector<Hoja> getHojas();
    void setIdRama(int idRama);
    void setIdPlanta(int idPlanta);
    void setPidRama(int pidRama);
    void pintar(QLabel *lblPintar, QString color);
    void labelPintar(QString color);
    void setMostrar(bool mostrar);
    void cambioMuestras(bool bandera);
    void mostrarRamas();
    int contadorHojas;

private:
    int idRama;
    int idPlanta;
    int pidRama;
    bool mostrar;
    vector<Hoja> hojas;
    Ui::MainWindow *main;
};

#endif // RAMA_H
