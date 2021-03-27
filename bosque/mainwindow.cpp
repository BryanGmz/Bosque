#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bosque.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
     //labelRamas.append(ui->lblRama1);
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
    //ui->lblComando->setStyleSheet("QLabel { background-color : " + QString::fromStdString(comado) + "; color : white; }");
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
            cout<<param_3<<endl;
            cout<<param_4<<endl;
            monatania.construir(ui, param_1, param_2, param_3, param_4);
            ui->lblComando->setText(ui->lblComando->text() + "\n" + QString::fromStdString(resultados[0]) + QString::number(param_2 + param_3 + param_4));
            qApp->processEvents();
            sleep(2);
            ui->lblComando->setStyleSheet("QLabel { background-color : ; color : blue; }");
        }
    }
    qApp->processEvents();
}

/*
bool MainWindow::contiene(vector<Planta> plantas, int comparacion){
    return true;
}
*/

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
