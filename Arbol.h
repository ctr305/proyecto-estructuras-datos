
#include<iostream>
#include "NodoArbol.h"
#include<windows.h>
#include<stdio.h>

class Arbol{

	private:
		
NodoArbol *raiz;	
	
	public:
	
		void Inicializar(){ 
			this->raiz=NULL;
		}
		
		NodoArbol *GetRaiz(){
			return raiz;
		}
		
		void AgregarNodo(string _proceso, int _memoria, int _tiempo) {//crear un nuevo nodo;
			
			NodoArbol *nuevo = new NodoArbol();
			nuevo = nuevo->crear(_proceso, _memoria, _tiempo);
			

			if (raiz == NULL) { //arbol vacío;
				raiz = nuevo;
			}else 
				NextNodo(raiz, nuevo);
		}
		
		void GetArbol(NodoArbol *raiz, int cont){
			if(raiz == NULL){
				return;
			}else{
				GetArbol(raiz->getApuntadorD(), cont + 1);
				for(int i = 0; i <cont; i++){
					cout<<"    ";
				}
				cout<<raiz->getId()<<endl;
				GetArbol(raiz->getApuntadorI(), cont + 1);
			}
		}
		
				int x = 0;
		void MostrarArbol(NodoArbol *aux, int y){//muestra el arbol en forma;
			if(aux == NULL){
				return;
			}else{
				x+=3;
				MostrarArbol(aux->getApuntadorI(), y+2);
				gotoxy(x, y);
				cout<<aux->getId()<<"\n";
				MostrarArbol(aux->getApuntadorD(), y+2);
				cout<<"\n";
			}
		}
		
		void gotoxy(int x,int y){  //funcion para usar coordenadas y hubicar nuestro arbol;
	      HANDLE hcon;  
	      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	      COORD dwPos;  
	      dwPos.X = x;  
	      dwPos.Y= y;  
	      SetConsoleCursorPosition(hcon,dwPos);  
		}
		

		
		void NextNodo(NodoArbol* aux, NodoArbol* nuevo) {//apunta al sig. nodo;
			if (aux == NULL)
				return;
			else {
				if (nuevo->getId() < aux->getId()) {
					if (aux->getApuntadorI() != NULL)
						NextNodo(aux->getApuntadorI(), nuevo);
					else{
						aux->setApuntadorI(nuevo);
						nuevo->setPadre(aux);
					}
						
				}
				else if (nuevo->getId() > aux->getId()) { 
					if (aux->getApuntadorD() != NULL)
						NextNodo(aux->getApuntadorD(), nuevo);
					else{
						aux->setApuntadorD(nuevo);
						nuevo->setPadre(aux);
					}
						
				}
			}
		}




		NodoArbol *BuscarNodo(NodoArbol *aux, int n){
			if(aux==NULL){
				return NULL;
			}
			if(n==aux->getId()){
				return aux;
			}
			if(n<aux->getId()){
				return BuscarNodo(aux->getApuntadorI(),n);
			}else{
				return BuscarNodo(aux->getApuntadorD(),n);
			}	
		}

	    void Orden(NodoArbol *aux){
	    	if(aux==NULL){
				return;
			}else{
				Orden(aux->getApuntadorI());
				cout<<aux->getId()<<endl;
				Orden(aux->getApuntadorD());
			}
		}
		
};