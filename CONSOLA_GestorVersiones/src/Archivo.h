/*
 * Archivo.h
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Archivo {
private:
	vector<string> indiceOriginal;
	vector<string> textoOriginal1;        //Vector necesarios para recorrer el archivo
	vector<string> textoEditado;
public:
	vector<int> indiceEliminados;
	vector<int> indiceInsertados;
	vector<string> textoEliminados;        //Vectores que contienen texto e indice de texto eliminado e insertado
	vector<string> textoInsertados;
	vector<string> textoOriginal;
	Archivo();        //Constructor
	virtual ~Archivo();        //Destructor
	bool elArchivoExiste(string);        //Verifica si un archivo existe
	vector<string> split_iterator(const string& str);        //Divide un texto en varias palabras
	void clonarVersion(string archivoControl,string clon);        //Clona una version para despues ser modificada
	vector<vector<string>> devuelveVersiones(string archivoControl);        //Vector contenedor de las versiones SOLO EL NOMBRE DE ESTAS
	void agregarArchivoControl(string archivoControl, string archivoOriginal,string version);        //Se adhiere al archivo de control las modificaciones de una version.
	void imprimirArchivos(string archivo);        //Imprime un archivo LOL
	void modificar(string archivoControl);        //Modifica el archivo de control
	string obtenerDelta(string version, string archivoControl);        //Devuelve el delta del parametro que se ingresa
	void diferencia(string archivov1, string archivov2);        //Crea un pequeño archivo de control que contiene las diferencias
	void formatoDiferencia(string cambios);        //Imprime de una manera especifica las diferencias
};

#endif /* ARCHIVO_H_ */
