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
	
	system("cls"); cout<<"RAM: "<<lista.ram(0)<<endl;
	
	cout<<"LISTA:"<<endl;
	lista.mostrar(lista.getInicio());
	
	cout<<"COLA:"<<endl;
	cola.mostrar(cola.getInicio());
	
	cout<<"\n"; system("pause"); system("cls");
	cout<<"ARBOL:"<<endl;
	arbol.mostrarArbol(arbol.GetRaiz(),70,2,1);
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
	return nombres[0+(rand()%(limit-1))];
}

int memoriaProceso(){
	srand(time(NULL));
	int limit = sizeof(memoria)/sizeof(memoria[0]);
	return memoria[0+(rand()%(limit))];
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
		cout<<i<<endl<<endl;
	
		if(tiempo==0){
			tiempoProceso(&tiempo);
		}else{
			if(tiempo==i){
				tiempoProceso(&tiempo);
				tiempoLista(&tiempoL);
				memory=memoriaProceso();
				
				if(lista.ramEx(memory,RAM)){
					lista.insertar(idProceso(),nombreProceso(),memory,tiempoL,i);
				}else{
					cola.push(idProceso(),nombreProceso(),memory,tiempoL,i);
				}	
			}
			
			
			if(lista.getInicio()!=NULL && lista.menor()==i){	
				for(int j=0;j<=lista.repeticiones(i);j++){
					identi = lista.buscar(i)->getId();
					name = lista.buscar(i)->getProceso();
					memo = lista.buscar(i)->getMemoria();
					tim = lista.buscar(i)->getTiempo();
					gest = lista.buscar(i)->getGestion();
				
					arbol.agregar(identi,name,memo,tim, gest);
					
					lista.eliminar(i);
				}	
			}
			
			if(cola.getInicio()!=NULL){
				memory = cola.getInicio()->getMemoria();
				tim = cola.getInicio()->getTiempo();
				
				if(lista.ramEx(memory,RAM)){
					identi = cola.getInicio()->getId();
					name = cola.getInicio()->getProceso();
					lista.insertar(identi,name,memory,tim,i);
					cola.pop();
				}
			}
		}
		
		cout<<"RAM: "<<lista.ram(0)<<endl;
	
		cout<<"LISTA:"<<endl;
		lista.mostrar(lista.getInicio());
	
		cout<<"COLA:"<<endl;
		cola.mostrar(cola.getInicio());
		
		sleep(1);
		loop(i+1,j);
	}
}
