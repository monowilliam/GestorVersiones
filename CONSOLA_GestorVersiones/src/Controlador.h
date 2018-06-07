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
	Controlador();
	virtual ~Controlador();
	string obtenerString();
	void crearProyecto(string);
	void crearArchivo(string);
	void eliminarArchivo(string);
	void buscarArchivo(string);
	void menu();
	void menuObtener(string archivoControl, string archivoOriginal);


};

#endif /* CONTROLADOR_H_ */
