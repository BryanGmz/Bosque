#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bosque.h>
#include <iostream>
#include <string>
#include <QApplication>
#include <QVector>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void agregarLbl();
    void mensaje(QString msg);
    void reemplazo(std::string &v, char c1, char c2);
    std::vector<std::string> split(std::string str, char pattern);

private slots:
    void on_btnIngresar_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLabel> labelRamas;
    QVector<QLabel> labelHojasRama;
};
#endif // MAINWINDOW_H
