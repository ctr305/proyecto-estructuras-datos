#include <iostream>
#include "NodoLista.h"
using namespace std;

class Lista{
	private:
		NodoLista *inicio;
		
	public:
		
		void iniciar(){
			inicio=NULL;
		}
		bool listaVacia(){
			if(inicio == NULL){
				return true;
			}else
				return false;
		}
		
		NodoLista *getInicio(){
			return inicio;
		}
		
		void insertar(int id, string proceso, int memoria, int tiempo, int gestion){
			NodoLista *nuevo,*aux;
			nuevo=nuevo->crear(id,proceso,memoria,tiempo, gestion);
			if(listaVacia()){
				nuevo->apuntador=NULL;
				inicio=nuevo;
				nuevo=NULL;
			}
			else{
				aux=inicio;
				while(aux->obtenerApuntador() != NULL){
					aux=aux->obtenerApuntador();
				}
				nuevo->apuntador=NULL;
				aux->conectar(nuevo);
				aux=NULL;
				nuevo=NULL;
			}
		}
		
		void eliminar(int tiempo){
			NodoLista *borrar; NodoLista *aux;
			if(listaVacia()){
				cout<<"La lista esta vacia."<<endl;
			}else{
				borrar = inicio;
				while(borrar->obtenerApuntador() != NULL && borrar->getTiempo()+borrar->getGestion()!=tiempo){
					aux = borrar;
					borrar = borrar->obtenerApuntador();
				}
				if(aux==NULL){
					inicio = inicio->obtenerApuntador();
					delete borrar;
				}else{
					aux->conectar(borrar->obtenerApuntador());
					delete borrar;
				}
			}
		}
	
		NodoLista *buscar(int tiempo) {
			NodoLista *aux;
			if(listaVacia()){
				cout<<"La lista esta vacia"<<endl;
			}else{
				aux=inicio;
				while(aux->obtenerApuntador()!=NULL && aux->getTiempo()+aux->getGestion()!=tiempo){
					aux = aux->obtenerApuntador();
				}
			}
			return aux;
		}
		
		void recorrer(){
			NodoLista *aux;
			if(listaVacia())
				cout<<"Lista vacia"<<endl;
			else{
				aux=inicio;
				while(aux != NULL ){
					cout<<"Posicion de memoria: "<<aux<<endl;
					cout<<aux->datos()<<endl;
					if(aux->obtenerApuntador()!=NULL){
						cout<<"Apunta a: "<<aux->obtenerApuntador()<<endl;
						cout<<endl;
					}else{
						cout<<"Final de la lista. "<<endl;
						cout<<endl;
					}
					aux=aux->obtenerApuntador();
				}
			}
		}
		
		NodoLista *last(){
			NodoLista *aux;
			if(listaVacia()){
				cout<<"Lista vacia"<<endl;
			}else{
				aux = inicio;
				while(aux->obtenerApuntador()!=NULL){
					aux=aux->obtenerApuntador();
				}
				
				return aux;
			}
		}
		
		int mostrar(NodoLista *aux){
			if(aux==NULL){
				return -1;
			}else{
				cout<<aux->datos()<<endl;
				mostrar(aux->obtenerApuntador());
			}
		}
		
		// REVISAR
		int ram(int suma){
			NodoLista *aux;
			if(listaVacia()){
				
			}else{
				aux = inicio;
				do{
					suma = suma + aux->getMemoria();
					aux = aux->obtenerApuntador();
				}while(aux!=NULL);
			}
			return suma;
		}
		
		bool tiempoIgual(int n){
			NodoLista *aux;
			if(listaVacia()){
				cout<<"La lista esta vacia"<<endl;
			}else{
				aux=inicio;
				while(aux!=NULL && aux->getTiempo()!=n){
					aux = aux->obtenerApuntador();
				}
				
				if(aux==NULL){
					
				}else{
					if(aux->getTiempo()==n){
						return true;
					}else{
						if(aux->getTiempo()!=n){
							return false;
						}
					}
				}
			}
		}
		
		bool ramEx(int memoria, int r){
			/*cout<<"RAM: "<<r<<endl;
			cout<<"Valor de memoria nuevo: "<<memoria<<endl;
			cout<<"Valor de elementos Lista: "<<ram(getInicio(),0)<<endl;*/
			if(memoria+ram(0)<r){
				return true;
			}else{
				return false;
			}
		}
		
		int menor(int minimo){
			NodoLista *aux;
			if(listaVacia()){
				
			}else{
				aux = inicio;
				minimo = aux->getGestion()+aux->getTiempo();
				do{
					if(minimo<aux->getGestion()+aux->getTiempo()){
						minimo = aux->getGestion()+aux->getTiempo();
					}
					aux = aux->obtenerApuntador();
				}while(aux!=NULL);
			}
			return minimo;
		}
};
