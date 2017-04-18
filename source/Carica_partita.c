#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"libreria.h"


void Grafica_Carica_partita(){
	//stampa  a video solo una piccola parte dell'interfaccia di carica partita
	system("cls");
	printf("\t\t\t\t CARICA PARTITA \n");
	printf("________________________________________________________________________________\n");
    return;
}
void Carica_partita(){
	//cerca la partita che serve all'utente e se la trova la riavvia
	HANDLE hConsole;	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int scelta_carica=0;
	long size;
	char nome_scelto[6]={"     "};  // 5 caratteri vuoti più uno di fine stringa
	BOOLEANO trovato,caricato;
	caricato=FALSO;
	trovato=FALSO;
	size=Controllo_esistenza_partite();
	if(size!=0){
		scelta_carica=Input_carica();
		if(scelta_carica!=ESC){
			do{
			    Leggere_partite_salvate();
				Input_nome_partita(nome_scelto);
				trovato=Cerca_partita(nome_scelto);
				if(trovato==VERO){				
					caricato=VERO;
					SetConsoleTextAttribute(hConsole,GREEN);
					gotoxy(45,9);
					printf("PARTITA CARICATA CON SUCCESSO!");
			        Sleep(1500);
		   	   		SetConsoleTextAttribute(hConsole,BLACK);
		   	   		gotoxy(45,9);
					printf("PARTITA CARICATA CON SUCCESSO!");
					SetConsoleTextAttribute(hConsole,WHITE);
	        	}	
				else{
					caricato=FALSO;
					SetConsoleTextAttribute(hConsole,RED);
					gotoxy(45,9);
					printf("NOME PARTITA NON  ESISTENTE!");
			        Sleep(1500);
		   	   		SetConsoleTextAttribute(hConsole,BLACK);
		   	   		gotoxy(45,9);
					printf("NOME PARTITA NON ESISTENTE!");
					SetConsoleTextAttribute(hConsole,WHITE);
					strcpy(nome_scelto,"     ");  // Puliamo la stringa del nome // 5 caratteri vuoti e uno di fine stringa
				}
			}while(caricato==FALSO);
			 if (caricato==VERO){
	        	Cancellare_partita_caricata(nome_scelto);
	        	Grafica_Nuova_partita();
			    Settare_pedine();
		        Spostare_pedina();
		        if(vincitore!=0)
					Salvare_risultati();
		   	 }
		}
	}
	else{
		SetConsoleTextAttribute (hConsole,RED);
	    gotoxy(15,23);
	    printf("ATTENZIONE! NON CI SONO PARTITE DA CARICARE!!	");
	    Sleep(1500);
	    SetConsoleTextAttribute (hConsole,WHITE);
	}
	return;
}

long Controllo_esistenza_partite(){
	//controlla che il file "partite_salvate" non sia vuoto
	FILE *fp;
	long size=0;
	fp=fopen("Partite_salvate.bin","rb");
	fseek(fp, size, SEEK_END); 
	size=ftell(fp);
	fclose(fp);
	return size;
}

int Input_carica(){
	//serve a far scegliere se caricare una partita o tornare al menu principale, altri caratteri non sono ammessi
	int s=0;
	do{
		Grafica_Carica_partita();
		Grafica_Scelta_carica();
		s=getche();
	}while(s!='s' && s!=ESC);
	return s;
}

void Cancellare_partita_caricata(char nome[]){
	//elimina la partita appena caricata dal file
	typedef struct Partite_salvate{
		char nome_part[6];
		int n;		// Numero giocatori
		int posg1;
		int posg2;
		int posg3;
		int posg4;
		int turno;  // da assegnare alla variabile num	
	}Ps;
	Ps Par_sal;
	FILE *fp, *fp2;
	char vecchio_nome[]="Partite_salvate.bin";
	char nuovo_nome[]="Partite_salvate2.bin";
	
	fp=fopen("Partite_salvate.bin","rb");
	fp2=fopen("Partite_salvate2.bin","ab");
	
	fread(&Par_sal,sizeof(Ps),1,fp);
	while(!feof(fp)){
		if(strcmp(Par_sal.nome_part,nome)!=0 )  // se non  sono uguali
			fwrite(&Par_sal, sizeof(Ps),1,fp2);	  // ricopia il record nell'altro file
		fread(&Par_sal,sizeof(Ps),1,fp);		 
	}
	fclose(fp);
	fclose(fp2);
	remove(vecchio_nome);   //cancello file 
	rename(nuovo_nome,vecchio_nome); // rinomino il file
	
	return;
}

void Grafica_Scelta_carica(){
	//Interfaccia per scegliere se salvare una partita o uscire 
	printf("\n Vuoi caricare una  partita salvata?");
	printf("\n\n\n      s = SI          ESC = Indietro   \n\n");
	printf("Fai la tua scelta: ");
	return;
}

void Settare_pedine(){
	//setta le pedine nelle posizioni previste dalla partita caricata
	int temp=num;
	num=0;
	while(num<n_partecipanti){
		Grafica_muovere_pedina();
		num++;
	}
	num=temp;
	return;
}

