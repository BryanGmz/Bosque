#include "rama.h"
#include "mainwindow.h"
#include "hoja.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

Rama::Rama() {
  contadorHojas = 0;
}

void Rama::producirHojas(int numeroHojas, int idRam, Ui::MainWindow *main){
    this->pidRama = getpid();
    this->contadorHojas = numeroHojas;
    for (int i = 0; i < numeroHojas; i++) {
        int pid_p = 0;
        pid_p = fork();
        if(pid_p == -1){
            printf("Error al crear el proceso hoja de rama");
            break;
        } else if(pid_p == 0) {
            cout<<"Pid - Hoja "<<getpid()<<endl;
            Hoja nuevaHoja = Hoja(main);
            nuevaHoja.setIdHoja(i);
            nuevaHoja.setIdRama(idRam);
            cout<<"Hojas "<< nuevaHoja.getIdHoja() <<" Rama: " << nuevaHoja.getIdRama() <<endl;
            hojas.push_back(nuevaHoja);
            nuevaHoja.producirHoja();
            break;
        }
    }
}

int Rama::getIdRama(){
  return this->idRama;
}

/*vector<Hoja> Rama::getHojas(){
  return this->hojas;
}*/

int Rama::getPidRama(){
  return this->pidRama;
}

int Rama::getIdPlanta(){
  return this->idPlanta;
}

void Rama::setIdRama(int idRama){
  this->idRama = idRama;
}

void Rama::setPidRama(int pidRama){
  this->pidRama = pidRama;
}

void Rama::setIdPlanta(int idPlanta){
  this->idPlanta = idPlanta;
}
