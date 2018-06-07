/*
 * Versiones.cpp
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#include "Version.h"


Version::Version() {}


Version::~Version() {}


void Version::buscarVersion(string nomVersion, string archivoControl){
	char separador = '|';
	int w1;
	ifstream archivo;
	string linea;
	int contador=0;
	int flag=0;
	archivo.open(archivoControl.c_str());
	if (archivo.fail () == true ) { // Verificacion
		cout << ("Error abriendo el archivo de texto") << endl;
		exit (1);
	}
	while(!archivo.eof()){
		getline(archivo,linea);
		contador++;
		if(flag==1){
			for (int i=0; i < (split_iterator(linea).size()); i++){
				if(split_iterator(linea)[i]=="Version")
					flag=0;
			}
			int n = sizeof(linea);
			if(linea[0]=='e'){
				for(w1=0; w1<n; w1++){
					if(linea[w1]==separador){
						break;
					}
				}
				string ind = linea.substr(0,w1);
				string  tex= linea.substr(w1+1);
				char k=ind[2];
				int x = (int)k - 48;
				indiceEliminados.push_back(x);
				textoEliminados.push_back(tex);
			}
			if(linea[0]=='i'){
				for(w1=0; w1<n; w1++){
					if(linea[w1]==separador){
						break;
					}
				}
				string ind = linea.substr(0,w1);
				string  tex= linea.substr(w1+1);
				char k=ind[2];
				int x = (int)k - 48;
				indiceInsertados.push_back(x);
				textoInsertados.push_back(tex);
			}
		}
		if(linea == "Version "+nomVersion){
			flag=1;
		}
	}
	archivo.close();
}



//Funcion que Regenera una version dado los archivos Originales y el de Control.
void Version::generarVersion(string archivoControl, string archivoOriginal){
	string linea;
	int contador=0;
	ifstream archivo;
	archivo.open(archivoOriginal.c_str());
	if (archivo.fail () == true) { // Verificacion
		cout << ("Error abriendo el archivo de texto")<< endl;
		exit (1);
	}
	while(!archivo.eof()){
		contador++;
		getline(archivo,linea);
		textoOriginal.push_back(linea);
	}
	ofstream archivoGenerado("generado.txt");
	//Elimina las lineas
	int j=indiceEliminados.size();
	for(int i=0; i<indiceEliminados.size(); i++){
		textoOriginal.erase(textoOriginal.begin()+indiceEliminados.at(j-1)-1);
		j--;
	}
	//Agrega las lineas
	for(int i=0; i<indiceInsertados.size(); i++){
		textoOriginal.insert(textoOriginal.begin()+indiceInsertados.at(i)-1, textoInsertados.at(i));
	}
	//Imprime en el generar.txt todo el vector textoOriginal ya modificado
	for(int i=0; i<textoOriginal.size(); i++){
		archivoGenerado<<textoOriginal.at(i);
		archivoGenerado<<endl;
	}
	archivo.close();
	archivoGenerado.close();
	while(!indiceEliminados.empty() ){
		indiceEliminados.pop_back();
	}
	while(!indiceInsertados.empty()){
		indiceInsertados.pop_back();
	}
	while(!textoEliminados.empty()){
		textoEliminados.pop_back();
	}
	while(!textoInsertados.empty()){
		textoInsertados.pop_back();
	}
	while(!textoOriginal.empty()){
		textoOriginal.pop_back();
	}
}



void Version::imprimirVersiones(string archivoControl){
    vector<string> versiones;
    ifstream archivo;
    ofstream version;
    string linea;
    int contador=0;
    version.open("versiones.txt");
    archivo.open(archivoControl.c_str());
    if (archivo.fail () == true ) { // Verificacion
        cout << "Error abriendo el diccionario (puede que el archivo no existe, inicie de nuevo)" << endl;
        exit (1);
    }
    while(!archivo.eof()){
        getline(archivo,linea);
        contador++;
            for(int i=0;i<split_iterator(linea).size();i++){
                if(split_iterator(linea)[i]=="Version"){
                    versiones.push_back(split_iterator(linea)[i+1]);
                }
            }
    }
    sort(versiones.begin(),versiones.end());
    for(int i=0;i<versiones.size();i++){
                version<<"Version "<<versiones[i]<<endl;
    }if(versiones.empty())
        version << "No existen versiones, por favor modifique la version original "<<endl<<endl;
    archivo.close();
    version.close();
}




bool Version::existeVersion(string archivoControl, string version){
	vector<vector<string>> todasVersiones = devuelveVersiones(archivoControl);
	int flag=0;
	vector<string> versionDiv;
	if(version == "ultima" && todasVersiones.empty()){
		flag=1;
	}
	if(version=="ultima"){
		versionDiv=todasVersiones[todasVersiones.size()-1];
	}
	else{
		string str= version;
		int n = str.length();
	    char char_array[n+1];
	    strcpy(char_array, str.c_str());
		vector<char> aux;
		for (int i=0; i<n; i++){
	    	aux.push_back(char_array[i]);
		}
		for(int i=0; i<aux.size();i++){
			string s(1, aux[i]);
			versionDiv.push_back(s);
		}
	}
	for(int i=0;i<todasVersiones.size();i++){
		if(todasVersiones[i]==versionDiv){
			flag=1;
		}
	}
	if(flag==0){
		return flag;
	}
	return flag;
}


vector<string> Version::versionesAnterior(string version, string archivoControl){
	vector<vector<string>> todasVersiones = devuelveVersiones(archivoControl);
	vector<vector<string>> anteriores;
	vector<string> anterioresUnido;
	string str= version;
	int n = str.length();
    char char_array[n+1];
    strcpy(char_array, str.c_str());
	vector<char> aux;
	for (int i=0; i<n; i++){
    	aux.push_back(char_array[i]);
	}
	vector<string> versionDiv;
	for(int i=0; i<aux.size();i++){
		string s(1, aux[i]);
		versionDiv.push_back(s);
	}
	int flag=0;
	for(int i=0;i<todasVersiones.size();i++){
		if(flag==0){
			if(todasVersiones[i]==versionDiv){
				flag=1;
			}
			if(versionDiv.size()==3 && todasVersiones[i].size()==3){
				anteriores.push_back(todasVersiones[i]);
			}
			else if(versionDiv.size()!=3){
				if(versionDiv[2]==todasVersiones[i][2] || todasVersiones[i].size()==3){
					anteriores.push_back(todasVersiones[i]);
				}
			}
		}
	}
	for(int i=0; i<anteriores.size();i++){
		string final;
		for(int j=0; j<anteriores[i].size();j++){
			final=final+anteriores[i][j];
		}
		anterioresUnido.push_back(final);
	}
	/*
	for(int i=0;i<anterioresUnido.size();i++){
		cout<<anterioresUnido[i]<<endl;
	}
	*/
    return anterioresUnido;
}



void Version::regenerarRecursivo(string archivoControl, string archivoOriginal,string version){
	vector<string> versionesAnteriores = versionesAnterior(version,archivoControl);
	for (int i=0; i<versionesAnteriores.size(); i++){
		if(i==0){
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,archivoOriginal);
		}else{
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,"generado.txt");
		}
	}
}

void Version::regenerarRecursivomeAnterior(string archivoControl, string archivoOriginal,string version){
	vector<string> versionesAnteriores = versionesAnterior(version,archivoControl);
	versionesAnteriores.pop_back();
	for (int i=0; i<versionesAnteriores.size(); i++){
		if(i==0){
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,archivoOriginal);
		}else{
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,"generado.txt");
		}
	}
	clonarVersion("generado.txt","generadoAnterior.txt");
}


void Version::regenerarRecursivo2(string archivoControl, string archivoOriginal,string version, string n){
	vector<string> versionesAnteriores = versionesAnterior(version,archivoControl);
	for (int i=0; i<versionesAnteriores.size(); i++){
		if(i==0){
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,archivoOriginal);
		}else{
			buscarVersion(versionesAnteriores[i],archivoControl);
			generarVersion(archivoControl,"generado.txt");
		}
	}clonarVersion("generado.txt",n.c_str());
}


