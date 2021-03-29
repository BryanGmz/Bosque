#include "bosque.h"
#include "vector"
#include "iostream"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

Bosque::Bosque(){}

Bosque::Bosque(Ui::MainWindow *main){
  plantaAnterior = new Planta();
  this->main = main;
}

void Bosque::construir(Ui::MainWindow *main, char instruccion, int numeroPlanta, int numeroRamas, int numeroHojas){
  bool bandera =false;


  if(plantas.size() > 0){
      for (int i = 0; i < this->plantas.size(); ++i) {
          if(plantas[i].getIdPlanta() == numeroPlanta){
            bandera =true;
            }
        }
    }

  if(plantas.size() > 0){
      for(int i = 0; i < plantas.size(); i++) {
          cout<<"-------------- ID: " << plantas[i].getIdPlanta();
          plantas[i].mostrarPlanta();
          cout << "-----------------------------------------" << endl;
        }
    }
  if(!bandera){
      Planta p = Planta(main);
      Planta *planta  = &p;
      int pid_p = fork();
      if(pid_p > 0){ /*Padre*/
          planta->setIdPlanta(numeroPlanta);
          planta->setPidPlanta(pid_p);
          this->plantas.push_back(*planta);
          planta->setMostrar(true);
          planta->labelPintar("QLabel { background-color : black; color : blue; }");
          qApp->processEvents();
          cout<<"Planta: "<<planta->getIdPlanta()<<" Numero Ramas: "<< planta->getRamas().size() << " PID " << planta->getPidPlanta() << " SIZE " << this->plantas.size() <<endl;
          //cout << "Tamanio Vector: if: " << planta.getRamas().size() << endl;
        } else if (pid_p == 0) {
          cout << "[Tallo] PID "<<getpid() <<" from [Programa] PID "<< getppid()<<endl;
          planta->producirRamas(numeroRamas, numeroHojas, main, planta);
          return;
      } else { /* Error */ }
      //cout << "Tamanio Vector: fuera: " << planta.getRamas().size() << endl;
  }
}

void Bosque::cambioDeMuestras(Planta *plantaNueva){
  if(plantaAnterior != NULL){
      for(int i = 0; i < plantaAnterior->getRamas().size(); i++){
          plantaAnterior->getRamas()[i].setMostrar(false);
          plantaAnterior->getRamas()[i].cambioMuestras(false);
        }
    }
  if(plantaNueva != NULL){
      plantaAnterior = plantaNueva;
      for(int i = 0; i < plantaNueva->getRamas().size(); i++){
          plantaNueva->getRamas()[i].setMostrar(true);
          plantaNueva->getRamas()[i].cambioMuestras(true);
        }
    }
}

void Bosque::realizarPintura(Planta *planta, int numeroRamas, int numeroHojas){
  bool banderaFin = true;
  while(banderaFin){
      for (int i = 0; i < planta->getRamas().size(); i++) {
          cout << "ID " << i << " SIZE " << planta->getRamas().at(i).getHojas().size() << " HOJAS " << numeroHojas <<endl;
        if(planta->getRamas().at(i).getHojas().size() == numeroHojas){
            if(banderaFin == true && (i < planta->getRamas().size())){
                banderaFin = false;
            }
          }
      }
      cout<<"Aqui"<<endl;
    }
  planta->cambioMuestras(true);
  cout << "Tamanio Vector: elif: " << planta->getRamas().size() << endl;

}

void Bosque::pintar(Planta *planta){
  //cout << endl << "Planeta " << planta << endl;
  for (int i = 0; i < planta->getRamas().size(); i++) {
      planta->labelPintar("QLabel { background-color : black; color : blue; }");
      for (int j = 0; j < planta->getRamas().size(); j++) {
          planta->getRamas()[j].labelPintar("QLabel { background-color : red; color : blue; }");
          for(int k = 0; k < planta->getRamas()[j].getHojas().size(); k++){
              planta->getRamas()[j].getHojas()[k].labelPintar("QLabel { background-color : blue; color : blue; }");
            }
        }
    }
}
