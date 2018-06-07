/*
 * ControladorModificar.cpp
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#include "controladormodificar.h"
#include "ui_controladormodificar.h"
#include "controlador.h"
#include "controladorcambiar.h"

//Metodo constructor que inicializar toda la ventana
ControladorModificar::ControladorModificar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControladorModificar)
{
    ifstream archivo;
    archivo.open("dato.txt");
    getline(archivo,archivoOriginal);
    archivo.close();
    archivoControl="s_"+archivoOriginal;
    eliminarArchivo("dato.txt");
    ui->setupUi(this);
    ui->label->setText(archivoOriginal.c_str());

}


//Destructor de la Ventana
ControladorModificar::~ControladorModificar(){
    delete ui;
}


//Boton que cierra la ventana y abre la ventana del menu principal
void ControladorModificar::on_BotonCerrar_clicked(){
    Controlador ventanaMenu;
    ventanaMenu.volverMenuPrincipal();
    destroy();
}


//Boton que representa toda la accion del proyecto-> HISTORIAL....
//Muestra en pantalla las versiones disponibles del archivo control
void ControladorModificar::on_botonHistorial_clicked(){
    v.imprimirVersiones(archivoControl);
    QFile file("versiones.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}


//Boton que representa cuando el boton Historia no esta presionado
void ControladorModificar::on_botonHistorial_clicked(bool checked){
    if(checked==false){
        eliminarArchivo("versiones.txt");
    }
}


//Boton que muestra en pantalla cualquier version del archivo de control, reconstruyendo el archivo con OBTENER y mostrarlo en pantalla
void ControladorModificar::on_botonVisualizar_clicked(){
    QString n = QInputDialog::getText(this,
                           "Visualizar Version","Ingrese la version que desea visualizar:");
    std::string version = n.toLocal8Bit().constData();
    if(v.existeVersion(archivoControl,version)){
        v.regenerarRecursivo(archivoControl,archivoOriginal,version);
        QFile file("generado.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }else{
        QMessageBox::warning(this,"Error en la version","Version no existe, ingrese una version valida");
    }
}


//Boton que representa cuando el botono Visualizar no esta presionado
void ControladorModificar::on_botonVisualizar_clicked(bool checked){
    if(checked==false){
        eliminarArchivo("generado.txt");
    }
}



//Boton que representa la DIFERENCIA en el proyecto, dandos dos versiones que se piden como mensajes, retorna las diferencias entre ellos
void ControladorModificar::on_botonDiferencia_clicked(){
    QString v1 = QInputDialog::getText(this,
                           "Version 1","Escribe la primera version a DIFERENCIAR:");
    QString v2 = QInputDialog::getText(this,
                           "Version 2","Escribe la segunda version a DIFERENCIAR:");
    string version1 = v1.toLocal8Bit().constData();
    string version2 = v2.toLocal8Bit().constData();
    if(v.existeVersion(archivoControl,version2) && version1 == "1.1"){
        v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
        a.diferencia(archivoOriginal,"v2.txt");
        a.formatoDiferencia("diferencias.txt");
        eliminarArchivo("v2.txt");
        eliminarArchivo("generado.txt");
        eliminarArchivo("diferencias.txt");
        QFile file("dif.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }
    else if(v.existeVersion(archivoControl,version1) && version2 == "1.1"){
        v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
        a.diferencia("v2.txt",archivoOriginal);
        a.formatoDiferencia("diferencias.txt");
        eliminarArchivo("v2.txt");
        eliminarArchivo("generado.txt");
        eliminarArchivo("diferencias.txt");
        QFile file("dif.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }
    else if(v.existeVersion(archivoControl,version1) && v.existeVersion(archivoControl,version2)){
        v.regenerarRecursivo2(archivoControl,archivoOriginal,version1,"v1.txt");
        v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
        v.diferencia("v1.txt","v2.txt");
        a.formatoDiferencia("diferencias.txt");
        a.imprimirArchivos("dif.txt");
        eliminarArchivo("v1.txt");
        eliminarArchivo("v2.txt");
        eliminarArchivo("generado.txt");
        eliminarArchivo("diferencias.txt");
        QFile file("dif.txt");
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }else{
        QMessageBox::warning(this,"Error en versiones","Alguna de las Versiones no existe, ingrese versiones validas e intente de nuevo");
    }
}


//Boton que representa que no esta presionado el boton Diferencia
void ControladorModificar::on_botonDiferencia_clicked(bool checked){
    eliminarArchivo("dif.txt");
}


//Metodo que elimina un archivo del sistema
void ControladorModificar::eliminarArchivo(string nom){
    const char *nom1 = nom.c_str();
    remove(nom1);
}


//Boton que representa el Guardar un cambio del requerimiento MODIFICAR
void ControladorModificar::on_botonGuardar_clicked(){
    a.agregarArchivoControl(archivoControl, archivoOriginal, version);
    a.modificar(archivoControl);
    QFile file("temporal_Control.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}


//Boton que representa el requerimiento MODIFICAR, el cual dada una version habilita un boton
//para editar y guardar los cambios del archivo y ver su respectivo cambio
void ControladorModificar::on_botonModificar_clicked(){
    QString v1 = QInputDialog::getText(this,
                           "Version","Escribe la version a MODIFICAR:");
    version = v1.toLocal8Bit().constData();

    version=a.obtenerDelta(version, archivoControl);
        if(version=="?"){
            QMessageBox::warning(this,"Error en versiones","Su version no es compatible por intentelo de nuevo");
        }else{
            a.clonarVersion(archivoOriginal,"editarAQUI.txt");
            eliminarArchivo("generado.txt");
            QFile file("editarAQUI.txt");
            if(!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"info",file.errorString());
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());
            ui->botonGuardar->setEnabled(true);
        }
}


//Metodo que representa cuando el boton Guardar no esta siendo presionado
void ControladorModificar::on_botonGuardar_clicked(bool checked){
    eliminarArchivo("temporal_Control.txt");
}
