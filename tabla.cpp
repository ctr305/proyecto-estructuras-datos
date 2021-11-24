#include <stdio.h>  
 #include <windows.h> 
 #include <iostream>
 #include <stdio.h>
 using namespace std;
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
 int main(){  
 	  gotoxy(48,1); printf("MEMORIA DE PROCESAMIENTO");cout<<endl;
 	  gotoxy(1,3);printf("LA SIGUIENTE VARIABLE SE CREARA EN: 04:20"); gotoxy(80,3);printf("TIEMPO TOTAL DE PROCESAMIENTO: 04:20");cout<<endl;
 	  cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
 	  gotoxy(0,5);printf("|");gotoxy(15,5);printf("TAREAS EN ESPERA "); gotoxy(58,5);printf("|");gotoxy(80,5);printf("TAREAS FINALIZADAS ");cout<<endl;gotoxy(119,5);printf("|");
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
   		// Tareas En Procesamiento
	  gotoxy(5,8);  printf("Tarea: Words(1024Mb)");  gotoxy(28,8); printf("Tarea: Word(1024Mb)");
	  gotoxy(5,9);  printf("Tiempo: 3:00");  gotoxy(28,9); printf("Tiempo: 3:00");
      gotoxy(5,11); printf("Tarea: Word(1024Mb)");  gotoxy(28,11); printf("Tarea: Word(1024Mb)");   
      gotoxy(5,12);  printf("Tiempo: 3:00");  gotoxy(28,12); printf("Tiempo: 3:00");
      gotoxy(5,14); printf("Tarea: Word(1024Mb)"); gotoxy(28,14); printf("Tarea: Word(1024Mb)"); 
	  gotoxy(5,15);  printf("Tiempo: 3:00");  gotoxy(28,15); printf("Tiempo: 3:00"); 
      gotoxy(5,17); printf("Tarea: Word(1024Mb)"); gotoxy(28,17); printf("Tarea: Word(1024Mb)");
      gotoxy(5,18);  printf("Tiempo: 3:00");  gotoxy(28,18); printf("Tiempo: 3:00");
      // Tareas Realizadas
      gotoxy(65,8);  printf("Tarea: Word(1024Mb)");  gotoxy(94,8); printf("");
      gotoxy(65,9);  printf("Tiempo salida: 3:00");  gotoxy(94,8); printf("");

      gotoxy(65,11); printf("");  gotoxy(94,11); printf("");   
      gotoxy(65,14); printf(""); gotoxy(94,14); printf("");  
      gotoxy(65,17); printf(""); gotoxy(94,17); printf("");
      cout<<endl;cout<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
      system("color 0F"); gotoxy(96,20); textcolor(4); printf("ALERTA: MEMORIA EN 90%%");
		textcolor(7);
      cout<<endl; system("pause"); 
      
 }  
 
