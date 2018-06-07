/*
 * Version.h
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#ifndef VERSION_H_
#define VERSION_H_
#include "Archivo.h"

class Version : public Archivo{
public:
	Version();		//Constructor
	virtual ~Version();		//Destructor
	void buscarVersion(string nomVersion, string archivoControl);		//Busca si existe una version
	void generarVersion(string archivoControl, string archivoOriginal);		//Genera una version
	void imprimirVersiones(string archivoControl);			//Imprime las versiones actuales
	bool existeVersion(string archivoControl, string version);		//Verifica si existe una version
	vector<string> versionesAnterior(string version, string archivoControl);	//Almacena LOS NOMBRES DE LAS VERSIONES ANTERIORES
	void regenerarRecursivo(string archivoControl, string archivoOriginal,string version);		//Genera las versiones con respecto a la ANTERIOR
	void regenerarRecursivo2(string archivoControl, string archivoOriginal,string version, string n);	//Genera las versiones con respecto a la ANTERIOR
	void regenerarRecursivomeAnterior(string archivoControl, string archivoOriginal,string version);	////Genera las versiones con respecto a la ANTERIOR
};

#endif /* VERSION_H_ */
