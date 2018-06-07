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
    vector<string> textoOriginal1;
    vector<string> textoEditado;
public:
    vector<int> indiceEliminados;
    vector<int> indiceInsertados;
    vector<string> textoEliminados;
    vector<string> textoInsertados;
    vector<string> textoOriginal;
    Archivo();
    virtual ~Archivo();
    bool elArchivoExiste(string);
    vector<string> split_iterator(const string& str);
    void clonarVersion(string archivoControl,string clon);
    vector<vector<string>> devuelveVersiones(string archivoControl);
    void agregarArchivoControl(string archivoControl, string archivoOriginal,string version);
    void imprimirArchivos(string archivo);
    void modificar(string archivoControl);
    string obtenerDelta(string version, string archivoControl);
    void diferencia(string archivov1, string archivov2);
    void formatoDiferencia(string cambios);
};

#endif /* ARCHIVO_H_ */
