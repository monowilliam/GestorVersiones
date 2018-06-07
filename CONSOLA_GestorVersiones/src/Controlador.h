/*
 * Controlador.h
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "Archivo.h"
#include "Version.h"
#include <iostream>
#include <string>
#include <dirent.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#ifdef _WIN32
#define  limpiar  system("cls")
#endif
#ifdef linux
#define  limpiar   system("clear");
#endif

class Controlador {
public:
	Archivo a;
	Version v;
	Controlador();			//Constructor
	virtual ~Controlador();			//Destructor
	string obtenerString();			//Funcion para no usar cin
	void crearProyecto(string);		//Se crea el proyecto y se genera la version s_texto
	void crearArchivo(string);		//Crea un archivo con un nombre solicitado
	void eliminarArchivo(string);	//Elimina un archivo
	void buscarArchivo(string);		//Busca si un archivo existe
	void menu();					//Gestiona el menu 
	void menuObtener(string archivoControl, string archivoOriginal); 		//Gestiona el menu de obtener


};

#endif /* CONTROLADOR_H_ */
