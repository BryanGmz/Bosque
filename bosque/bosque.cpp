#include "bosque.h"
#include "vector"
#include "iostream"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <array>
#include <string.h>
#include <fstream>
#include <sys/prctl.h>

using namespace std;

Bosque::Bosque(){}

Bosque::Bosque(Ui::MainWindow *main){
  plantaAnterior = new Planta();
  this->main = main;
}

void Bosque::plantar(Ui::MainWindow *main, int numeroPlanta, int numeroRamas, int numeroHojas, Planta *planta, bool hacer, bool mostrar){
}

void Bosque::construir(Ui::MainWindow *main, char instruccion, int numeroPlanta, int numeroRamas, int numeroHojas){
  bool bandera =false;
  Planta *plant;
  if(plantas.size() > 0){
      for (int i = 0; i < this->plantas.size(); ++i) {
          if(plantas[i].getIdPlanta() == numeroPlanta){
            bandera =true;
            plant = &plantas[i];
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
      planta->producirRamas(numeroRamas, numeroHojas, main, planta, true);
      return;
  } else { /* Error */ }
  //cout << "Tamanio Vector: fuera: " << planta.getRamas().size() << endl;
}

void Bosque::actualizar(int idPlanta, int numeroRamas, int numeroHojas){
  string nuevo = obtenerObjeto(idPlanta);
  vector<string> resultados = split(nuevo, '\n');
  reemplazo(resultados[0], 'R', ' ');
  reemplazo(resultados[1], 'H', ' ');
  resultados[0].erase(remove(resultados[0].begin(), resultados[0].end(), ' '), resultados[0].end());
  resultados[1].erase(remove(resultados[1].begin(), resultados[1].end(), ' '), resultados[1].end());
  int r = numeroRamas;
  int h = stoi(resultados[1]);
  if(numeroHojas != 0) {
      h = numeroHojas;
    }
  if(numeroRamas == 0){
      r = 0;
      h = 0;
    }
  escribirObjeto(idPlanta, r, h);
  if(idPlanta == 1){
      system("killall planta_1");
    } else if (idPlanta == 2) {
      system("killall planta_2");
    } else if (idPlanta == 3) {
      system("killall planta_3");
    } else if (idPlanta == 4) {
      system("killall planta_4");
    } else if (idPlanta == 5) {
      system("killall planta_5");
    } else if (idPlanta == 6) {
      system("killall planta_6");
    } else if (idPlanta == 7) {
      system("killall planta_7");
    } else if (idPlanta == 8) {
      system("killall planta_8");
    } else if (idPlanta == 9) {
      system("killall planta_9");
    } else if (idPlanta == 10) {
      system("killall planta_10");
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

string Bosque::execComando(const string cmd, int &out_exitStatus){
    out_exitStatus = 0;
    auto pPipe = ::popen(cmd.c_str(), "r");
    if(pPipe == nullptr) {
        throw std::runtime_error("Cannot open pipe");
    }
    std::array<char, 256> buffer;
    std::string result;
    while(not std::feof(pPipe)) {
        auto bytes = std::fread(buffer.data(), 1, buffer.size(), pPipe);
        result.append(buffer.data(), bytes);
    }
    auto rc = ::pclose(pPipe);
    if(WIFEXITED(rc)) {
        out_exitStatus = WEXITSTATUS(rc);
    }
    return result;
}

void Bosque::escribirObjeto(int idPlanta, int numeroRamas, int numeroHojas){
    ofstream file ("./Planta_" + to_string(idPlanta));
    if(file.is_open()) {
        file << "R";
        file << to_string(numeroRamas);
        file << "\nH";
        file << to_string(numeroHojas);
        file.close();
    }
}

string Bosque::obtenerObjeto(int idPlanta){
    ifstream entrada ("./Planta_" + to_string(idPlanta));
    string temp;
    string temp2 = "";
    if(entrada.is_open()){
        while (getline(entrada, temp)) {
            temp2 += temp + "\n";
        }
        entrada.close();
    }
    return temp2;
}

void Bosque::escribirFichero(const string datos){
    ofstream file;
    ifstream entrada ("./Salida.txt");
    string temp;
    string temp2 = "";
    if(entrada.is_open()){
        while (getline(entrada, temp)) {
            temp2 += temp + "\n";
        }
        entrada.close();
    }
    cout << "TEMP \n";
    file.open("./Salida.txt");
    file << temp2;
    file << "\n";
    file << "---------------------------------------------------------------------------------------------------------------------------\n";
    file << datos;
    file << "\n";
    file << "---------------------------------------------------------------------------------------------------------------------------\n";
    file.close();
}

void Bosque::reemplazo(string &v, char c1, char c2){
    for (int i = 0; i < v.length(); i++) {
        if (v[i] == c1) {
            v[i] = c2;
        }
    }
}

vector<string> Bosque::split(string str, char pattern) {
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;
    while(posFound >= 0) {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }
    return resultados;
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

void Bosque::greepPsTree(int idPlanta){
    int exitStatus = 0;
    string comando = "pstree -c | grep planta_" + to_string(idPlanta);
    string result = execComando(comando, exitStatus);
    cout << "Este es la salida: " << endl;
    escribirFichero(result);
}
