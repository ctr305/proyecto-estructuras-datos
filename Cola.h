#include<iostream>
#include"NodoCola.h"
using namespace std;
class Cola{
	private:
		// Datos de un elemento.
		NodoCola *inicio;
		
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
		int push(int id, string proceso, int memoria, int tiempo){
			NodoCola *nuevo; NodoCola *aux;
			nuevo = nuevo->crear(id, proceso, memoria, tiempo);
			
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
		
		NodoCola *getInicio(){
			return inicio;
		}
		
		int mostrar(NodoCola *aux){
			if(colaVacia() || aux==NULL){
				return -1;
			}else{
				cout<<aux->datos()<<endl;
				mostrar(aux->obtenerApuntador());
			}
		}
};
