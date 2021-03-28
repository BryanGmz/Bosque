#ifndef BOSQUE_H
#define BOSQUE_H


#include <vector>
#include "planta.h"
#include "ui_mainwindow.h"

using namespace std;

class Bosque
{
public:
    Bosque();
    Bosque(Ui::MainWindow *main);
    void mostrar(Planta *planta);
    void realizarPintura(Planta *planta, int numeroRamas, int numeroHojas);
    void cambioDeMuestras(Planta *plantaNueva);
    void pintar(Planta *planta);
    void construir(Ui::MainWindow *main, char instruccion, int numeroPlanta, int numeroRamas, int numeroHojas);

private:
    vector<Planta> plantas;
    Planta *plantaAnterior;
    Ui::MainWindow *main;
};

#endif // BOSQUE_H
