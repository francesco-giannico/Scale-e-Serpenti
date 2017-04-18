#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "costanti.h"
#include <windows.h>
void Inizializzare_gioco();

int main() {
	//funzione principale che collega tutte le altre
	Inizializzare_gioco();
	HANDLE hConsole;	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, WHITE);
	do{
		Menu();
		scelta_menu=getche();
		scelta_menu-=48;
		Sleep(500);
		if(scelta_menu!=0)
			if(scelta_menu==1)
				Nuova_partita();
				else if(scelta_menu==2)
					Carica_partita();
					else if(scelta_menu==3)
						Salva_partita();
						else if(scelta_menu==4)
							Impostazioni();
							else if(scelta_menu==5)
								Record();
	}while(scelta_menu!=0);
	return 0;
}

void Inizializzare_gioco(){
	//funzione di lavoro , per far si che Record_file o Partite_savate siano sempre esistenti , anche se vuoti.
	int i=0;
	typedef struct Record{
		int n_giocatore;   // num+1 = vincitore
		int p_vinte;
		int p_giocate;
	}R;
	R record;
	n_partecipanti=DEFAULT;
	//caricato=FALSO;
	FILE *fp;
	fp=fopen("Record_file.bin","rb");
	if(fp==NULL){
		fp=fopen("Record_file.bin","a");
		while(i<GIOCATORI_MAX){
			record.n_giocatore=i+1;
			record.p_vinte=0;
			record.p_giocate=0;
			i++;
			fwrite(&record,sizeof(R),1,fp);
		}
	}
	fclose(fp);
		
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
	if(fp==NULL)   // Se il file non esiste lo crea
		fp=fopen("Partite_salvate.bin","wb");	
	fclose(fp);	
	return;
}
