#include<iostream>
#include"NodoCola.h"
#include"Reloj.h"
using namespace std;
class Cola{
	private:
		// Datos de un elemento.
		NodoCola *inicio;
		int tiempoProceso;
		
		// Cola vacía.
		bool colaVacia(){
			if(inicio==NULL){
				return true;
			}else{
				return false;
			}
		}
		
		// Reordenar elementos tras eliminación.
		NodoCola reordenarCola(NodoCola *aux){
			// Caso base.
			if(aux->obtenerApuntador()==NULL){
				
			}else{
				// Caso general.
				aux->conectar(aux->obtenerApuntador());
				reordenarCola(aux);
			}
		}
		
	public:
		// Crear cola.
		void iniciar(){
			inicio = NULL;
		}
		
		// Insertar elemento a cola.
		int push(int id, string proceso, int memoria, int tiempo, int gestion){
			NodoCola *nuevo; NodoCola *aux;
			nuevo = nuevo->crear(id, proceso, memoria, tiempo, gestion);
			
			if(colaVacia()){
				nuevo->apuntador = NULL;
				inicio = nuevo;
				nuevo = NULL;
			}else{
				aux = inicio;
				
				while(aux->obtenerApuntador()!=NULL){
					aux = aux->obtenerApuntador();
				}
				
				nuevo->apuntador = NULL;
				aux->conectar(nuevo);
				aux = NULL;
				nuevo = NULL;
			}
		}
		
		// Eliminar elemento a cola.
		int pop(){
			if(colaVacia()){
				cout<<"Cola vacia.\n";
			}else{
				inicio = inicio->obtenerApuntador();
			}
		}
		
		// Vaciar cola.
		int drop(){
			if(colaVacia()){
				return -1;
			}else{
				pop();
				drop();
				return 0;
			}
		}
		
		int returnTareasCola(NodoCola *aux,int cont){
			if(aux==NULL){
				return cont;
			}else{
				returnTareasCola(aux->obtenerApuntador(), cont+1);
			}
		}
		
		
		NodoCola *getInicio(){
			return inicio;
		}
		
		int mostrarToda(NodoCola *aux){
			if(colaVacia() || aux==NULL){
				return -1;
			}else{
				cout<<"Tarea: "<<aux->getProceso();cout<<"(";cout<<aux->getMemoria();cout<<" MB)"<<endl;
				
				mostrar(aux->obtenerApuntador());
			}
		}
		
		int mostrarInformacion(NodoCola *aux){
			if(aux==NULL){
				
			}else{
				aux->datos(); cout<<endl;
				mostrarInformacion(aux->obtenerApuntador());
			}
		}
		
		NodoCola *getNodo(NodoCola *aux, int num, int cont){
		if(aux!=NULL){
			if(cont==num){
				return aux;
			}else{
				aux=aux->obtenerApuntador();
				return getNodo(aux,num,cont+1);
			}
		}else{
			return NULL;
			}
		}
		
		
		int mostrar(NodoCola *aux){
			if(aux==NULL){
				return -1;
			}else{
				cout<<"Tarea: "<<aux->getProceso();cout<<"(";cout<<aux->getMemoria();cout<<" MB)"<<endl;

			}
		}
	
		string mostrarTiempo(NodoCola *aux){
			if(aux==NULL){
				return "";
			}else{
				tiempoProceso=aux->getTiempo();
				return "Tiempo: "+ReturnTime(tiempoProceso);
			}
		}
};
