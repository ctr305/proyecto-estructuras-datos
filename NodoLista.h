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
		
	public:
		NodoLista *apuntador;
		
		// Gestión Nodo.
		NodoLista *crear(int _id, string _proceso, int _memoria, int _tiempo){
			NodoLista *nuevo = new NodoLista();
			nuevo->id = _id;
			nuevo->proceso = _proceso;
			nuevo->memoria = _memoria;
			nuevo->tiempo = _tiempo;
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
