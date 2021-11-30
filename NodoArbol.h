#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
class NodoArbol{
	private:
		int id;
		string proceso;
		int memoria;
		int tiempo;
		int gestion;
	public:
		NodoArbol *padre;
		NodoArbol *apuntadorI;
		NodoArbol *apuntadorD;
		
		// Gestión Nodo.
		NodoArbol *crear(int _id, string _proceso, int _memoria, int _tiempo, int _gestion){
			NodoArbol *nuevo = new NodoArbol();
			nuevo->id = _id;
			nuevo->proceso = _proceso;
			nuevo->memoria = _memoria;
			nuevo->tiempo = _tiempo;
			nuevo->gestion = _gestion;
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
		
		int getGestion(){
			return gestion;
		}
		
		string datos(){
			stringstream ssid, ssmemoria, sstiempo;
			ssid<<id;
			ssmemoria<<memoria;
			sstiempo<<tiempo;
			
			string sid = ssid.str();
			string smemoria = ssmemoria.str();
			string stiempo = sstiempo.str();
			
			return "ID: " + sid + "; Nombre: " + proceso + "; Memoria: " + smemoria + "; Tiempo: " + stiempo;
		}
};
