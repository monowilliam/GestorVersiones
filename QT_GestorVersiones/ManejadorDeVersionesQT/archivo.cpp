/*
 * Archivo.cpp
 *
 *  Created on: 3/06/2018
 *      Author: William Aguirre & Juan Camilo Ariza
 */

#include "Archivo.h"

Archivo::Archivo() {}        //Constructor

Archivo::~Archivo() {}        //Destructor


bool Archivo::elArchivoExiste(string nom){
	FILE * archivo;
	if((archivo = fopen(nom.c_str(), "r"))){        //Verifica si un archivo existe
		fclose(archivo);
		return true;
	}else
		return false;
}


vector<string> Archivo::split_iterator(const string& str){

	vector<string> resultado;
	string::const_iterator itBegin = str.begin();
	string::const_iterator itEnd   = str.end();
		int numItems = 1;
		for( string::const_iterator it = itBegin; it!=itEnd; ++it )
			numItems += *it==' ';
	  resultado.reserve(numItems);
	  for( string::const_iterator it = itBegin; it!=itEnd; ++it )        //Divide un texto en varias palabras
	  {
	    if( *it == ' ' )
	    {
	      resultado.push_back(string(itBegin,it));
	      itBegin = it+1;
	    }
	  }
	  if( itBegin != itEnd )
	    resultado.push_back(string(itBegin,itEnd));
	  return resultado;
}



void Archivo::diferencia(string archivov1, string archivov2){

	vector<string> vectordiferencia;
	string b;
	string linea;
	string linea2;
	string linea3;
	ifstream archivo;
	ifstream archivo2;
	ofstream archivo3;
	archivo.open(archivov2.c_str());
	archivo2.open(archivov1.c_str());
	archivo3.open("diferencias.txt");
	while(!archivo.eof()){
		getline(archivo,linea);
		textoEditado.push_back(linea);
	}
	while(!archivo2.eof()){
		getline(archivo2,linea2);
		textoOriginal1.push_back(linea2);
	}

	vector <string> Union = textoEditado;
	vector <int> flag;
	for(int i=0; i<textoOriginal1.size();i++){        //Realiza la Union entre 2 textos
		flag.push_back(0);
	}
	for(int i=0; i<Union.size();i++){
		for(int j=0; j<textoOriginal1.size();j++){
			if(Union[i]==textoOriginal1[j] && flag[j]==0){
				flag[j]=1;
			}
		}
	}
	for(int i=0; i<flag.size();i++){
		if (flag[i]==0){
			Union.push_back(textoOriginal1[i]);
		}
	}
	vector<string> Interseccion;
	for(int i=0; i<flag.size();i++){
		if (flag[i]==1){
			Interseccion.push_back(textoOriginal1[i]);        //Realiza la interseccion de 2 textos
		}
	}
	vector<int> flag2;
	for(int i=0; i<textoOriginal1.size();i++){
		flag2.push_back(0);
	}
	vector<string> Diferencia;
	for(int i=0; i<textoOriginal1.size();i++){
		for(int j=0; j<Interseccion.size();j++){
			if(Interseccion[j]==textoOriginal1[i] && flag2[i]==0){        //Realiza la Diferencia entre 2 textos
				flag2[i]=1;
			}
		}
	}
	//encuentra las eliminadas e insertadas en los dos archivos
	bool encontro=false;
	int pos=0;
	for(int i=0; i<textoOriginal1.size()  && !encontro; i++){
		for(int j=0; j<textoEditado.size() && !encontro; j++){
			if(textoOriginal1[i]==textoEditado[j]){    
				encontro=true;
				pos=i+1;
				archivo3 << "e "<<pos<<" |"<< textoOriginal1.at(i)<<endl;
			}
		}														//Busca el token e y lo ingresa en el texto
	}
	vector <string> Union2 = textoOriginal1;
	for(int i=0; i<flag2.size();i++){
		if (flag2[i]==0){
			Diferencia.push_back(textoOriginal1[i]);
			archivo3<<"e "<<i+1 <<" |"<< textoOriginal1[i]<<endl;
		}
	}
	encontro=false;
	pos=0;
	for(int i=0; i<textoOriginal1.size()  && !encontro; i++){
		for(int j=0; j<textoEditado.size() && !encontro; j++){				//Busca el token i y lo ingresa en el texto
			if(textoOriginal1[i]==textoEditado[j]){
				encontro=true;
				pos=i+1;
				//cout << "e "<<pos<<" |"<< textoOriginal1.at(i)<<endl;
				archivo3 << "i "<<j+1<<" |"<< textoEditado.at(j)<<endl;
			}
		}
	}
	vector <int> flag4;
	for(int i=0; i<textoEditado.size();i++){
		flag4.push_back(0);
	}
	for(int i=0; i<Union2.size();i++){
		for(int j=0; j<textoEditado.size();j++){
			if(Union2[i]==textoEditado[j] && flag4[j]==0){				//Realiza la Union entre 2 textos
				flag4[j]=1;
			}
		}
	}
	for(int i=0; i<flag4.size();i++){
		if (flag4[i]==0){
			Union2.push_back(textoEditado[i]);
		}
	}
	vector<string> Interseccion2;
	for(int i=0; i<flag4.size();i++){					//Realiza la interseccion entre 2 textos		
		if (flag4[i]==1){
			Interseccion2.push_back(textoEditado[i]);
		}
	}
	vector<int> flag3;
	for(int i=0; i<textoEditado.size();i++){
		flag3.push_back(0);
	}
	vector<string> Diferencia2;
	for(int i=0; i<textoEditado.size();i++){
		for(int j=0; j<Interseccion2.size();j++){
			if(Interseccion2[j]==textoEditado[i] && flag3[i]==0){				//Realiza la Diferencia entre 2 textos
				flag3[i]=1;
			}
		}
	}
	//stringstream ins;
	for(int i=0; i<flag3.size();i++){
		if (flag4[i]==0){
			Diferencia2.push_back(textoEditado[i]);								//Busca el token i y lo ingresa en el texto	
			archivo3<<"i "<<i+1 << " |"<<textoEditado[i]<<endl;
			//inse.push_back(ins.str());
		}
	}
	archivo.close();
	archivo2.close();
	archivo3.close();
	while(!textoEditado.empty()){
		textoEditado.pop_back();
	}
	while(!textoOriginal1.empty()){
		textoOriginal1.pop_back();
	}
}


void Archivo::clonarVersion(string archivoControl,string clon){
    ifstream archivoAleer;
    ofstream archivoAescribir;
    char chs;
    archivoAleer.open (archivoControl.c_str());
    archivoAescribir.open(clon);
    while (!archivoAleer.eof()) {
        archivoAleer.get(chs);					//Clona una version para despues ser modificada
        if (!archivoAleer.eof()) {
            archivoAescribir<<chs;
        }
    }
    archivoAescribir.close();
    archivoAleer.close();
}



void Archivo::agregarArchivoControl(string archivoControl, string archivoOriginal,string version){
	clonarVersion(archivoOriginal,"editarAQUI.txt");
	vector<string> vectordiferencia;
	string b;
	string linea;
	string linea2;
	string linea3;
	ifstream archivo;
	ifstream archivo2;
	ofstream archivo3;
	archivo.open("editarAQUI.txt");					//Se adhiere al archivo de control las modificaciones de una version
	archivo2.open(archivoOriginal.c_str());
	system("pause");
	archivo3.open("temporal_Control.txt");
	while(!archivo.eof()){
		getline(archivo,linea);
		textoEditado.push_back(linea);
	}
	while(!archivo2.eof()){
		getline(archivo2,linea2);
		textoOriginal1.push_back(linea2);
	}
	archivo3<< "Version " << version << endl;		//Ingresa el titulo de la version

	vector <string> Union = textoEditado;
	vector <int> flag;
	for(int i=0; i<textoOriginal1.size();i++){
		flag.push_back(0);
	}
	for(int i=0; i<Union.size();i++){
		for(int j=0; j<textoOriginal1.size();j++){
			if(Union[i]==textoOriginal1[j] && flag[j]==0){
				flag[j]=1;
			}
		}
	}
	for(int i=0; i<flag.size();i++){
		if (flag[i]==0){
			Union.push_back(textoOriginal1[i]);
		}
	}
	vector<string> Interseccion;
	for(int i=0; i<flag.size();i++){
		if (flag[i]==1){
			Interseccion.push_back(textoOriginal1[i]);
		}
	}
	vector<int> flag2;
	for(int i=0; i<textoOriginal1.size();i++){
		flag2.push_back(0);
	}
	vector<string> Diferencia;
	for(int i=0; i<textoOriginal1.size();i++){
		for(int j=0; j<Interseccion.size();j++){
			if(Interseccion[j]==textoOriginal1[i] && flag2[i]==0){
				flag2[i]=1;
			}
		}
	}
	//encuentra las eliminadas e insertadas en los dos archivos
	bool encontro=false;
	int pos=0;
	for(int i=0; i<textoOriginal1.size()  && !encontro; i++){
		for(int j=0; j<textoEditado.size() && !encontro; j++){
			if(textoOriginal1[i]==textoEditado[j]){
				encontro=true;
				pos=i+1;
				archivo3 << "e "<<pos<<" |"<< textoOriginal1.at(i)<<endl;
				//cout << "i "<<j+1<<" |"<< textoEditado.at(j)<<endl;
			}
		}
	}
	vector <string> Union2 = textoOriginal1;
	for(int i=0; i<flag2.size();i++){
		if (flag2[i]==0){
			Diferencia.push_back(textoOriginal1[i]);
			archivo3<<"e "<<i+1 <<" |"<< textoOriginal1[i]<<endl;
		}
	}
	encontro=false;
	pos=0;
	for(int i=0; i<textoOriginal1.size()  && !encontro; i++){
		for(int j=0; j<textoEditado.size() && !encontro; j++){
			if(textoOriginal1[i]==textoEditado[j]){
				encontro=true;
				pos=i+1;
				archivo3 << "i "<<j+1<<" |"<< textoEditado.at(j)<<endl;
			}
		}
	}
	vector <int> flag4;
	for(int i=0; i<textoEditado.size();i++){
		flag4.push_back(0);
	}
	for(int i=0; i<Union2.size();i++){
		for(int j=0; j<textoEditado.size();j++){
			if(Union2[i]==textoEditado[j] && flag4[j]==0){
				flag4[j]=1;
			}
		}
	}
	for(int i=0; i<flag4.size();i++){
		if (flag4[i]==0){
			Union2.push_back(textoEditado[i]);
		}
	}
	vector<string> Interseccion2;
	for(int i=0; i<flag4.size();i++){
		if (flag4[i]==1){
			Interseccion2.push_back(textoEditado[i]);
		}
	}
	vector<int> flag3;
	for(int i=0; i<textoEditado.size();i++){
		flag3.push_back(0);
	}
	vector<string> Diferencia2;
	for(int i=0; i<textoEditado.size();i++){
		for(int j=0; j<Interseccion2.size();j++){
			if(Interseccion2[j]==textoEditado[i] && flag3[i]==0){
				flag3[i]=1;
			}
		}
	}
	for(int i=0; i<flag3.size();i++){
		if (flag4[i]==0){
			Diferencia2.push_back(textoEditado[i]);
			archivo3<<"i "<<i+1 << " |"<<textoEditado[i]<<endl;
		}
	}

	archivo.close();
	archivo2.close();
	archivo3.close();
	while(!textoEditado.empty()){
		textoEditado.pop_back();
	}
	while(!textoOriginal1.empty()){
		textoOriginal1.pop_back();
	}
	const char *nom1 = "editarAQUI.txt";
		remove(nom1);
}






void Archivo::imprimirArchivos(string archivo){
	ifstream a;
	char chs;
	a.open(archivo);
	while(!a.eof()){
		a.get(chs);					//Imprime el archivo
		if(!a.eof())
			cout << chs;
	}
	a.close();
}







void Archivo::modificar(string archivoControl){
    ifstream archivoAleer;
    fstream archivoAescribir;
    char chs;
    archivoAleer.open ("temporal_Control.txt");
    archivoAescribir.open(archivoControl.c_str(),ios::app);
    while (!archivoAleer.eof()) {
        archivoAleer.get(chs);						//Modifica el archivo de control
        if (!archivoAleer.eof()) {
            archivoAescribir<<chs;
        }
    }
    archivoAescribir.close();
    archivoAleer.close();
}




string Archivo::obtenerDelta(string version, string archivoControl){
	vector<vector<string>> todasVersiones = devuelveVersiones(archivoControl);
	string final;
	string str= version;
	string finalaux;
	int n = str.length();
    char char_array[n+1];
    strcpy(char_array, str.c_str());
	vector<char> aux;
	for (int i=0; i<n; i++){
    	aux.push_back(char_array[i]);
	}
	int num;
	vector<string> versionDiv;
	for(int i=0; i<aux.size();i++){
		string s(1, aux[i]);
		versionDiv.push_back(s);
	}
	if(todasVersiones.empty() && version=="1.1"){			//Si no hay versiones modificaciones y la version ingresada es 1.1 
		return "1.2";
	}

	if("ultima"==version){
		if(todasVersiones.empty()){						//Si la version ingresada es ultima
			return "1.2";
		}
		versionDiv=todasVersiones.back();
		num= atoi(versionDiv.back().c_str());
		num++;
		finalaux =to_string(num);
		versionDiv.back()=finalaux;						//Se toma el ultimo + 1
		for(int i=0;i<versionDiv.size();i++){
			final=final+versionDiv[i];
		}
		return final;
	}
	if(versionDiv.size()==1 && todasVersiones.empty()){
		if(atoi(versionDiv[0].c_str()) != 2){				//Si se ingresa un numero mayor que 2 y no existen modificaciones error
			final= "?";
			return final;
		}
		return "2.1";
	}
	if(todasVersiones.empty()){				//Si no existen versiones error
		return "?";
	}

	if(versionDiv.size()==3 && atoi(versionDiv[0].c_str()) == atoi(todasVersiones[todasVersiones.size()-1][0].c_str())+1 ){
		final= "?";
		return final;					//Si se ingresa una version en la que la siguiente version no sea mayor a esa + 1
	}
	if(versionDiv.size()%2==0){
		final= "?";				//Si se ingresa una version con cardinalidad par error
		return final;
	}
	if(versionDiv.size()==1 && (versionDiv[0] > todasVersiones[todasVersiones.size()-1][0])){
		if(atoi(versionDiv[0].c_str()) != atoi(todasVersiones[todasVersiones.size()-1][0].c_str())+1){
			final= "?";
			return final;			//Si se ingresa una version con cardinalidad 1 y esta es mayor a la version anterior error 
		}
	}
	if(versionDiv.size()==3 && (versionDiv[2] > todasVersiones[todasVersiones.size()-1][2])){
		if(atoi(versionDiv[2].c_str()) != atoi(todasVersiones[todasVersiones.size()-1][2].c_str())+1){
			final= "?";
			return final;				//Si se ingresa una version con cardinalidad 3 y esta no existe porque su segundo parametro es mayor al ya existente +2
		}
	}
	for(int i=0; i<versionDiv.size();i++){
		if(i%2==0){
			if(atoi(versionDiv[i].c_str())==0){		//Si se ingresa una version con algun parametro letra error
				final= "?";
				return final;
			}
		}
		if(i%2==1){
			if(versionDiv[i]!="."){			//Si se ingresa una version que no contiene puntos error
				final= "?";
				return final;
			}
		}

	}
	if(versionDiv.size()>7){
		final= "?";			//Si se ingresa una version con cardinalidad> 7 error
		return final;
	}
	if(versionDiv.size()==1 && (versionDiv[0] > todasVersiones[todasVersiones.size()-1][0])){
		if(atoi(versionDiv[0].c_str()) == atoi(todasVersiones[todasVersiones.size()-1][0].c_str())+1){
			final = versionDiv[0]+".1";
			return final;		//Retorna la siguiente version en 1
		}
	}
	if(versionDiv.size()==3 && (versionDiv[2] == todasVersiones[todasVersiones.size()-1][2])){
			num = atoi(todasVersiones[todasVersiones.size()-1][2].c_str())+1;
			finalaux =to_string(num);
			final = versionDiv[0]+"."+finalaux;			//Se crea la siguiente version + 1 
			return final;
	}
	if(versionDiv.size()==3 && (versionDiv[2] < todasVersiones[todasVersiones.size()-1][2])){
		for(int i=0;i<versionDiv.size();i++){
			final=final+versionDiv[i];
		}
		final=final+".1.1";			//Se crea el primer delta
		return final;
	}
	if(versionDiv.size()==7){
		finalaux=versionDiv[6];
		num=atoi(finalaux.c_str());
		num=num+1;
		finalaux =to_string(num);
		versionDiv[6] = finalaux;
		for(int i=0; i<todasVersiones.size();i++){
			if(versionDiv==todasVersiones[i]){
				final="?";					//Si ya existe esa version error
				return final;
			}
		}
		for(int i=0;i<versionDiv.size();i++){
			final=final+versionDiv[i];		//Si no existe crearla
		}
		return final;

	}
	if(versionDiv.size()==5){
		for(int i=0; i<todasVersiones.size();i++){
			if(todasVersiones[i].size()==7){
				if((versionDiv[4]==todasVersiones[i][4]) && (versionDiv[2]==todasVersiones[i][2]) && (versionDiv[0]==todasVersiones[i][0])){
					final="?";
					return final;			//Si se ingresa una version con cardinalidad 5 y esta supera el actualmente existente
				}
			}
		}
		finalaux=versionDiv[4];
		num=atoi(finalaux.c_str());
		num=num-1;
		finalaux =to_string(num);
		int flag =0;
		for(int i=0; i<todasVersiones.size();i++){			//Crearla en caso contrario la .1
			if(todasVersiones[i].size()==7){
				if(finalaux==todasVersiones[i][4]){
					flag=1;
				}
			}
		}
		if(flag==1){
			for(int i=0;i<versionDiv.size();i++){
				final=final+versionDiv[i];
			}
			final=final+".1";
			return final;
		}
		if(flag==0){
			final="?";
			return final;
		}
	}
	for(int i=0; i<todasVersiones.size();i++){
		if(todasVersiones[i].size()==3){
			if((versionDiv[2]==todasVersiones[i][2]) && (versionDiv[0]==todasVersiones[i][0])){
				final="?";
				return final;			//Si la version ya existe error
			}
		}
	}
	return "?"; //Retornar error en cualquier otro caso
}




vector<vector<string>> Archivo::devuelveVersiones(string archivoControl){
	vector<string> versiones;
	ifstream archivo;
	string linea;
	int contador=0;
	int flag=0;
	string decision;
	archivo.open(archivoControl.c_str());
	if (archivo.fail () == true ) { // Verificacion
		cout << "Error abriendo el diccionario (puede que el archivo no existe, inicie de nuevo)" << endl;
		exit (1);
	}
	while(!archivo.eof()){
		getline(archivo,linea);
		contador++;
			for(int i=0;i<split_iterator(linea).size();i++){
    			if(split_iterator(linea)[i]=="Version"){			//Vector contenedor de las versiones SOLO EL NOMBRE DE ESTAS
    				versiones.push_back(split_iterator(linea)[i+1]);
				}
			}
	}
	sort(versiones.begin(),versiones.end());
	vector<char> aux;
	vector<string> versionDiv;
	vector<vector<string>> todasVersiones;
	for(int i=0;i<versiones.size();i++){
		string str= versiones[i];
		int n = str.length();
	    char char_array[n+1];
	    strcpy(char_array, str.c_str());
	    for (int i=0; i<n; i++){
	    	aux.push_back(char_array[i]);
		}
		for(int i=0; i<aux.size();i++){
			string s(1, aux[i]);
			versionDiv.push_back(s);
		}
		todasVersiones.push_back(versionDiv);
		while(!versionDiv.empty()){
			versionDiv.pop_back();
		}
		while(!aux.empty()){
			aux.pop_back();
		}
	}
	archivo.close();
	return todasVersiones;
}



void Archivo::formatoDiferencia(string cambios){
	vector<int> indiceEliminados;
	vector<int> indiceInsertados;
	vector<string> textoEliminados;
	vector<string> textoInsertados;
	ofstream dife;
	char separador = '|';
	int w1;
	ifstream archivo;
	string linea;
	int contador=0;
	dife.open("dif.txt");
	archivo.open(cambios.c_str());
	if (archivo.fail () == true ) { // Verificacion
		dife << ("Error abriendo el archivo de texto") << endl;
		exit (1);
	}
	while(!archivo.eof()){
		getline(archivo,linea);
		contador++;
		int n = sizeof(linea);
		if(linea[0]=='e'){
			for(w1=0; w1<n; w1++){
				if(linea[w1]==separador){			//Imprime de una manera especifica las diferencias
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
	sort(indiceInsertados.begin(),indiceInsertados.end());
	sort(indiceEliminados.begin(),indiceEliminados.end());

	vector<vector<int> > consecutivosI;
	vector <int> temp;
	int flag=0;
	for(int i=0;i<indiceInsertados.size()-1;i++){
		if(indiceInsertados[i]+1==indiceInsertados[i+1]){
			flag=1;
			if(temp.empty()){
				temp.push_back(indiceInsertados[i]);
			}
			temp.push_back(indiceInsertados[i+1]);
			if(i+1==indiceInsertados.size()-1){
				consecutivosI.push_back(temp);
			}
		}
		else{
			flag=0;
			if(!temp.empty()){
				consecutivosI.push_back(temp);
			}
			while(!temp.empty()){
				temp.pop_back();
			}
		}
	}
	vector<vector<int> > consecutivosE;
	vector <int> temp2;
	int flag2=0;
	for(int i=0;i<indiceEliminados.size()-1;i++){
		if(indiceEliminados[i]+1==indiceEliminados[i+1]){
			flag2=1;
			if(temp2.empty()){
				temp2.push_back(indiceEliminados[i]);
			}
			temp2.push_back(indiceEliminados[i+1]);
			if(i+1==indiceEliminados.size()-1){
				consecutivosE.push_back(temp2);
			}
		}
		else{
			flag2=0;
			if(!temp2.empty()){
				consecutivosE.push_back(temp2);
			}
			while(!temp2.empty()){
				temp2.pop_back();
			}
		}
	}
	for(int i=0;i<consecutivosE.size();i++){
		dife<<consecutivosE[i].front()<<"-"<<consecutivosE[i].back()<<"e"<<consecutivosE[i].front()<<endl;
		for(int j=0;j<consecutivosE[i].size();j++){
			for(int m=0;m<indiceEliminados.size();m++){
				if(consecutivosE[i][j]==indiceEliminados[m]){
					dife<<"<"<<textoEliminados[m]<<endl;
				}
			}
		}
	}
	for(int i=0;i<consecutivosI.size();i++){
		dife<<consecutivosI[i].back()<<"i"<<consecutivosI[i].front()<<"-"<<consecutivosI[i].back()<<endl;
		for(int j=0;j<consecutivosI[i].size();j++){
			for(int m=0;m<indiceInsertados.size();m++){
				if(consecutivosI[i][j]==indiceInsertados[m]){
					dife<<">"<<textoInsertados[m]<<endl;
				}
			}
		}
	}
	archivo.close();
	dife.close();
}

