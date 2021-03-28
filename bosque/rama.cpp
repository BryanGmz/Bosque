#include "rama.h"
#include "mainwindow.h"
#include "hoja.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sys/prctl.h>
#include <QApplication>

using namespace std;

Rama::Rama() {
  contadorHojas = 0;
}

Rama::Rama(Ui::MainWindow *main){
  contadorHojas = 0;
  this->main = main;
}

void Rama::setMostrar(bool mostrar){
  this->mostrar = mostrar;
}

void Rama::producirHojas(int numeroHojas, int idRam, Ui::MainWindow *main, Rama *rama){
    for (int i = 0; i < numeroHojas; i++) {
        Hoja nv = Hoja(main);
        Hoja *nuevaHoja = &nv;
        int pid_p = fork();
        if(pid_p > 0) { /*padre*/
            nuevaHoja->setIdHoja(i);
            nuevaHoja->setIdRama(idRam);
            nuevaHoja->setPidHoja(pid_p);
            rama->getHojas().push_back(*nuevaHoja);
            nuevaHoja->setMostrar(true);
            nuevaHoja->labelPintar("QLabel { background-color : blue; color : blue; }");
            sleep(1);
            qApp->processEvents();
            cout << "Hoja: "<<nuevaHoja->getIdHoja()<< " PID " << nuevaHoja->getPidHoja() << " SIZE " << rama->getHojas().size() <<endl;
          } else if(pid_p == 0) {
            cout << "[Hoja] PID "<<getpid() <<" from [Rama] PID "<< getppid()<< " ID - Hoja " << i <<endl;
            nuevaHoja->producirHoja();
            break;
        } else { /* Error */ }
    }
}

void Rama::pintar(QLabel *lblPintar, QString color){
  if(mostrar == true){
      sleep(2);
      cout<<"\nDesde pintar Rama "<<this->idRama<<" Planta "<<this->idPlanta<<endl<<endl;
      sleep(2);
      lblPintar->setStyleSheet(color);
      sleep(2);
      lblPintar->update();
      //qApp->processEvents();
    }
}

void Rama::labelPintar(QString color){
  cout<<"Main pintar rama"<<main<<endl;
  switch (this->idRama) {
    case 0:
      pintar(main->lblRama1, color);
      break;
    case 1:
      pintar(main->lblRama2, color);
      break;
    case 2:
      pintar(main->lblRama3, color);
      break;
    case 3:
      pintar(main->lblRama4, color);
      break;
    case 4:
      pintar(main->lblRama5, color);
      break;
    default:
      cout << "Error al pintar rama." << endl;
      break;
    }
}

void Rama::cambioMuestras(bool bandera){
  this->mostrar =true;
  cout << "Size Hojas " << this->hojas.size() << endl;
  for (int i = 0; i < this->hojas.size(); i++) {
      this->hojas.at(i).setMostrar(bandera);
      cout<<"Rama Muestra Cambio " << this->idRama << " Hoja " << this->hojas.at(i).getIdHoja() << endl;
    }
}

int Rama::getIdRama(){
  return this->idRama;
}

vector<Hoja> Rama::getHojas(){
  return this->hojas;
}

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

void Rama::mostrarRamas(){
  cout << "\nHojas en la rama: " << this->hojas.size() << endl << endl;
  for (int i = 0; i < this->hojas.size(); i++) {
      cout<<"Hoja "<<this->hojas[i].getIdHoja()<<endl;
    }
}
