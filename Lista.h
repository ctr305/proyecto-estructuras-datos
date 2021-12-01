#include <iostream>
#include "NodoLista.h"
using namespace std;

class Lista{
	private:
		NodoLista *inicio;
		int tiempoProceso;
		
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
			NodoLista *borrar; NodoLista *aux=NULL;
			if(listaVacia()){
				cout<<"La lista esta vacia. Eliminar"<<endl;
			}else{
				borrar = inicio;
				while((borrar->obtenerApuntador() != NULL) && (borrar->i()!=tiempo)){
					aux = borrar;
					borrar = borrar->obtenerApuntador();
				}
				if(borrar==NULL){
					
				}else{
					if(aux==NULL){
						inicio = inicio->obtenerApuntador();
						delete borrar;
					}else{
						aux->conectar(borrar->obtenerApuntador());
						delete borrar;
					}
				}
			}
		}
	
		NodoLista *buscar(int tiempo) {
			NodoLista *aux;
			if(listaVacia()){
				cout<<"La lista esta vacia Buscar"<<endl;
			}else{
				aux=inicio;
				while(aux->obtenerApuntador()!=NULL && aux->i()!=tiempo){
					aux = aux->obtenerApuntador();
				}
			}
			return aux;
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
		
		int mostrarToda(NodoLista *aux){
			if(aux==NULL){
				return -1;
			}else{
				cout<<"Tarea: "<<aux->getProceso();cout<<"(";cout<<aux->getMemoria();cout<<" MB)"<<endl;
				mostrar(aux->obtenerApuntador());
			}
		}
		
		int mostrarInformacion(NodoLista *aux){
			if(aux==NULL){
				return -1;
			}else{
				cout<<aux->datos();cout<<endl;
				mostrarInformacion(aux->obtenerApuntador());
			}
		}
		
		int mostrar(NodoLista *aux){
			if(aux==NULL){
				return -1;
			}else{
				cout<<"Tarea: "<<aux->getProceso();cout<<"(";cout<<aux->getMemoria();cout<<" MB)"<<endl;
			}
		}
		
		string mostrarTiempo(NodoLista *aux){
			if(aux==NULL){
				return "";
			}else{
				tiempoProceso=aux->getTiempo();
				return "Tiempo: "+ReturnTime(tiempoProceso);
			}
		}
		
		NodoLista *getNodo(NodoLista *aux, int num, int cont){
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
		
		int returnTareas(NodoLista *aux,int cont){
			if(aux==NULL){
				return cont;
			}else{
				returnTareas(aux->obtenerApuntador(), cont+1);
			}
		}
		
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
			if(memoria+ram(0)<=r){
				return true;
			}else{
				return false;
			}
		}
		
		int menor(){
			int minimo;
			NodoLista *aux;
			if(listaVacia()){
				
			}else{
				aux = inicio;
				minimo = aux->i();
				while(aux!=NULL){
					if(aux->i()<minimo){
						minimo = aux->i();
					}
					aux = aux->obtenerApuntador();
				}
			}
			return minimo;
		}
		
		int num(int menor){
			int cont=0;
			NodoLista *aux;
			cout<<"hola";
			if(listaVacia()){
				
			}else{
				aux = inicio;
				while(aux!=NULL && aux->i()!=menor){
					cont++;
					cout<<cont;
					aux = aux->obtenerApuntador();
				}
			}
			return cont;
		}
		
		
		int repeticiones(int minimo){
			int c;
			NodoLista *aux;
			if(listaVacia()){
				
			}else{
				aux = inicio;
				c=0;
				while(aux!=NULL){
					if(aux->i()==minimo){
						c++;
					}
					aux = aux->obtenerApuntador();
				}
				return c;
			}
		}
};
