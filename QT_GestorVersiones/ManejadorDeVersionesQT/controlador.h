/*
 * Controlador.h
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QMainWindow>
#include <QIcon>
#include <QTreeWidget>
#include <QtWidgets>
#include <controladormodificar.h>
#include "archivo.h"
#include "version.h"

//Clase Controlador que representa toda la interfaz grafica del proyecto
namespace Ui {
class Controlador;
}

class Controlador : public QMainWindow
{
    Q_OBJECT

public:
    Archivo a;
    Version v;
    bool elArchivoExiste(string nom);
    void crearArchivo(string nom);
    void eliminarArchivo(string nom);
    explicit Controlador(QWidget *parent = 0);
    void volverMenuPrincipal();
    ~Controlador();
    string hallarArchivo(string str);

private slots:
    void on_BotonCerrar_clicked();
    void on_BotonModificar_clicked();
    void on_BotonCrear_clicked();

private:
    Ui::Controlador *ui;
};

#endif // CONTROLADOR_H
