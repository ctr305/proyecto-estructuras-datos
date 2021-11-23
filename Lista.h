#include <iostream>
#include "NodoLista.h"
using namespace std;

class Lista{
	private:
		Nodo *inicio;
	public:
		void Inicializar(){
			inicio=NULL;
		}
		bool EsVacia(){
			if(inicio == NULL){
				return true;
			}else
				return false;
		}
		void Insertar(int num){
			Nodo *nuevo,*aux;
			nuevo=nuevo->Crear(num);
			if(EsVacia()){
				nuevo->apuntador=NULL;
				inicio=nuevo;
				nuevo=NULL;
			}
			else{
				aux=inicio;
				while(aux->ObtieneApuntador() != NULL){
					aux=aux->ObtieneApuntador();
				}
				nuevo->apuntador=NULL;
				aux->Conectar(nuevo);
				aux=NULL;
				nuevo=NULL;
			}
		}
		void Eliminar(int num){
			Nodo *borrar,*aux;
			if(EsVacia()){
				cout<<"La lista está vacía."<<endl;
			}else{
				borrar=inicio;
				if(borrar->ObtenerDato()==num){
					if(borrar->ObtieneApuntador()==NULL)
						delete inicio;
					else{
						inicio=borrar->ObtieneApuntador();
						delete borrar;
					}
				}else{
					while(borrar != NULL){
						if(borrar->ObtenerDato()!= num){
							aux=borrar;
							borrar=aux->ObtieneApuntador();
						}else{
							if(borrar->ObtieneApuntador()!= NULL){
							aux->Conectar(borrar->ObtieneApuntador());
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
	
		void Buscar(int num) {
			Nodo *aux;
			bool existe =false;
			if(EsVacia()){
				cout<<"La lista esta vacia"<<endl;
			}else{
				aux=inicio;
				while(aux!=NULL && existe==false){
					if(aux->ObtenerDato()==num){
						existe=true;
						cout<<"Posicion de memoria: "<<aux<<endl;
						cout<<"Dato guardado ["<<aux->ObtenerDato()<<"]"<<endl;
						if(aux->ObtieneApuntador()!=NULL)
							cout<<"Apunta a "<<aux->ObtieneApuntador()<<endl<<endl;
						else
							cout<<"Final de la lista "<<endl;
					}else{
						aux=aux->ObtieneApuntador();
					}
				}
				if(existe==false)
					cout<<"Dato no encontrado en la lista"<<endl;
			}
		}
		
		void Recorrer(){
			Nodo *aux;
			if(EsVacia())
				cout<<"Lista vacia"<<endl;
			else{
				aux=inicio;
				while(aux != NULL ){
					cout<<"Posicion de memoria "<<aux<<endl;
					cout<<"Dato guardado "<<aux->ObtenerDato()<<endl;
					if(aux->ObtenerDato() !=NULL){
						cout<<"Apunta a: "<<aux->ObtieneApuntador()<<endl;
						cout<<endl;
					}else{
						cout<<"Final de la lista"<<endl;
						cout<<endl;
					}
					aux=aux->ObtieneApuntador();
				}
			}
		}
};
