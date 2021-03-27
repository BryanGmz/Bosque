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
      int pid_p = 0;
      pid_p = fork();
      if(pid_p == -1){
          printf("Error al crear el proceso hijo\n");
          exit(0);
      } else if (pid_p == 0) {
        cout<<"Pid - Planta "<<getpid()<<endl;
        Planta rama = Planta();
        rama.setIdPlanta(numeroPlanta);
        rama.setPidPlanta(getpid());
        cout<<"Planta: "<<rama.getIdPlanta()<<" Numero Ramas: "<<numeroRamas<<endl;
        plantas.push_back(rama);
        rama.producirRamas(numeroRamas, numeroHojas, main);
        return;
      }
  }
}
