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
		
		void insertar(int id, string proceso, int memoria, int tiempo){
			NodoLista *nuevo,*aux;
			nuevo=nuevo->crear(id,proceso,memoria,tiempo);
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
		void eliminar(int n){
			NodoLista *borrar,*aux;
			if(listaVacia()){
				cout<<"La lista está vacía."<<endl;
			}else{
				borrar=inicio;
				if(borrar->getId()==n){
					if(borrar->obtenerApuntador()==NULL)
						delete inicio;
					else{
						inicio=borrar->obtenerApuntador();
						delete borrar;
					}
				}else{
					while(borrar != NULL){
						if(borrar->getId()!= n){
							aux=borrar;
							borrar=aux->obtenerApuntador();
						}else{
							if(borrar->obtenerApuntador()!= NULL){
							aux->conectar(borrar->obtenerApuntador());
							delete borrar;
							borrar=NULL;
								}else{
									delete borrar;
									borrar=NULL;
								}
							}
					}
				
				}
			}
		}
	
		void buscar(int n) {
			NodoLista *aux;
			bool existe =false;
			if(listaVacia()){
				cout<<"La lista esta vacia"<<endl;
			}else{
				aux=inicio;
				while(aux!=NULL && existe==false){
					if(aux->getId()==n){
						existe=true;
						cout<<"Posicion de memoria: "<<aux<<endl;
						cout<<"Dato guardado ["<<aux->getId()<<"]"<<endl;
						if(aux->obtenerApuntador()!=NULL)
							cout<<"Apunta a "<<aux->obtenerApuntador()<<endl<<endl;
						else
							cout<<"Final de la lista "<<endl;
					}else{
						aux=aux->obtenerApuntador();
					}
				}
				if(existe==false)
					cout<<"Dato no encontrado en la lista"<<endl;
			}
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
			if(listaVacia() || aux==NULL){
				return -1;
			}else{
				cout<<aux->datos()<<endl;
				mostrar(aux->obtenerApuntador());
			}
		}
};
