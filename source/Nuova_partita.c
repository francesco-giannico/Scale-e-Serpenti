#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include"costanti.h"
#include"libreria.h"

void Nuova_partita(){
	//funzione che permette di giocare una partita, e di salvare i risultati
	Inizializzare_partita();
	Settare_pedine();	
	Spostare_pedina();
	if(vincitore!=0)
		Salvare_risultati();
	return;
}
void Grafica_Nuova_partita(){
	//stampa a video il campo da gioco
	//procedura per prelevare le informazioni dalla scheda video
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	//funzione che setta il colore di scrittura in VGA
	SetConsoleTextAttribute (hConsole,WHITE);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c    %c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n",186,186,186,186,186,186,186,186,186,186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188);
	
	int x=1,y=1,cont=100;
	char num[4]="";

	//da 100 a 91, da 80 a 71, da 60 a 51..., da 20 a 11. 
	while(y<=29){
		x=1;
		while(x<=46){
			itoa(cont,num,10);
			gotoxy(x,y);
			printf("%s",num);
			cont--;		
			x+=5;
		}
		cont-=10;
		y+=6;
	}
	x=1;
	y=4;
	//da 90 a 81, da 70 a 61, da 50 a 41..., da 10 a 1.
	cont=81;
	while(y<=29){
		x=1;
		while(x<=46){
			itoa(cont,num,10);
			gotoxy(x,y); 
			printf("%s",num);
			x+=5;
			cont++;
		}
		cont-=30;
		y+=6;
	}
	
	gotoxy(61,1);
	printf("LEGENDA");
	gotoxy(52,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(52,3);
	printf("%c         TASTI         %c",179,179);
	gotoxy(52,4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
	gotoxy(52,5);
	printf("%c  Esc   Torna al menu' %c",179,179);
	gotoxy(52,6);
	printf("%c  Invio   Lancio dado  %c",179,179);
	gotoxy(52,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);
	gotoxy(52,8);
	printf("%c        SIMBOLI        %c",179,179);
	gotoxy(52,9);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180);

	gotoxy(52,10);	
	printf("%c                       %c",179,179);
	gotoxy(52,11);
	printf("%c                       %c",179,179);
	gotoxy(52,12);
	printf("%c                       %c",179,179);
	gotoxy(52,13);
	printf("%c                       %c",179,179);
	gotoxy(52,14);
	printf("%c                       %c",179,179);
	gotoxy(52,15);
	printf("%c                       %c",179,179);

	gotoxy(56,10);//12 RED
	SetConsoleTextAttribute (hConsole, RED);   
	printf("%c    Giocatore 1",3);			 
											  
	gotoxy(56,11);//11 BLUE
	SetConsoleTextAttribute (hConsole, BLUE);
	printf("%c    Giocatore 2",4);
	
	gotoxy(56,12);//6 GREY
	SetConsoleTextAttribute (hConsole, GREY);
	printf("%c    Giocatore 3",5);
	
	gotoxy(56,13);//13 MAGENTA
	SetConsoleTextAttribute (hConsole, MAGENTA);
	printf("%c    Giocatore 4",6);
	
	gotoxy(56,14);//10 VERDE
	SetConsoleTextAttribute (hConsole, GREEN);
	printf("%c    Serpente   ",31);

	gotoxy(56,15);//14 GIALLO
	SetConsoleTextAttribute (hConsole, YELLOW);
	printf("%c    Scala     ",30);
	 //15 WHITE
	SetConsoleTextAttribute (hConsole, WHITE);
	gotoxy(52,16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	// FINE TABELLA  LEGENDA
	
	//POSIZIONIAMO	 SCALE E SERPENTI NEL CAMPO DA GIOCO IN MODO FISSO	
	SetConsoleTextAttribute (hConsole,YELLOW);
	gotoxy(19,10);
	printf("1");
	gotoxy(3,25);
	printf("%c1",30); 
		//scale 2
	gotoxy(14,19);
	printf("2");
	gotoxy(18,25);
	printf("%c2",30);
		//scale 3
	gotoxy(24,7);
	printf("3");
	gotoxy(48,28);
	printf("%c3",30);
		//scale 4
	gotoxy(29,1);
	printf("4");
	gotoxy(33,19);
	printf("%c4",30);
		//scale 5
	gotoxy(14,4);
	printf("5");
	gotoxy(8,13);
	printf("%c5",30);
	
		
	// setta colore VERDE per serpenti
	SetConsoleTextAttribute (hConsole,GREEN);
		//serpenti 1
	gotoxy(23,1);
	printf("%c1",31);
	gotoxy(44,13);
	printf("1",31);
			//serpenti 2
	gotoxy(38,4);
	printf("%c2",31);
	gotoxy(14,22);
	printf("2");
		//serpenti 3
	gotoxy(18,7);
	printf("%c3",31);
	gotoxy(34,28);
	printf("3");
			//serpenti 4
	gotoxy(28,16);
	printf("%c4",31);
	gotoxy(24,19);
	printf("4");
	
			//serpenti 5
	gotoxy(33,10);
	printf("%c5",31);
	gotoxy(44,22);
	printf("5");	
	
	SetConsoleTextAttribute (hConsole,WHITE);
	gotoxy(1,32);
	//imposto posizione iniziale giocatori
	gotoxy(56,18);
	printf("PARTECIPANTI");
	if(n_partecipanti==2){
		gotoxy(56,19);//12 RED
		SetConsoleTextAttribute (hConsole, RED);   
		printf("%c",3);			  
		gotoxy(58,19);//11 BLUE
		SetConsoleTextAttribute (hConsole, BLUE);
		printf("%c",4);
	}	
	else if(n_partecipanti==3){
		gotoxy(56,19);//12 RED
		SetConsoleTextAttribute (hConsole, RED);   
		printf("%c",3);			  
		gotoxy(58,19);//11 BLUE
		SetConsoleTextAttribute (hConsole, BLUE);
		printf("%c",4);
		gotoxy(60,19);//6 GREY
		SetConsoleTextAttribute (hConsole, GREY);
		printf("%c",5);
	}
	else if(n_partecipanti==4){	
		gotoxy(56,19);//12 RED
		SetConsoleTextAttribute (hConsole, RED);   
		printf("%c",3);			  
		gotoxy(58,19);//11 BLUE
		SetConsoleTextAttribute (hConsole, BLUE);
		printf("%c",4);
		gotoxy(60,19);//6 GREY
		SetConsoleTextAttribute (hConsole, GREY);
		printf("%c",5);
		gotoxy(62,19);//13 MAGENTA
		SetConsoleTextAttribute (hConsole, MAGENTA);
		printf("%c",6);
	}	
	//Imposto il colore bianco di default
	SetConsoleTextAttribute (hConsole,WHITE);
	return;
}

void Inizializzare_partita() {
	//setta qualche variabile prima di iniziare la partita
	num=0;
	while(num<n_partecipanti){
		cella_g[num]=0;
		num++;
	}
	num=0; // resetta la variabile turno-giocatore
	vincitore=0;
	Grafica_Nuova_partita();
	return;	
}

void Spostare_pedina(){
	// funzione che permette di giocare tutta la partita
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int dado=0;
	int scelta_tasto=0;
	do{
		scelta_tasto=Turno_giocatore();
		if(scelta_tasto!=ESC){
			dado=Lanciare_dado();		
			gotoxy(54,23);	
			printf("Valore del dado: %d",dado);
			cella_prec_g[num]=cella_g[num];
			cella_g[num]+=dado;
			if(cella_g[num]>DIM_CAMPO)
				cella_g[num]=100;
	     	Grafica_cancellare_pedina();
			Grafica_muovere_pedina();
			Vedere_vittoria();	
			if(vincitore==0){
				Vedere_scala();
				Vedere_serpente();
			}
			// Cancello scritte col colore nero
			Sleep(1000);
			SetConsoleTextAttribute(hConsole,BLACK);
			gotoxy(54,20);
			printf("Turno del Giocatore %d",num+1);
			gotoxy(54,21);
			printf("Fai la scelta: ");
			gotoxy(54,22);
			printf("Lancio dado...");
			gotoxy(54,23);	
			printf("Valore del dado: %d",dado);
			SetConsoleTextAttribute(hConsole,WHITE);
			num++;
			if(num==n_partecipanti)
			   num=0;		
		}
	}while(scelta_tasto!=ESC && vincitore==0);
	return;
}

int Turno_giocatore(){
	//scelta del giocatore a cui tocca, se uscire dal gioco o lanciare il dado
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int s;  // Scelta del tasto premuto
	do{
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,20);
		printf("Turno del Giocatore %d",num+1);
		gotoxy(54,21);
		printf("Fai la scelta: ");
		s=getch();
		if(s==INVIO){
			gotoxy(54,22);
			printf("Lancio dado...");
		}
	}while(s!=INVIO && s!=ESC);
	return s;
}

void Salvare_risultati(){
	//salva i risultati riguardo le partite fatte e vinte per ogni partecipante
	int i=0; // Per indicare il giocatore num i
	long posizione=0;
	// FILE DEI RECORD!
	typedef struct Record{
		int n_giocatore;   // num+1 = vincitore
		int p_vinte;
		int p_giocate;
	}R;
	R record;
	FILE *fp;
	fp=fopen("Record_file.bin","r+b");
	posizione=ftell(fp);
	fread(&record, sizeof(R),1,fp);
	while(i<n_partecipanti && !feof(fp)){
		if(vincitore==record.n_giocatore)
			record.p_vinte++;
		record.p_giocate++;
		fseek(fp,posizione,0);
		fwrite(&record,sizeof(R),1,fp);
		posizione=(i+1)*sizeof(R);
		fseek(fp,posizione,0);
		fread(&record, sizeof(R),1,fp);	
		i++;		
	}
	fclose(fp);
	return;
}

int Lanciare_dado(){
	//genera un valore casuale al dado
	int d;
	srand (time(NULL));
	d=rand()%MAXDADO+1;
	return d;
}

void Grafica_muovere_pedina(){
	//sposta la pedina nella nuova posizione
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    int x=1,y=1;
	// DISEGNA LA PEDINA IN NUOVA POSIZIONE  
	int casella,decina,unita,resto=0,giocatore;
	BOOLEAN flag;
    casella=cella_g[num]; // casella contiene la posizione  del giocatore nuova in base al dado uscito.
	giocatore=num;// n è num quindi è il turno del giocatore 
    decina=casella/10;
	unita=casella%10;
	flag=FALSO;
	int i=2;
	//Se è un multiplo di 10 
	if(unita==0){
		//Se pari
		if(decina%2==0){
			x=1;
			i=0;
			y=38;  
			while(i<=10 && flag==FALSO){
				y-=6;
				if(decina==i){
					flag=VERO;
				}
				i+=2;
											
			}	
		}
		else{
			// Se dispari
			i=1;
			x=46;
			y=35;
			while(i<10 && flag==FALSO){
				y-=6;							
				if(decina==i){
					flag=VERO;
				}
				i+=2;
			}
		}
	} 
	// Se non multiplo di 10
	else{
		resto=decina%2;
		if(resto==0){
			//Se pari
			i=0;
			y=29;
			// trova la y
			flag=FALSO;
			while(i<=8 && flag==FALSO){
				if(decina==i){
					flag=VERO;
				}
				else
					y-=6;
				i+=2;
			}
			// trova la x
			x=1;
			i=1;
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(i==unita){
					flag=VERO;
				}
				else
					x+=5;
				i++;
			}
		}
		else{
			//Se dispari
			i=1;
			y=26;
			// trova la y
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(decina==i){
					flag=VERO;
				}
				else
					y-=6;
				i+=2;
			}
			// trova la x
			x=46;
			i=1;
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(i==unita){
					flag=VERO;
				}
				else
					x-=5;
				i++;
			}		
	
		}
	}
	// sposto le pedine effettivamente in base al numero del giocatore
	x+=giocatore;
	if(giocatore==0){
		gotoxy(x,y);//12 RED
		SetConsoleTextAttribute (hConsole, RED);   
	   	printf("%c",3);	
	} 
	else if (giocatore==1){
			gotoxy(x,y);//11 BLUE
	    	SetConsoleTextAttribute (hConsole, BLUE);
			printf("%c",4);		
	}
	else if(giocatore==2){
		gotoxy(x,y);//6 GREY
		SetConsoleTextAttribute (hConsole, GREY);
		printf("%c",5);		  
	}
	else if(giocatore==3){	
	   		gotoxy(x,y);//13 MAGENTA
			SetConsoleTextAttribute (hConsole, MAGENTA);
			printf("%c",6);
	} 
	return;
}

void Grafica_cancellare_pedina(){
	//cancella la pedina dalla vecchia posizione
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x=1,y=1;
	int casella,decina,unita,resto=0,giocatore;
	BOOLEAN flag;
    casella=cella_prec_g[num]; // casella contiene la posizione  del giocatore nuova in base al dado uscito.
	giocatore=num;// n è num quindi è il turno del giocatore 
    decina=casella/10;
	unita=casella%10;
	flag=FALSO;
	int i=2;
	//Se è un multiplo di 10 
	if(unita==0){
		//Se pari
		if(decina%2==0){
			x=1;
			i=0;
			y=38;  // + 6 per 			<<< INZIFTO >>> 
			while(i<=10 && flag==FALSO){
				y-=6;
				if(decina==i){
					flag=VERO;
				}
				i+=2;
											
			}	
		}
		else{
			// Se dispari
			i=1;
			x=46;
			y=35;
			while(i<10 && flag==FALSO){
				y-=6;							
				if(decina==i){
					flag=VERO;
				}
				i+=2;
			}
		}
	} 
	// Se non multiplo di 10
	else{
		resto=decina%2;
		if(resto==0){
			//Se pari
			i=0;
			y=29;
			// trova la y
			flag=FALSO;
			while(i<=8 && flag==FALSO){
				if(decina==i){
					flag=VERO;
				}
				else
					y-=6;
				i+=2;
			}
			// trova la x
			x=1;
			i=1;
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(i==unita){
					flag=VERO;
				}
				else
					x+=5;
				i++;
			}
		}
		else{
			//Se dispari
			i=1;
			y=26;
			// trova la y
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(decina==i){
					flag=VERO;
				}
				else
					y-=6;
				i+=2;
			}
			// trova la x
			x=46;
			i=1;
			flag=FALSO;
			while(i<=9 && flag==FALSO){
				if(i==unita){
					flag=VERO;
				}
				else
					x-=5;
				i++;
			}		
		}
	}
	// sposto le pedine effettivamente in base al numero del giocatore
	x+=giocatore;
	SetConsoleTextAttribute (hConsole, BLACK); 
	if(giocatore==0){
		gotoxy(x,y);
	   	printf("%c",3);	
	} 
	else if (giocatore==1){
			gotoxy(x,y);
			printf("%c",4);		
	}
	else if(giocatore==2){
		gotoxy(x,y);
		printf("%c",5);		  
	}
	else if(giocatore==3){	
	   		gotoxy(x,y);
			printf("%c",6);
	} 
	return;
}

void Vedere_vittoria(){
	//controlla se c'è stato un vincitore
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(cella_g[num]>=DIM_CAMPO){
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,26);
		printf("GIOCATORE %d HA VINTO!",num+1);
		printf("\a\a\a");
		Sleep(1000);
		printf("\a\a\a");
		Sleep(1000);
		printf("\a\a\a\a\a\a\a");
		vincitore=num+1;
		Sleep(1500);
	}
	return;
}

void Vedere_scala(){
	//controlla se una pedina è su una casella di una scala
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOLEANO rilevata=FALSO;
	int v_scala_partenza[5]={20,17,10,34,59};
	int v_scala_arrivo[5]={64,38,76,95,83};
    int i=0;
    int salvaind=0;//salva l'indice
    while(i<ELEM_V){
		if(cella_g[num]==v_scala_partenza[i]){
			rilevata=VERO;
	        salvaind=i;
		}
		i++;
	}
	if(rilevata==VERO){
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,26);
		printf("GIOCATORE %d SULLA SCALA!",num+1);	
		Sleep(1000);
		SetConsoleTextAttribute(hConsole,BLACK);
		gotoxy(54,26);
		printf("GIOCATORE %d SULLA SCALA!",num+1);	
		Sleep(500);
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,26);
		printf("GIOCATORE %d SULLA SCALA!",num+1);	
		Sleep(1500);
		SetConsoleTextAttribute(hConsole,BLACK);
		gotoxy(54,26);
		printf("GIOCATORE %d SULLA SCALA!",num+1);
		cella_g[num]=v_scala_arrivo[salvaind]; 
		cella_prec_g[num]=v_scala_partenza[salvaind];
		Grafica_cancellare_pedina();
	    Grafica_muovere_pedina();	
	}
	return;
}

void Vedere_serpente(){
	//controlla se un una pedina è su una casella di un serpente
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	BOOLEANO rilevata=FALSO;
	
	int v_serpente_partenza[5]={96, 88, 77, 46, 67};
	int v_serpente_arrivo[5]={52, 23, 7, 36, 29};
    int i=0;
    int salvaind=0; //salva l'indice
    while(i<ELEM_V){
		if(cella_g[num]==v_serpente_partenza[i]){
			rilevata=VERO;
	        salvaind=i;
		}
		i++;
	}
	if(rilevata==VERO){
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,26);
		printf("GIOCATORE %d SUL SERPENTE!",num+1);	
		Sleep(1000);
		SetConsoleTextAttribute(hConsole,BLACK);
		gotoxy(54,26);
		printf("GIOCATORE %d SUL SERPENTE!",num+1);	
		Sleep(500);
		SetConsoleTextAttribute(hConsole,WHITE);
		gotoxy(54,26);
		printf("GIOCATORE %d SUL SERPENTE",num+1);	
		Sleep(1500);
		SetConsoleTextAttribute(hConsole,BLACK);
		gotoxy(54,26);
		printf("GIOCATORE %d SUL SERPENTE!",num+1);
		cella_g[num]=v_serpente_arrivo[salvaind]; 
		cella_prec_g[num]=v_serpente_partenza[salvaind];
		Grafica_cancellare_pedina();
	    Grafica_muovere_pedina();	
	}
	return;
}
