#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"libreria.h"
#include"costanti.h"

void Salva_partita(){
	//salva tutti i dati utili al carica partita della partita in corso
	HANDLE hConsole;	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int scelta_salva=0;
	char nome_scelto[6]={"     "};  // 5 caratteri vuoti e uno di fine stringa
	BOOLEANO trovato, salvato;
	trovato=FALSO;
	salvato=FALSO;
	scelta_salva=Input_salva();
	if(scelta_salva!=ESC){
		do{
			Leggere_partite_salvate();
			Input_nome_partita(nome_scelto);
			trovato=Cerca_partita(nome_scelto);
			if(trovato==FALSO){
				Scrivere_nel_file(nome_scelto);
				salvato=VERO;
				SetConsoleTextAttribute(hConsole,GREEN);
				gotoxy(45,9);
				printf("PARTITA SALVATA CON SUCCESSO!");
		        Sleep(1500);
	   	   		SetConsoleTextAttribute(hConsole,BLACK);
	   	   		gotoxy(45,9);
				printf("PARTITA SALVATA CON SUCCESSO!");
				SetConsoleTextAttribute(hConsole,WHITE);
			}	
			else{
				salvato=FALSO;
				SetConsoleTextAttribute(hConsole,RED);
				gotoxy(45,9);
				printf("NOME PARTITA GIA' ESISTENTE!");
		        Sleep(1500);
	   	   		SetConsoleTextAttribute(hConsole,BLACK);
	   	   		gotoxy(45,9);
				printf("NOME PARTITA GIA' ESISTENTE!");
				SetConsoleTextAttribute(hConsole,WHITE);
				strcpy(nome_scelto,"     ");
			}
		}while(salvato==FALSO);
	}
	return;
}
int Input_salva(){
	//serve a far scegliere se salvare una partita o tornare al menu principale, altri caratteri non sono ammessi
	int s=0;
	do{
		Grafica_Salva_partita();
		Grafica_Scelta_salva();
		s=getche();
	}while(s!='s' && s!=ESC);
	return s;
}
void Leggere_partite_salvate(){
	//legge dal file tutte le partite salvate e stampa a video il nome della partita e il numero dei partecipanti
	//funzione usata sia da carica partita che da salva partita 
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
	FILE *fp;
    if(scelta_menu==2)
    	Grafica_Carica_partita();
   	else 
    	Grafica_Salva_partita();
	fp=fopen("Partite_salvate.bin","rb");
	Grafica_Inizio_elenco();
	fread(&Par_sal, sizeof(Ps),1,fp);
	while(!feof(fp)){
		Grafica_Elenco_partite(Par_sal.nome_part,Par_sal.n);
		fread(&Par_sal, sizeof(Ps),1,fp);		
	}
	Grafica_Fine_elenco();
	fclose(fp);
	return;
}
void Input_nome_partita(char nome[]){
	 //funzione usata sia da carica partita che da salva, e permette di inserire il nome di una partita
	HANDLE hConsole;		
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i=0; 	// Lunghezza stringa car
	char car=0;
	do{
		gotoxy(45,5);
		printf("e premere invio:                ");
		gotoxy(63,5);
     	printf("%s",nome);
     	gotoxy(63+i,5);
		car=getche();
		if(car!=INVIO && car!=ESC && (( car>=A && car<=Z) || (car>=a && car<=z) )){ // Solo lettere (esclusi  backspace ed enter)
			nome[i]=car;
			i++;
		}
		else{
			if(car==ESC && i>0){  
				i--;
				nome[i]='\0';	
			}
		}
	}while( (i<5 && i==0) || ( i<5 && car!=INVIO) ); // ripete finchè lungh<5 AND =0  OPPURE lungh<5  AND l'ultimo car è invio
													// Non permette l'inserimento di invio a primo colp
	return;
}
BOOLEANO Cerca_partita(char nome[]){
	//cerca la partita in base al nome inserito
	FILE *fp;
	BOOLEANO trov=FALSO;
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
	fp=fopen("Partite_salvate.bin","rb");
	fread(&Par_sal, sizeof(Ps),1,fp);
	while(!feof(fp) && trov==FALSO){
		if( (strcmp(nome, Par_sal.nome_part))==0 ){
			trov=VERO;
			if (scelta_menu==2){ //nel caso è carica partita
				num=Par_sal.turno;
			    n_partecipanti=Par_sal.n;
			    if (n_partecipanti==2){
					cella_g[0]=Par_sal.posg1;
					cella_g[1]=Par_sal.posg2;
			    }
			    else if(n_partecipanti==3){
			    	cella_g[0]=Par_sal.posg1;
				    cella_g[1]=Par_sal.posg2;
				    cella_g[2]=Par_sal.posg3;
			    }
			    else if(n_partecipanti==4){
			    	cella_g[0]=Par_sal.posg1;
				    cella_g[1]=Par_sal.posg2;
				    cella_g[2]=Par_sal.posg3;
				    cella_g[3]=Par_sal.posg4;
		   		}
			}
		}
		fread(&Par_sal, sizeof(Ps),1,fp);
	}	
	fclose(fp);
	return trov;
}
void Scrivere_nel_file(char nome[]){
	//scrive nel file tutti i dati utili al carica partita per ripendere la partita in corso
	FILE *fp;
	BOOLEANO trov=FALSO;
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
	fp=fopen("Partite_salvate.bin","ab");
	Par_sal.n=n_partecipanti;
	Par_sal.turno=num;
	Par_sal.posg1=cella_g[0];
	Par_sal.posg2=cella_g[1];
	Par_sal.posg3=cella_g[2];
	Par_sal.posg4=cella_g[3];
	strcpy(Par_sal.nome_part,nome);
	fwrite(&Par_sal, sizeof(Ps),1,fp);
	
	fclose(fp);
	return;
}
void Grafica_Salva_partita(){
	//stampa a video una piccola parte dell'interfaccia del salva partita
	system("cls");
	printf("\t\t\t\t SALVA PARTITA \n");
	printf("________________________________________________________________________________\n");
	return;
}
void Grafica_Scelta_salva(){
	//stampa a video una piccola parte dell'interfaccia del salva partita
	printf("\n Vuoi salvare la partita in corso?");
	printf("\n\n\n      s = SI          ESC = Indietro   \n\n");	
	printf("Fai la tua scelta: ");
	return;
}
void Grafica_Inizio_elenco(){
	//stampa a video una piccola parte dell'interfaccia del salva partita con le intestazioni della tabella che conterranno le partite esistenti sul file
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\n%c  NOME PARTITA  %c # PARTECIPANTI  %c",186,186,186);
	return;
}
void Grafica_Elenco_partite(char nome[6],int n){
	//stampa a video una piccola parte dell'interfaccia del salva partita aggiungendo all'interno della tabella tutte le partite salvate sul file
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	printf("\n%c      %s\t %c\t  %d\t   %c",186,nome,186,n,186);
	return;
}
void Grafica_Fine_elenco(){
	//stampa a video una piccola parte dell'interfaccia del salva partita con le ultime informazioni per la comunicazione con l'utente
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(45,3);
	printf("Inserire il nome della ");
	gotoxy(45,4);
	if(scelta_menu==2)
		printf("partita da caricare");
	else
	    printf("partita da salvare");
	
   	gotoxy(45,5);
	printf("e premere invio:");
	gotoxy(45,6);
	printf("(MAX 5 LETTERE!)");
	return;
}
