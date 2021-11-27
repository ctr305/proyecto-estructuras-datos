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
string nombres[] = {"Teams","Chrome","PDF","SQL Server",
	"Pencil","Arduino","Spotify","Word","Excel","PowerPoint","Skype",
	"Store","PSeInt","Skype","Acess","Cortana","Calendario","Fotos",
	"Outlook","Netflix"};	
int memoria[] = {1024,2048,5120};

// Funciones.
int tiempoLista(int *tiempo);
int memoriaProceso();
int idProceso();
string nombreProceso();
void loop(int i, int j);

// Objetos.
Lista lista;
Cola cola;
Arbol arbol;


// Tiempo global.
int tiempo=0;
int tiempoL=0;

// Tiempo de cambio.
int tim=0;

// Identificador de cambio.
int identi=0;

// Nombre de cambio.
string name = "";

// Memoria de cambio.
int memo=0;

// Gestión de cambio.
int gest=0;

// Memoria.
int memory=0;

int main(){
	// Crear arreglos.
	cola.iniciar();
	lista.iniciar();
	arbol.inicializar();
	
	loop(0,180);
	
	cout<<"RAM: "<<lista.ram(0)<<endl;
	
	cout<<"LISTA:"<<endl;
	lista.mostrar(lista.getInicio());
	
	cout<<"COLA:"<<endl;
	cola.mostrar(cola.getInicio());
	
	cout<<"\n"; system("pause"); system("cls");
	cout<<"ARBOL:"<<endl;
	arbol.mostrarArbol(arbol.GetRaiz(),60,2,1);
}

int tiempoProceso(int *tiempo){
	srand(time(NULL));
	*tiempo += 2+(rand()%(5-2));
}

int tiempoLista(int *tiempo){
	srand(time(NULL));
	*tiempo = 2+(rand()%(11-2));
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
	int id = 1+(rand()%(100-1));
	return id;
}

void loop(int i, int j){
	if(i==j){
		
	}else{
		system("cls");
		cout<<i<<endl;
	
		if(tiempo==0){
			tiempoProceso(&tiempo);
			cout<<"Tiempo de nueva tarea: "<<tiempo<<endl;
		}else{
			if(tiempo==i){
				tiempoProceso(&tiempo);
				tiempoLista(&tiempoL);
				memory=memoriaProceso();
				
				if(!lista.tiempoIgual(tiempoL)){
					if(lista.ramEx(memory,RAM)){
						lista.insertar(idProceso(),nombreProceso(),memory,tiempoL,i);
					}else{
						cola.push(idProceso(),nombreProceso(),memory,tiempoL,i);
					}
				}else{
					cola.push(idProceso(),nombreProceso(),memory,tiempoL,i);
				}
				
			}
			
			
			if(lista.menor(0)==i){
				identi = lista.buscar(lista.menor(0))->getId();
				name = lista.buscar(lista.menor(0))->getProceso();
				memo = lista.buscar(lista.menor(0))->getMemoria();
				tim = lista.buscar(lista.menor(0))->getTiempo();
				gest = lista.buscar(lista.menor(0))->getGestion();
				arbol.agregar(identi,name,memo,tim, gest);
				lista.eliminar(lista.menor(0));
			}
			
			if(cola.getInicio()!=NULL){
				memory = cola.getInicio()->getMemoria();
				
				if(lista.ramEx(memory,RAM)){
					identi = cola.getInicio()->getId();
					name = cola.getInicio()->getProceso();
					tim = cola.getInicio()->getTiempo();
					lista.insertar(identi,name,memory,tim,i);
				}
			}
		}
		sleep(1);
		loop(i+1,j);
	}
}
