#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"libreria.h"

void Impostazioni(){
	//permette di modificare la quantità dei partecipanti 
	n_partecipanti=Input_giocatori();
	if (n_partecipanti==TRE){
		 n_partecipanti=3;
    }	
    else if(n_partecipanti==DUE){
          n_partecipanti=2;
   	}
    else 
	   n_partecipanti=4;
	return;
}
	
void Grafica_Impostazioni(){
	//interfaccia di impostazioni	
	system("cls");
	printf("\t\t\t\t IMPOSTAZIONI \n");
	printf("________________________________________________________________________________");
	printf("\n Numero Giocatori [2-4].");
	printf("\n\n\n Inserire il numero dei giocatori:");	
	printf("\n\n Oppure premi ESC per tornare al menu'",27,196);
	gotoxy(36,6);
	return;
}

int Input_giocatori(){
	//permette di inserire la  quantità di partecipanti da 2-4
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int num=0; // var locale
	Grafica_Impostazioni();
	num=getche();
	while((num<DUE||num>QUATTRO) && num!=ESC){
		   Sleep(500);
	  	   SetConsoleTextAttribute(hConsole,RED);
		   gotoxy(0,9);
	       printf("VALORE NON VALIDO! INSERIRE UN VALORE TRA 2-4!");
	       Sleep(1500);
	   	   SetConsoleTextAttribute(hConsole,WHITE);
	   	   Grafica_Impostazioni();
	       num=getche();
   	}
	return num;
}
