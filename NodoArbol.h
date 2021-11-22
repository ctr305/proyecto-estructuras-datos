#include<iostream>
#include<string.h>
using namespace std;
class NodoArbol{
	private:
		// Datos Nodo
		int id;
		string proceso;
		int memoria;
		int tiempo;
		
	public:
		NodoArbol *padre;
		NodoArbol *apuntadorI;
		NodoArbol *apuntadorD;
		
		// Gestión Nodo.
		NodoArbol *crear(string _proceso, int _memoria, int _tiempo){
			NodoArbol *nuevo = new NodoArbol();
			nuevo->proceso = _proceso;
			nuevo->memoria = _memoria;
			nuevo->tiempo = _tiempo;
			return nuevo;
		}
		
		NodoArbol *getPadre(){
			return padre;
		}
		
		NodoArbol *getApuntadorI(){
			return apuntadorI;
		}
		
		NodoArbol *getApuntadorD(){
			return apuntadorD;
		}
		
		void setApuntadorI(NodoArbol *nuevo){
			apuntadorI = nuevo;
		}
		
		void setApuntadorD(NodoArbol *nuevo){
			apuntadorD = nuevo;
		}
		
		void setPadre(NodoArbol *nuevo){
			padre = nuevo;
		}
		
		// Setters.
		void setProceso(string _proceso){
			proceso = _proceso;
		}
		
		void setMemoria(int _memoria){
			memoria = _memoria;
		}
		
		void setTiempo(int _tiempo){
			tiempo = _tiempo;
		}
		
		// Getters.
		int getId(){
			return id;
		}
		
		string getProceso(){
			return proceso;
		}
		
		int getMemoria(){
			return memoria;
		}
		
		int getTiempo(){
			return tiempo;
		}
};
