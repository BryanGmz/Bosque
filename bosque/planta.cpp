#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "rama.h"
#include "planta.h"
#include <iostream>

using namespace std;

Planta::Planta(){}

void Planta::producirRamas(int numeroRamas, int numeroHojas, Ui::MainWindow *main){
    this->pidPlanta = getpid();
    this->contadorRamas = numeroRamas;
    for (int i = 0; i < numeroRamas; i++) {
        int pid_p = 0;
        pid_p = fork();
        if(pid_p == -1){
            printf("Error al crear el proceso hijo\n");
            break;
        } else if (pid_p == 0) {
            cout<<"Pid - Rama "<<getpid()<<endl;
            Rama rama = Rama();
            rama.setIdRama(i);
            rama.setIdPlanta(this->idPlanta);
            cout<<"Rama: "<<rama.getIdRama()<<" Numero Hojas: "<<numeroRamas<<endl;
            ramas.push_back(rama);
            this->ramas[i].producirHojas(numeroHojas, rama.getIdRama(), main);
            break;
        }
    }
}

void Planta::setIdPlanta(int idPlanta){
  this->idPlanta = idPlanta;
}

void Planta::setPidPlanta(int pidPlanta){
  this->pidPlanta = pidPlanta;
}

int Planta::getIdPlanta(){
  return this->idPlanta;
}

int Planta::getPidPlanta(){
  return this->pidPlanta;
}

/*vector<Rama> Planta::getRamas(){
  return this->ramas;
}*/
