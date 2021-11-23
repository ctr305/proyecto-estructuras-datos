#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#include"Cola.h"
#include"Lista.h"
#include"Arbol.h"
using namespace std;

int const RAM = 8192;

// Vectores.
string nombres[] = {"Microsoft Teams","Google Chrome","Acrobat Reader DC","Microsoft SQL Server",
	"Pencil","Enterprise Architect","Explorador de archivos","Word","Excel","PowerPoint","Configuracion",
	"Microsoft Store","PSeInt","Skype","Acess","Calculadora","Calendario","Fotos",
	"Outlook","Netflix"};	
int memoria[] = {1024,2048,5120};

// Funciones.
int tiempoProceso(int *tiempo);
int memoriaProceso();
int idProceso();
string nombreProceso();
void insertarElementoCola(int tiempo);
void insertarElementoLista(int tiempo);

// Objetos.
Lista lista;
Cola cola;
Arbol arbol;

int main(){
	// Crear arreglos.
	cola.iniciar();
	lista.iniciar();
	arbol.inicializar();
	
	int tiempo=0;
	int memo=0;
	
	// Función principal
	for(int i=0;i<10;i++){
		system("cls");
		cout<<i<<endl;
		if(lista.listaVacia() && lista.last()->getTiempo()==0){
			tiempoProceso(&tiempo);
			lista.insertar(idProceso(),nombreProceso(),memoriaProceso(),tiempo);
			cout<<"xTiempo: "<<tiempo<<endl;
			cout<<"Hello!\n";
		}else{
			if(lista.last()->getTiempo()==i){
				tiempoProceso(&tiempo);
				lista.insertar(idProceso(),nombreProceso(),memoriaProceso(),tiempo);
				cout<<"xTiempo: "<<tiempo<<endl;
				cout<<"Adieu!\n";
			}
		}
		
		sleep(3);
	}
	
	lista.recorrer();
}

int tiempoProceso(int *tiempo){
	srand(time(NULL));
	*tiempo += 2+(rand()%(5-2));
}

string nombreProceso(){
	srand(time(NULL));
	int limit = sizeof(nombres)/sizeof(nombres[0]);
	return nombres[1+(rand()%(limit-1))];
}

int memoriaProceso(){
	srand(time(NULL));
	int limit = sizeof(memoria)/sizeof(memoria[0]);
	return memoria[1+(rand()%(limit-1))];
}

int idProceso(){
	srand(time(NULL));
	int id = 2+(rand()%(100-2));
	return id;
}

void insertarElementoCola(int tiempo){
	cola.push(idProceso(),nombreProceso(),memoriaProceso(),tiempoProceso(&tiempo));
}

void insertarElementoLista(int tiempo){
	lista.insertar(idProceso(),nombreProceso(),memoriaProceso(),tiempoProceso(&tiempo));
}
