#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "rama.h"
#include "planta.h"
#include <iostream>
#include <QApplication>
#include <QWidget>

using namespace std;

Planta::Planta(){}

Planta::Planta(Ui::MainWindow *main){
  this->main = main;
}

bool Planta::getMostrar(){
  return this->mostrar;
}

void Planta::producirRamas(int numeroRamas, int numeroHojas, Ui::MainWindow *main, Planta *planta, bool mostrar){
  for (int i = 0; i < numeroRamas; i++) {
      Rama r = Rama(main);
      Rama *rama = &r;
      int pid_p = fork();
      if(pid_p > 0) { /*Padre*/
          rama->setIdRama(i);
          rama->setIdPlanta(this->idPlanta);
          rama->setPidRama(pid_p);
          planta->getRamas().push_back(*rama);
          rama->setMostrar(mostrar);
          rama->labelPintar("QLabel { background-color : rgb(143, 89, 2); color : blue; }");
          sleep(1);
          qApp->processEvents();
          cout<<"Rama: "<<rama->getIdRama()<<" Numero Hojas: "<< rama->getHojas().size() << " PID " << rama->getPidRama() << " SIZE " << planta->getRamas().size() <<endl;
        } else if (pid_p == 0) {
          cout << "[Rama] PID "<<getpid() <<" from [Planta] PID "<< getppid()<< " ID - Rama " << i <<endl;
          rama->producirHojas(numeroHojas, i, main, rama, mostrar);
          //cout<<"Rama Despues: "<<0<<" Numero Hojas: "<< rama.getHojas().size() << " PID " << 0 << " SIZE " << this->getRamas().size() <<endl;
          //exit(0);
          break;
      } else { /* Error */ }
  }
}

void Planta::pintar(QLabel *lblPintar, QString color){
  cout << "Bandera Tallo "<< this->mostrar << endl;
  if(mostrar == true){
      sleep(2);
      cout<<"\nDesde pintar Tallo "<<this->idPlanta<<" PID "<<this->pidPlanta<<endl<<endl;
      sleep(2);
      lblPintar->setStyleSheet(color);
      sleep(2);
      lblPintar->update();
      //qApp->processEvents();
    }
}

void Planta::cambioMuestras(bool bandera){
  this->mostrar = true;
  cout << "Size Ramas " << ramas.size() << endl;
  for (int i = 0; i < this->ramas.size(); i++) {
      this->ramas.at(i).setMostrar(bandera);
      this->ramas.at(i).cambioMuestras(bandera);
    }
}

void Planta::labelPintar(QString color){
  pintar(main->lblTalloPrincipal, color);
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

vector<Rama> Planta::getRamas(){
  return this->ramas;
}

void Planta::setMostrar(bool mostrar){
  this->mostrar = mostrar;
}

void Planta::mostrarPlanta(){
  cout << "\nRamas en la planta: " << this->ramas.size() << endl << endl;
  for (int i = 0; i < this->ramas.size(); i++) {
      cout<<"Rama "<<this->ramas[i].getIdRama()<<endl;
    }
}
