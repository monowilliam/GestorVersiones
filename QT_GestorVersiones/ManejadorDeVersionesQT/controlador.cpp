/*
 * Controlador.cpp
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#include "controlador.h"
#include "ui_controlador.h"

//Constructor de la Clase Controlador
Controlador::Controlador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controlador){
    ui->setupUi(this);
}


//Destructor de la clase Controlador
Controlador::~Controlador(){
    delete ui;
}


//Boton que cierra el programa
void Controlador::on_BotonCerrar_clicked(){
    destroy();
}


//Funcion que es llamada cada vez que se cierre un programa
void Controlador::volverMenuPrincipal(){
    Controlador *VentanaMenu = new Controlador;
    VentanaMenu->show();
}


//Metodo que se usa para acceder a los proyectos creados con el programa, abre un aviso preguntando el nombre del archivo y despues cierra la ventalla e
//inicializa la ventana de las modificaciones de un proyecto
void Controlador::on_BotonModificar_clicked(){
    QString n = QInputDialog::getText(this,
                           "Archivo Fuente","Por favor ingrese el nombre del archivo que se encuentra en el repositorio:");
    string c = n.toStdString();
    string b= "s_"+c;
    if(!elArchivoExiste(c)){
        QMessageBox::warning(this,"Error Archivo Fuente","Seleccione un nombre de archivo valido");
    }else{
        ofstream archivoAescribir;
        archivoAescribir.open("dato.txt");
        archivoAescribir << c;
        archivoAescribir.close();
        ControladorModificar *VentanaModificar = new ControladorModificar;
        VentanaModificar->show();
        close();
    }
}


//Boton de crear un nuevo repositorio, el cual se abre y permite dos tipos de archivos .txt .py y les crea su archivoControl y una copia del
//Contenido del archivo que seleccione
void Controlador::on_BotonCrear_clicked(){
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Crear una version de un archivo"),
                                         QDir::currentPath(),
                                         tr("Archivos (*.txt *.py)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Manejador de Versiones ERROR"),
                             tr("No puedes abrir el archivo %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName),
                                  file.errorString()));
    return;
    }
    std::string x = fileName.toLocal8Bit().constData();
    string archivoControl = hallarArchivo(x);
    a.clonarVersion(x,archivoControl);
    crearArchivo(archivoControl);
}


//Metodo que nos permite encontrar el nombre de cualquier ruta de escritorio ejemplo: D://ubicacion/ejemplo.txt
string Controlador::hallarArchivo(string str){
    vector<string> vectorizado;
    int n = str.length();
    char char_array[n+1];
    strcpy(char_array, str.c_str());
    vector<char> aux;
    for (int i=0; i<n; i++){
        aux.push_back(char_array[i]);
    }
    for(int i=0; i<aux.size();i++){
        string s(1, aux[i]);
        vectorizado.push_back(s);
    }
    int indice;
    for(int i=0;i<vectorizado.size(); i++){
        if("/"==vectorizado[i]){
            indice=i;
        }
    }
    int indice2;
    for(int i=0;i<vectorizado.size(); i++){
        if("\""==vectorizado[i]){
            indice2=i;
        }
    }
    string ubicacion;
    for(int i=0;i<vectorizado.size(); i++){
        if(i>indice && i<indice2){
            ubicacion=ubicacion+vectorizado[i];
        }
    }
    return ubicacion;
}


//Metodo que retorna false o true si un archivo existe en el repositorio del manejador de versiones
bool Controlador::elArchivoExiste(string nom){
    FILE * archivo;
    if((archivo = fopen(nom.c_str(), "r"))){
        fclose(archivo);
        return true;
    }else
        return false;
}


//Metodo que crea un archivo asignando el respectivo s_ de control
void Controlador::crearArchivo(string nom){
    ofstream archivo;
    nom= "s_" + nom;
    archivo.open(nom,ios::out);
    archivo.close();
}


//Metodo que elimina un archivo del sistema
void Controlador::eliminarArchivo(string nom){
    const char *nom1 = nom.c_str();
    remove(nom1);
}
