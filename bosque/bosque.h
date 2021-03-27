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
    void construir(Ui::MainWindow *main, char instruccion, int numeroPlanta, int numeroRamas, int numeroHojas);

private:
    vector<Planta> plantas;
};

#endif // BOSQUE_H
