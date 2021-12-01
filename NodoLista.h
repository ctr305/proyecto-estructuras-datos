#include<iostream>
#include<string.h>
#include<sstream>

using namespace std;
class NodoLista{
	private:
		int id;
		string proceso;
		int memoria;
		int tiempo;
		int gestion;
		
	public:
		NodoLista *apuntador;
		
		// Gestión Nodo.
		NodoLista *crear(int _id, string _proceso, int _memoria, int _tiempo, int _gestion){
			NodoLista *nuevo = new NodoLista();
			nuevo->id = _id;
			nuevo->proceso = _proceso;
			nuevo->memoria = _memoria;
			nuevo->tiempo = _tiempo;
			nuevo->gestion = _gestion;
			return nuevo;
		}
		
		void *conectar(NodoLista *siguiente){
			apuntador = siguiente;
		}
		
		NodoLista *obtenerApuntador(){
			return apuntador;
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
		
		int i(){
			return tiempo+gestion;
		}
		
		string datos(){
			stringstream ssid, ssmemoria, sstiempo, ssgestion;
			ssid<<id;
			ssmemoria<<memoria;
			sstiempo<<tiempo;
			ssgestion<<gestion;
			
			string sid = ssid.str();
			string smemoria = ssmemoria.str();
			string stiempo = sstiempo.str();
			string sgestion = ssgestion.str();
			
			return "ID: " + sid + "; Nombre: " + proceso + "; Memoria: " + smemoria + "; Tiempo: " + stiempo;
		}
};
