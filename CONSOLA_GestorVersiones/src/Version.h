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
	Version();
	virtual ~Version();
	void buscarVersion(string nomVersion, string archivoControl);
	void generarVersion(string archivoControl, string archivoOriginal);
	void imprimirVersiones(string archivoControl);
	bool existeVersion(string archivoControl, string version);
	vector<string> versionesAnterior(string version, string archivoControl);
	void regenerarRecursivo(string archivoControl, string archivoOriginal,string version);
	void regenerarRecursivo2(string archivoControl, string archivoOriginal,string version, string n);
	void regenerarRecursivomeAnterior(string archivoControl, string archivoOriginal,string version);
};

#endif /* VERSION_H_ */
