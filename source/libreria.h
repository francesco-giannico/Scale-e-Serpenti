#ifndef LIBRERIA_H
#define LIBRERIA_H
#include"costanti.h"

/*Grafiche */
void Menu();
void Grafica_Nuova_partita();
void Grafica_Carica_partita();
void Grafica_Salva_partita();
void Grafica_Impostazioni();
void Grafica_Record();
void Grafica_cancellare_pedina();
void Grafica_muovere_pedina();
void Grafica_Scelta_salva();
void Grafica_Inizio_elenco();
void Grafica_Elenco_partite(char nome[6],int n );
void Grafica_Fine_elenco();

/* funzioni principali */
void Nuova_partita();
void Salva_partita();
void Carica_partita();
void Impostazioni();
void Record();

//FUNZIONI NUOVA PARTITA E IMPOSTAZIONI
int Input_giocatori();  //funzione che riceve in input il numero di partecipanti
void Inizializzare_partita();
void Spostare_pedina();
int Turno_giocatore();
void Salvare_risultati();
int Lanciare_dado();
void Vedere_vittoria();
void Vedere_scala();
void Vedere_serpente();

//FUNZIONI RECORD
void Leggere_risultati();
void Ordinare_record(int g[],int v[],int f[]);

//FUNZIONI SALVA PARTITA	
int Input_salva();
void Leggere_partite_salvate();
void Input_nome_partita(char nome[]);
BOOLEANO Cerca_partita(char nome[]);
void Scrivere_nel_file(char nome[]);

//FUNZIONI CARICA PARTITA	
void Carica_partita();
void Grafica_Scelta_carica();
long Controllo_esistenza_partite();
int Input_carica();


/*Variabile globali */
int num; 			// Indica il turno del giocatore 
int n_partecipanti;			//Indica il numero di giocatori partecipanti [2-4]  di default è 2
int vincitore;  	//Indica il numero del giocatore +1 che ha vinta
int cella_g[GIOCATORI_MAX];//cella del giocatore dopo il lancio del dado 
int cella_prec_g[GIOCATORI_MAX]; //cella  di ogni giocatore prima del lancio del dado
int scelta_menu;  // var scelta che serve al menu' 


#endif 
