#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#include"Cola.h"
#include"Lista.h"
#include"Arbol.h"
#include <windows.h> 
using namespace std;

int const RAM = 8192;


// Vectores.
string nombres[] = {"Teams","Chrome","PDF","SQL Server",
	"Pencil","Arduino","Spotify","Word","Excel","PowerPoint","Skype",
	"Store","PSeInt","Skype","Acess","Cortana","Calendario","Fotos",
	"Outlook","Netflix"};	
int memoria[] = {1024,2048,5120};

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 	void textcolor(int color) { 
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(h,color); 
	}

// Funciones.
int tiempoLista(int *tiempo);
int memoriaProceso();
int idProceso();
string nombreProceso();
void loop(int i, int j);

// Objetos.
Lista lista;
Cola cola;
Arbol arbol;

// Tiempo global.
int tiempo=0;
int tiempoL=0;

// Tiempo de cambio.
int tim=0;

//Veces limite
int contLimite=0;

// Numero Tareas
int numTareasProcesamiento=0;
int numTareasCola=0;

// Identificador de cambio.
int identi=0;

// Nombre de cambio.
string name = "";

// Memoria de cambio.
int memo=0;

// Gestión de cambio.
int gest=0;

// Memoria.
int memory=0;

//Tiempo-i
int restaTiempo=0;

int main(){
	// Crear arreglos.
	cola.iniciar();
	lista.iniciar();
	arbol.inicializar();
	
	loop(0,180);
	
	system("cls"); cout<<"RAM: "<<lista.ram(0)<<endl;
	
	cout<<"LISTA:"<<endl;
	lista.mostrarInformacion(lista.getInicio());
	
	cout<<"COLA:"<<endl;
	cola.mostrarInformacion(cola.getInicio());
	
	cout<<"CONTADOR TOPE: "<<contLimite<<endl;
	
	cout<<"\n"; system("pause"); system("cls");
	cout<<"ARBOL:"<<endl;
	arbol.mostrarArbol(arbol.GetRaiz(),70,2,1);
}

int tiempoProceso(int *tiempo){
	srand(time(NULL));
	*tiempo += 2+(rand()%(5-2));
}

int tiempoLista(int *tiempo){
	srand(time(NULL));
	*tiempo = 2+(rand()%(11-2));
}

string nombreProceso(){
	srand(time(NULL));
	int limit = sizeof(nombres)/sizeof(nombres[0]);
	return nombres[0+(rand()%(limit-1))];
}

int memoriaProceso(){
	srand(time(NULL));
	int limit = sizeof(memoria)/sizeof(memoria[0]);
	return memoria[0+(rand()%(limit))];
}

int idProceso(){
	srand(time(NULL));
	int id = 1+(rand()%(100-1));
	return id;
}

void loop(int i, int j){
	if(i==j){
		
	}else{

		if(tiempo==0){
			tiempoProceso(&tiempo);
		}else{
			if(tiempo==i){
				tiempoProceso(&tiempo);
				tiempoLista(&tiempoL);
				memory=memoriaProceso();
				
				if(lista.ramEx(memory,RAM)){
					lista.insertar(idProceso(),nombreProceso(),memory,tiempoL,i);
				}else{
					cola.push(idProceso(),nombreProceso(),memory,tiempoL,i);
				}	
			}
			

			if(!lista.listaVacia() && lista.menor()==i){	
				for(int j=0;j<=lista.repeticiones(i);j++){
					if(!lista.listaVacia()){
						identi = lista.buscar(i)->getId();
						name = lista.buscar(i)->getProceso();
						memo = lista.buscar(i)->getMemoria();
						tim = lista.buscar(i)->getTiempo();
						gest = lista.buscar(i)->getGestion();
				
						arbol.agregar(identi,name,memo,tim, gest);
					
						lista.eliminar(i);
					}
				}		
			}
			
			if(cola.getInicio()!=NULL){
				memory = cola.getInicio()->getMemoria();
				tim = cola.getInicio()->getTiempo();
				
				if(lista.ramEx(memory,RAM)){
					identi = cola.getInicio()->getId();
					name = cola.getInicio()->getProceso();
					lista.insertar(identi,name,memory,tim,i);
					cola.pop();
				}
			}
			
		}
		
		restaTiempo=tiempo-i;

		system("cls");
		
		gotoxy(48,1); printf("MEMORIA DE PROCESAMIENTO");cout<<endl;
 	 	gotoxy(1,3);printf("LA SIGUIENTE TAREA SE CREARA EN: "); cout<<ReturnTime(restaTiempo);gotoxy(80,3);printf("TIEMPO TOTAL DE PROCESAMIENTO: ");cout<<ReturnTime(i)<<endl;
 	  	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
 	  	gotoxy(0,5);printf("|");gotoxy(15,5);printf("TAREAS EN ESPERA "); gotoxy(58,5);printf("|");gotoxy(80,5);printf("TAREAS EN PROCESAMIENTO ");cout<<endl;gotoxy(119,5);printf("|");
 	  	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
 	 	 for(int i=7;i<20;i++){
 	  		gotoxy(0,i);printf("|");
   		 }
   	 	for(int i=7;i<20;i++){
 	  		gotoxy(58,i);printf("|");
   		 }
   	 	for(int i=7;i<20;i++){
 	  		gotoxy(119,i);printf("|");
   		 }
   		 
   		// Tareas En Espera
	  	gotoxy(5,8);
	  	numTareasCola=cola.returnTareasCola(cola.getInicio(),0);
	  	switch(numTareasCola){
	  		case 1:
	  			gotoxy(5,8); cola.mostrar(cola.getNodo(cola.getInicio(),0,0));   
	  			gotoxy(5,9); cout<<cola.mostrarTiempo(cola.getNodo(cola.getInicio(),0,0));   
				  
				  
	  			break;
	  		case 2:
	  			gotoxy(5,8); cola.mostrar(cola.getNodo(cola.getInicio(),0,0));   
	  			gotoxy(5,9); cout<<cola.mostrarTiempo(cola.getNodo(cola.getInicio(),0,0));   
	  			
	  				gotoxy(28,8); cola.mostrar(cola.getNodo(cola.getInicio(),1,0));   
	  			gotoxy(28,9); cout<<cola.mostrarTiempo(cola.getNodo(cola.getInicio(),1,0));   
	  			break;
	  	
		  }
	 	 gotoxy(5,9);  printf("");  gotoxy(28,9); printf("");
      	 gotoxy(28,18); printf("");
  			
    	  // Tareas en Procesamiento
    	  numTareasProcesamiento=lista.returnTareas(lista.getInicio(),0);
     	 gotoxy(65,8); 
     	 
     	 	/*for(int i=0;i<numTareasProcesamiento;i++){
     	 		
			  }*/
			  
     	 switch(numTareasProcesamiento){
     	 	case 1:
     	 		gotoxy(65,8);
     	 		 lista.mostrar(lista.getNodo(lista.getInicio(),0,0));
    	  		gotoxy(65,9); 
				 cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),0,0));
    	  		break;
    	  	case 2:
    	  		gotoxy(65,8);
				 lista.mostrar(lista.getNodo(lista.getInicio(),0,0));	
    	  		gotoxy(65,9);
				  cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),0,0)); 	
    	  		gotoxy(94,8); 
				  lista.mostrar(lista.getNodo(lista.getInicio(),1,0));
				gotoxy(94,9);
 					cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),1,0));
    	  		break;
    	  	case 3:
    	  		gotoxy(65,8); lista.mostrar(lista.getNodo(lista.getInicio(),0,0));		
    	  		gotoxy(65,9); cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),0,0)); 	
    	  		
    	  		gotoxy(94,8); lista.mostrar(lista.getNodo(lista.getInicio(),1,0));
    	  		gotoxy(94,9);cout<< lista.mostrarTiempo(lista.getNodo(lista.getInicio(),1,0));
    	  		
    	  		gotoxy(65,11); lista.mostrar(lista.getNodo(lista.getInicio(),2,0));
    	  		gotoxy(65,12); cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),2,0));
    	  		break;
    	  	case 4:
    	  		gotoxy(65,8); lista.mostrar(lista.getNodo(lista.getInicio(),0,0));		
    	  		gotoxy(65,9); cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),0,0)); 	
    	  		
    	  		gotoxy(94,8); lista.mostrar(lista.getNodo(lista.getInicio(),1,0));
    	  		gotoxy(94,9);cout<< lista.mostrarTiempo(lista.getNodo(lista.getInicio(),1,0));
    	  		
    	  		gotoxy(65,11); lista.mostrar(lista.getNodo(lista.getInicio(),2,0));
    	  		gotoxy(65,12); cout<<lista.mostrarTiempo(lista.getNodo(lista.getInicio(),2,0));
    	  		

		  }
     	  
     	gotoxy(94,17);
     	 cout<<endl;cout<<endl;
    	 cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    	
		 if(lista.ram(0)>=7168){
    	 	system("color 0F"); gotoxy(96,20); textcolor(4); printf("ALERTA: MEMORIA EN 90%%");
    	 	contLimite++;
			textcolor(7);
    		cout<<endl; 
		 }
      	
		
		sleep(1);
		loop(i+1,j);
	}
}
