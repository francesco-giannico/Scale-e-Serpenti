#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"costanti.h"


void Menu(){
	//stampa il menu iniziale
	system("cls");
	HANDLE hConsole;	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole,GREEN);
	printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n"); 
	printf("   ***   ***   **   *   ***     ***      *** *** ****   **** *** *   * ***** *\n");
	printf("  *     *     *  *  *   *       *       *    *   *  *   *  * *   * * *   *   *\n");
	printf("    *  *     * ** * *   ***     ***       *  *** ****   **** *** *  **   *   *\n");
	printf("     *  *    *    * *   *       *          * *   *   *  *    *   *   *   *   *\n");
	printf("  ***    *** *    * *** ***     ***     ***  *** *    * *    *** *   *   *   *\n");
	printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
	SetConsoleTextAttribute (hConsole,WHITE);
	printf("________________________________________________________________________________\n");
	printf("			[1]. Nuova partita\n");
	printf("			[2]. Carica partita\n");
	printf("			[3]. Salva partita\n");
	printf("			[4]. Impostazioni\n");
	printf("			[5]. Record\n\n");
	printf("			[0]. Fine\n\n");
	printf("Fai la tua scelta premendo un tasto fra quelli indicati nel menu': ");
	return;
}
void gotoxy(short x, short y) {
	//funzione di lavoro che serve a settare il colore in scrittura a video e la posizione DPI
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


