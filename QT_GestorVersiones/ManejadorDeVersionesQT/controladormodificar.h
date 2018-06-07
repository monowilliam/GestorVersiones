/*
 * Controlador.h
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#ifndef CONTROLADORMODIFICAR_H
#define CONTROLADORMODIFICAR_H
#include "archivo.h"
#include "version.h"
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

//Clase que representa la ventana Modificadora del proyecto respetando el modelo vista controlador
namespace Ui {
class ControladorModificar;
}

class ControladorModificar : public QWidget
{
    Q_OBJECT

public:
    Archivo a;
    Version v;
    string archivoOriginal;
    string archivoControl;
    string version;
    explicit ControladorModificar(QWidget *parent = 0);
    ~ControladorModificar();
    void eliminarArchivo(string nom);

private slots:
    void on_BotonCerrar_clicked();
    void on_botonHistorial_clicked();
    void on_botonHistorial_clicked(bool checked);
    void on_botonVisualizar_clicked();
    void on_botonVisualizar_clicked(bool checked);
    void on_botonDiferencia_clicked();
    void on_botonDiferencia_clicked(bool checked);
    void on_botonGuardar_clicked();
    void on_botonModificar_clicked();
    void on_botonGuardar_clicked(bool checked);

private:
    Ui::ControladorModificar *ui;
};

#endif // CONTROLADORMODIFICAR_H
