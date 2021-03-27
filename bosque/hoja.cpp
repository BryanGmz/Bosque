#include "hoja.h"
#include "mainwindow.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <QWidget>
#include <QLabel>
#include <QApplication>

using namespace std;

Hoja::Hoja(){}

Hoja::Hoja(Ui::MainWindow * main){
  this->main = main;
}

void Hoja::pintar(QLabel *lblPintar, QString color){
  cout<<"\nDesde pintar "<<this->idHoja<<" Rama "<<this->idRama<<endl<<endl;
  sleep(1);
  lblPintar->setStyleSheet(color);
  qApp->processEvents();
}

void Hoja::producirHoja(){
  QString color = "QLabel { background-color : white; color : white; }";
  cout<<"\nDesde hoja "<<this->idHoja<<" Rama "<<this->idRama<<endl<<endl;
  if(idRama == 0){
      cout<<"\nDesde case "<<this->idHoja<<" Rama "<<this->idRama<<endl<<endl;
    }
  switch (this->idRama) {
      cout<<"\nDesde case "<<this->idHoja<<" Rama "<<this->idRama<<endl<<endl;
      /*  case 0:
          switch (this->idHoja) {
            case 0:
              pintar(main->lblHoja1_1, color);
            break;
            case 1:
              pintar(main->lblHoja1_2, color);
            break;
            case 2:
              pintar(main->lblHoja1_3, color);
            break;
            case 3:
              pintar(main->lblHoja1_4, color);
            break;
            case 4:
              pintar(main->lblHoja1_5, color);
            break;
            case 5:
              pintar(main->lblHoja1_6, color);
            break;
            case 6:
              pintar(main->lblHoja1_7, color);
            break;
            case 7:
              pintar(main->lblHoja1_8, color);
            break;
            case 8:
              pintar(main->lblHoja1_9, color);
            break;
            case 9:
              pintar(main->lblHoja1_10, color);
            break;
            }
        break;
        case 1:
          switch (this->idHoja) {
                  case 0:
                    pintar(main->lblHoja2_1, color);
                  break;
                  case 1:
                    pintar(main->lblHoja2_2, color);
                  break;
                  case 2:
                    pintar(main->lblHoja2_3, color);
                  break;
                  case 3:
                    pintar(main->lblHoja2_4, color);
                  break;
                  case 4:
                    pintar(main->lblHoja2_5, color);
                  break;
                  case 5:
                    pintar(main->lblHoja2_6, color);
                  break;
                  case 6:
                    pintar(main->lblHoja2_7, color);
                  break;
                  case 7:
                    pintar(main->lblHoja2_8, color);
                  break;
                  case 8:
                    pintar(main->lblHoja2_9, color);
                  break;
                  case 9:
                    pintar(main->lblHoja2_10, color);
                  break;
                  }
        break;
        case 2:
            switch (this->idHoja) {
                  case 0:
                    pintar(main->lblHoja3_1, color);
                  break;
                  case 1:
                    pintar(main->lblHoja3_2, color);
                  break;
                  case 2:
                    pintar(main->lblHoja3_3, color);
                  break;
                  case 3:
                    pintar(main->lblHoja3_4, color);
                  break;
                  case 4:
                    pintar(main->lblHoja3_5, color);
                  break;
                  case 5:
                    pintar(main->lblHoja3_6, color);
                  break;
                  case 6:
                    pintar(main->lblHoja3_7, color);
                  break;
                  case 7:
                    pintar(main->lblHoja3_8, color);
                  break;
                  case 8:
                    pintar(main->lblHoja3_9, color);
                  break;
                  case 9:
                    pintar(main->lblHoja3_10, color);
                  break;
                  }
        case 3:
              switch (this->idHoja) {
                  case 0:
                    pintar(main->lblHoja4_1, color);
                  break;
                  case 1:
                    pintar(main->lblHoja4_2, color);
                  break;
                  case 2:
                    pintar(main->lblHoja4_3, color);
                  break;
                  case 3:
                    pintar(main->lblHoja4_4, color);
                  break;
                  case 4:
                    pintar(main->lblHoja4_5, color);
                  break;
                  case 5:
                    pintar(main->lblHoja4_6, color);
                  break;
                  case 6:
                    pintar(main->lblHoja4_7, color);
                  break;
                  case 7:
                    pintar(main->lblHoja4_8, color);
                  break;
                  case 8:
                    pintar(main->lblHoja4_9, color);
                  break;
                  case 9:
                    pintar(main->lblHoja4_10, color);
                  break;
                  }
        break;
        case 4:
          switch (this->idHoja) {
                  case 0:
                    pintar(main->lblHoja5_1, color);
                  break;
                  case 1:
                    pintar(main->lblHoja5_2, color);
                  break;
                  case 2:
                    pintar(main->lblHoja5_3, color);
                  break;
                  case 3:
                    pintar(main->lblHoja5_4, color);
                  break;
                  case 4:
                    pintar(main->lblHoja5_5, color);
                  break;
                  case 5:
                    pintar(main->lblHoja5_6, color);
                  break;
                  case 6:
                    pintar(main->lblHoja5_7, color);
                  break;
                  case 7:
                    pintar(main->lblHoja5_8, color);
                  break;
                  case 8:
                    pintar(main->lblHoja5_9, color);
                  break;
                  case 9:
                    pintar(main->lblHoja5_10, color);
                  break;
                  }
        break;*/
      }
}

int Hoja::getIdHoja(){
    return this->idHoja;
}

int Hoja::getIdRama(){
    return  this->idRama;
}

int Hoja::getPidHoja(){
    return this->pidHoja;
}

void Hoja::setIdHoja(int idHoja){
  this->idHoja = idHoja;
}

void Hoja::setIdRama(int idRama){
  this->idRama = idRama;
}
