#include "bosque.h"
#include "vector"
#include "iostream"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

Bosque::Bosque(){}

void Bosque::construir(Ui::MainWindow *main, char instruccion, int numeroPlanta, int numeroRamas, int numeroHojas){
  bool bandera =false;
  for (int i = 0; i < this->plantas.size(); ++i) {
      if(plantas[i].getIdPlanta() == numeroPlanta){
        bandera =true;
        }
    }
  if(!bandera){
      pid_t pid_p = fork();
      if(pid_p > 0){ //Padre
        } else if (pid_p == 0) {
          cout<<"Pid - Planta "<<getpid()<<endl;
          Planta planta = Planta();
          planta.setIdPlanta(numeroPlanta);
          planta.setPidPlanta(getpid());
          cout<<"Planta: "<<planta.getIdPlanta()<<" Numero Ramas: "<<numeroRamas<<endl;
          plantas.push_back(planta);
          planta.producirRamas(numeroRamas, numeroHojas, main);
        //return;
      } else {
          //Error
      }
  }
}
