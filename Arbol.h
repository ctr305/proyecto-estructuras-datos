#include<iostream>
#include "NodoArbol.h"
#include<windows.h>
#include<stdio.h>

class Arbol{

	private:
		
		NodoArbol *raiz;	
	
	public:
	
		void inicializar(){ 
			this->raiz=NULL;
		}
		
		NodoArbol *GetRaiz(){
			return raiz;
		}
		
		void agregar(int id, string proceso, int memoria, int tiempo) {//crear un nuevo nodo;
			
			NodoArbol *nuevo = new NodoArbol();
			nuevo = nuevo->crear(id, proceso, memoria, tiempo);
			

			if (raiz == NULL) { //arbol vacÃ­o;
				raiz = nuevo;
			}else 
				nextNodo(raiz, nuevo);
		}
		
		void getArbol(NodoArbol *raiz, int cont){
			if(raiz == NULL){
				return;
			}else{
				getArbol(raiz->getApuntadorD(), cont + 1);
				for(int i = 0; i <cont; i++){
					cout<<"    ";
				}
				cout<<raiz->getId()<<endl;
				getArbol(raiz->getApuntadorI(), cont + 1);
			}
		}
		
		
		void mostrarArbol(NodoArbol *raiz, int x, int y, int izq){
			if(raiz==NULL){
				
			}else{
				gotoxy(x,y);
				cout<<raiz->getId();
				if(izq==1){
					mostrarArbol(raiz->getApuntadorD(),x-20,y+3,izq+1);
					mostrarArbol(raiz->getApuntadorI(),x+20,y+3,izq+1);
				}else if(izq==2){
					mostrarArbol(raiz->getApuntadorD(),x-10,y+3,izq+1);
					mostrarArbol(raiz->getApuntadorI(),x+10,y+3,izq+1);
				}else if(izq==3){
					mostrarArbol(raiz->getApuntadorD(),x-4,y+3,izq+1);
					mostrarArbol(raiz->getApuntadorI(),x+4,y+3,izq+1);
				}else{
					mostrarArbol(raiz->getApuntadorD(),x-2,y+3,izq+1);
					mostrarArbol(raiz->getApuntadorI(),x+2,y+3,izq+1);
				}
			}
			cout<<endl;
		}
		
		void gotoxy(int x,int y){  //funcion para usar coordenadas y hubicar nuestro arbol;
	      HANDLE hcon;  
	      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	      COORD dwPos;  
	      dwPos.X = x;  
	      dwPos.Y= y;  
	      SetConsoleCursorPosition(hcon,dwPos);  
		}
		

		
		void nextNodo(NodoArbol* aux, NodoArbol* nuevo) {//apunta al sig. nodo;
			if (aux == NULL)
				return;
			else {
				if (nuevo->getId() < aux->getId()) {
					if (aux->getApuntadorI() != NULL)
						nextNodo(aux->getApuntadorI(), nuevo);
					else{
						aux->setApuntadorI(nuevo);
						nuevo->setPadre(aux);
					}
						
				}
				else if (nuevo->getId() > aux->getId()) { 
					if (aux->getApuntadorD() != NULL)
						nextNodo(aux->getApuntadorD(), nuevo);
					else{
						aux->setApuntadorD(nuevo);
						nuevo->setPadre(aux);
					}
						
				}
			}
		}




		NodoArbol *buscarNodo(NodoArbol *aux, int n){
			if(aux==NULL){
				return NULL;
			}
			if(n==aux->getId()){
				return aux;
			}
			if(n<aux->getId()){
				return buscarNodo(aux->getApuntadorI(),n);
			}else{
				return buscarNodo(aux->getApuntadorD(),n);
			}	
		}

	    void orden(NodoArbol *aux){
	    	if(aux==NULL){
				return;
			}else{
				orden(aux->getApuntadorI());
				cout<<aux->getId()<<endl;
				orden(aux->getApuntadorD());
			}
		}
		
};
