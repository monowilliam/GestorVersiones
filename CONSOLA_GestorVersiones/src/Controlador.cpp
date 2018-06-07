/*
 * Controlador.cpp
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */
#include "Controlador.h"

Controlador::Controlador() {}			//Constructor

Controlador::~Controlador() {}			//Destructor


string Controlador::obtenerString(){
	string a;
	cin>>a;								//Funcion para no usar cin
	return a;
}



void Controlador::buscarArchivo(string elemento){
	if(!a.elArchivoExiste(elemento)){
		cout << endl <<"El archivo no existe, por favor crear el archivo en la carpeta raiz";
		cout << endl;
		system("pause");				//Busca si un archivo existe
		menu();
	}
}


void Controlador::crearArchivo(string nom){
	ofstream archivo;
	nom= "s_" + nom;
	archivo.open(nom,ios::out);				//Se crea el proyecto y se genera la version s_texto
	archivo.close();
	cout << endl;
	system("pause");
	limpiar;
}


void Controlador::eliminarArchivo(string nom){
	const char *nom1 = nom.c_str();			//Elimina un archivo
	remove(nom1);
}


void Controlador::crearProyecto(string nom){
	buscarArchivo(nom);					//Se crea el proyecto y se genera la version s_texto
	crearArchivo(nom);
}


void Controlador::menuObtener(string archivoControl, string archivoOriginal){
	string version;
	string decision;
	cout<<endl<<"Que desea realizar: "<<endl;
	cout<<endl<<"1 - HISTORIAL de todas las versiones creadas"<<endl;
	cout<<endl<<"2 - VISUALIZAR una Version"<<endl;
	cout<<endl<<"3 - MODIFICAR una Version"<<endl;
	cout<<endl<<"4 - DIFERENCIAS de dos versiones"<<endl;
	cout<<endl<<"0 - Cancelar"<<endl <<endl;
	cin>>decision;
	if(decision=="1"){
		limpiar;
		cout<<"Versiones disponibles para: " << archivoControl<< endl<<endl;
		v.imprimirVersiones(archivoControl);
		v.imprimirArchivos("versiones.txt");
		eliminarArchivo("versiones.txt");
		system("pause");
		cout << endl;
		limpiar;
		menuObtener(archivoControl,archivoOriginal);			//Gestiona el menu de obtener
	}
	else if(decision=="2"){
		limpiar;
		string version;
		cout<<"Escribe la version que desea visualizar ejemplo: '1.2'"<< endl << "En caso de que quieras visualizar la ultima version escribe 'ultima': "; cin>>version;
		if(v.existeVersion(archivoControl,version)){
			limpiar;
			v.regenerarRecursivo(archivoControl,archivoOriginal,version);
			cout <<"Tu Version " << version<< " es la siguiente:"<<endl<<endl;
			a.imprimirArchivos("generado.txt");
			eliminarArchivo("generado.txt");
			cout << endl; system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}else{
			cout<<endl<<"Version no existe, ingrese una version valida"<<endl<<endl;
			system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}
	}
	else if(decision=="3"){
		limpiar;
		string version;
		string x=version;
		cout<<"Escribe la version que desea modificar ejemplo: '1.2'"<< endl << "En caso de que quieras modificar la ultima version escribe 'ultima': "; cin>>version;
		version=a.obtenerDelta(version, archivoControl);
		if(version=="?"){
			cout << "Error, su version no es compatible por intentelo de nuevo "<<endl;
			system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}else{
			limpiar;
			cout <<"Porfavor edita el archivo 'editarAQUI.txt', guarde y confirma con cualquier tecla la finalizacion de las modificaciones"<<endl<<endl;
			a.agregarArchivoControl(archivoControl, archivoOriginal, version);
			cout <<"La version que escogiste fue " << x<< " e = eliminadas, i = insertadas, y los cambios fueron: "<<endl<<endl;
			a.imprimirArchivos("temporal_Control.txt");
			a.modificar(archivoControl);
			eliminarArchivo("temporal_Control.txt");
			cout << endl; system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}
	}
	else if(decision=="4"){
		limpiar;
		string version1;
		string version2;
		cout<<"Escribe la primera version a DIFERENCIAR ejemplo: '1.1'  "; cin>>version1;
		cout<<endl;
		cout<<"Escribe la segunda version a DIFERENCIAR ejemplo: '1.2'  "; cin>>version2;

		if(v.existeVersion(archivoControl,version2) && version1 == "1.1"){
			limpiar;
			v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
			a.diferencia(archivoOriginal,"v2.txt");
			cout << "Las diferencias entre las versiones: 1.1  y  "<<version2 << "  son: " <<endl<<endl;
			a.formatoDiferencia("diferencias.txt");
			a.imprimirArchivos("dif.txt");
			eliminarArchivo("v2.txt");
			eliminarArchivo("generado.txt");
			eliminarArchivo("diferencias.txt");
			eliminarArchivo("dif.txt");
			cout << endl<<endl; system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}
		else if(v.existeVersion(archivoControl,version1) && version2 == "1.1"){
			limpiar;
			v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
			v.diferencia("v2.txt",archivoOriginal);
			cout << "Las diferencias entre las versiones: "<<version1 << "  y  1.1  son: " <<endl<<endl;
			v.formatoDiferencia("diferencias.txt");
			v.imprimirArchivos("dif.txt");
			eliminarArchivo("v2.txt");
			eliminarArchivo("generado.txt");
			eliminarArchivo("diferencias.txt");
			eliminarArchivo("dif.txt");
			cout << endl<<endl; system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}
		else if(v.existeVersion(archivoControl,version1) && v.existeVersion(archivoControl,version2)){
			limpiar;
			v.regenerarRecursivo2(archivoControl,archivoOriginal,version1,"v1.txt");
			v.regenerarRecursivo2(archivoControl,archivoOriginal,version2,"v2.txt");
			a.diferencia("v1.txt","v2.txt");
			cout << "Las diferencias entre las versiones:  "<<version1<<"  y  "<<version2 << "  son: " <<endl<<endl;
			a.formatoDiferencia("diferencias.txt");
			a.imprimirArchivos("dif.txt");
			eliminarArchivo("v1.txt");
			eliminarArchivo("v2.txt");
			eliminarArchivo("generado.txt");
			eliminarArchivo("diferencias.txt");
			eliminarArchivo("dif.txt");
			menuObtener(archivoControl,archivoOriginal);
			cout << endl<<endl; system("pause");
			limpiar;
		}
		else{
			cout<<endl<<"Alguna de las Versiones no existe, ingrese versiones validas e intente de nuevo"<<endl<<endl;
			system("pause");
			limpiar;
			menuObtener(archivoControl,archivoOriginal);
		}
	}
	else if(decision=="0"){
		limpiar;
		menu();
	}else{
		cout<<endl<<"Opcion invalida, intenta nuevamente"<<endl<<endl;
		system("pause");
		limpiar;
		menuObtener(archivoControl,archivoOriginal);
	}
}


void Controlador::menu(){
	limpiar;
	string nombreproy;
	string version;
		do{
			cout<<endl ;
			cout<<"   ษออออออออออออออออออออออออออออออออออออออออออออป"<<endl;
			cout<<"   บ	         Gestor de Archivos             บ "<<endl ;
			cout<<"   บ Juan Camilo Ariza - William Aguirre Zapata บ "<<endl ;
			cout<<"   ศออออออออออออออออออออออออออออออออออออออออออออผ "<<endl<<endl;
			cout<<" 1 - CREA un nuevo proyecto repositorio a gestionar"<<endl <<endl;
			cout<<" 2 - Acceda a HISTORIAL, VISUALIZAR, MODIFICAR, DIFERENCIA de algun proyecto" <<endl<<endl;
			cout<<" 0 - Salir"<<endl<<endl;
			cout << "Ingrese la opcion que desea realizar "<<endl<<endl;
			string pl;
			pl=obtenerString();
			if( pl == "1"){
				limpiar;
				cout <<"Por favor copie su programa a nuestra carpeta fuente e ingrese el nombre de su archivo";
				cout <<"fuente con su formato para crear su primera version:  'ejemplo.txt'"<<endl;
				nombreproy = obtenerString();
				crearProyecto(nombreproy);
			}
			else if( pl == "2"){			//Gestiona el menu principal
				limpiar;
				cout << "Por favor ingrese el nombre del archivo que desea OBTENER: 'ejemplo.txt' ";
				nombreproy = obtenerString();
				buscarArchivo(nombreproy);
				string archivoOriginal=nombreproy;
				string archivoControl= "s_"+nombreproy;
				menuObtener(archivoControl,archivoOriginal);
			}
			else if( pl == "0"){
				limpiar; cout << endl;
				cout <<"Hasta pronto!"<< endl;
				system("pause");
				exit(1);
			}
			else{
				cout << endl;
				cout << "Opcion invalida, intenta nuevamente"<< endl<<endl;
				system("pause");
				limpiar;
			}
		}while(1);
}
