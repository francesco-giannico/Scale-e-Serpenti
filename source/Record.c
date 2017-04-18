#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"libreria.h"
#include"costanti.h"

void Record(){
	//permette di visualizzare tutti i risultati precedentemente salvati da Salvare_risultati sul file Record_file
	int s=0;
	Grafica_Record();
	Leggere_risultati();
	printf("\n\nPremi ESC per tornare al menu': ");
	do{
		s=getch();
	}while(s!=ESC);
	return;
}

void Grafica_Record(){
    //interfaccia di Record con la quantità di partite vinte per ogni giocatore e quelle giocate	
	int i=0;
	system("cls");
	printf("\t\t\t\t RECORD \n");
	printf("________________________________________________________________________________");
	printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);	
	printf("\n\t%c                  %c                  %c                  %c",186,186,186,186);
	printf("\n\t%c   GIOCATORE #    %c  PARTITE VINTE   %c  PARTITE GIOCATE %c",186,186,186,186);
	printf("\n\t%c                  %c                  %c                  %c",186,186,186,186);
	i=0;
	while(i<GIOCATORI_MAX){
		printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
		printf("\n\t%c                  %c                  %c                  %c",186,186,186,186);
		i++;
	}
	printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);		
	return;
}
void Leggere_risultati(){
	//legge dal file per tutti i giocatori la quantità di partite vinte e fatte, le ordina in base alle partite vinte, e poi le stamp a video nella tabella
	int giocatori[GIOCATORI_MAX];
	int partite_vinte[GIOCATORI_MAX];
	int partite_fatte[GIOCATORI_MAX];
	int i=0;
	int x=17,y=8;
	// FILE DEI RECORD!
	typedef struct Record{
		int n_giocatore;   // num+1 = vincitore
		int p_vinte;
		int p_giocate;
	}R;
	R record;
	FILE *fp;
	fp=fopen("Record_file.bin","rb");
	fread(&record, sizeof(R),1,fp);
	while(!feof(fp)){
		giocatori[i]=record.n_giocatore;
		partite_vinte[i]=record.p_vinte;
		partite_fatte[i]=record.p_giocate;
		fread(&record, sizeof(R),1,fp);	
		i++;		
	}
	fclose(fp);
	Ordinare_record(giocatori,partite_vinte,partite_fatte);
	i=0;
	while(i<GIOCATORI_MAX){
		gotoxy(x,y);
		printf("%d",giocatori[i]);
		gotoxy(x+19,y);
		printf("%d",partite_vinte[i]);
		gotoxy(x+2*19,y);
		printf("%d",partite_fatte[i]);
		y+=2;
		i++;
	}
	printf("\n\n\n\n\n");
	return;
}

void Ordinare_record(int g[],int v[], int f[]){
	//ordina tutti i record letti in base a partite vinte, quindi in ordine decrescente.
	int i=0,j=0,temp=0;
	while(i<GIOCATORI_MAX){
		temp=v[i];
		j=0;
		while(j<GIOCATORI_MAX){
			if(temp>v[j]){
								
				temp=g[j];
				g[j]=g[i];
				g[i]=temp;
				
				temp=f[j];
				f[j]=f[i];
				f[i]=temp;
				
				temp=v[j];
				v[j]=v[i];
				v[i]=temp;
			}
			j++;
		}
		i++;
	}
	return;
}
