#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bosque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <QApplication>
#include <QLabel>
#include <QVector>

Bosque monatania;

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  monatania = Bosque();
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mensaje(QString msg){
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::agregarLbl(){
    ui->lblHoja1_1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_6->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_7->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_8->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_9->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja1_10->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_6->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_7->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_8->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_9->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja2_10->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_6->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_7->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_8->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_9->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja3_10->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_6->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_7->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_8->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_9->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja4_10->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_6->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_7->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_8->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_9->setStyleSheet("QLabel { background-color : ;}");
    ui->lblHoja5_10->setStyleSheet("QLabel { background-color : ;}");
    ui->lblRama1->setStyleSheet("QLabel { background-color : ;}");
    ui->lblRama2->setStyleSheet("QLabel { background-color : ;}");
    ui->lblRama3->setStyleSheet("QLabel { background-color : ;}");
    ui->lblRama4->setStyleSheet("QLabel { background-color : ;}");
    ui->lblRama5->setStyleSheet("QLabel { background-color : ;}");
    ui->lblTalloPrincipal->setStyleSheet("QLabel { background-color : gray;}");
    qApp->processEvents();
}

void MainWindow::on_btnIngresar_clicked() {
    //Variables de los parametros a utilizar
    char param_1;
    int param_2 = 0, param_3 = 0, param_4 = 0;
    //Obteniendo el comando
    QString txtString = ui->lineInputComand->text();
    string comando = txtString.toStdString();
    reemplazo(comando, '(', ' ');
    reemplazo(comando, ')', ' ');
    comando.erase(remove(comando.begin(), comando.end(), ' '), comando.end());
    ui->lblComando->setText("Este es el comando: \n" + QString::fromStdString(comando));
    sleep(2);
    ui->lblComando->setStyleSheet("QLabel { background-color : red; color : blue; }");
    qApp->processEvents();
    // Realizando split
    vector<string> resultados = split(comando, ',');
    if(resultados.size() > 4) {
        mensaje("Lo siento la cantidad de parametros, debe de ser menor a 5.");
    } else {
        bool error;
        for(int i = 0; i < resultados.size(); i++){
            if(error){
                break;
            }
            resultados[i].erase(remove(resultados[i].begin(), resultados[i].end(), ' '), resultados[i].end());
            switch (i) {
                case 0:
                    param_1 = resultados[0][0];
                    if(!(param_1 == 'p' || param_1 == 'P' || param_1 == 'i' || param_1 == 'I' || param_1 == 'M' || param_1 == 'm')){
                        mensaje("Error, los siento la instruccion no corresponde a ninguno de los registrados");
                        error = true;
                    }
                    if(!(param_1 == 'i' || param_1 == 'I')){
                        agregarLbl();
                      }
                break;
                case 1:
                    param_2 = stoi(resultados[1]);
                    if(param_2 < 1 || param_2 > 10) {
                         mensaje("Error, los siento el numero de plantas esta en el rango de (1, 10)");
                         error = true;
                    }
                break;
                case 2:
                    param_3 = stoi(resultados[2]);
                    if(param_3 < 1 || param_3 > 5) {
                         mensaje("Error, los siento el numero de ramas esta en el rango de (1, 5)");
                         error = true;
                    }
                break;
                case 3:
                    param_4 = stoi(resultados[3]);
                    if(param_4 < 1 || param_4 > 10) {
                         mensaje("Error, los siento el numero de hojas esta en el rango de (1, 10)");
                         error = true;
                    }
                break;
            }
        }
        if(!error) {
            if(param_1 == 'P' || param_1 == 'p'){
                cout<<param_3<<endl;
                cout<<param_4<<endl;
                monatania.construir(ui, param_1, param_2, param_3, param_4);
                ui->lblComando->setText(ui->lblComando->text() + "\n" + QString::fromStdString(resultados[0]) + QString::number(param_2 + param_3 + param_4));
                qApp->processEvents();
                sleep(2);
                ui->lblComando->setStyleSheet("QLabel { background-color : ; color : blue; }");
            } else if (param_1 == 'M' || param_1 == 'm'){

            } else if (param_1 == 'I' || param_1 == 'i'){
              monatania.greepPsTree(param_2);
              cout<<"\n\n\nYa puedes ir al fichero de salida: <Salida.txt>\n\n\n" << endl;
            } else {
              cout << "ERROR Parametro: " << param_1 << " No reconocido" << endl;
            }
        }
    }
    //qApp->processEvents();
}

vector<string> MainWindow::split(string str, char pattern) {
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

void MainWindow::reemplazo(string &v, char c1, char c2){
    for (int i = 0; i < v.length(); i++) {
        if (v[i] == c1) {
            v[i] = c2;
        }
    }
}
