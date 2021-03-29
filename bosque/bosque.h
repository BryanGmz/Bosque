#ifndef BOSQUE_H
#define BOSQUE_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <array>
#include <iostream>
#include <string.h>
#include <fstream>
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
    void escribirObjeto(int idPlanta, int numeroRamas, int numeroHojas);
    void escribirFichero(const string datos);
    void actualizar(int idPlanta, int numeroRamas, int numeroHojas);
    void plantar(Ui::MainWindow *main, int numeroPlanta, int numeroRamas, int numeroHojas, Planta *planta, bool hacer, bool mostrar);
    void reemplazo(string &v, char c1, char c2);
    void greepPsTree(int idPlanta);
    vector<string> split(string str, char pattern);
    string execComando(const string cmd, int &out_exitStatus);
    string obtenerObjeto(int idPlanta);

private:
    vector<Planta> plantas;
    Planta *plantaAnterior;
    Ui::MainWindow *main;
};

#endif // BOSQUE_H
