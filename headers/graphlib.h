#ifndef GRAPH_LIB_H
#define GRAPH_LIB_H

//*******************************************************************************
//includere srand((unsigned int)time(0)) nel main se si fa uso di randomizzaGrafo o randomizzaGrafoPesato
//*******************************************************************************

typedef struct arco{
  int key;
  struct arco *next;
  int peso;
}arco;

typedef struct grafo{
  int n_vertici;
  arco **adiacenti;
  int pesato;
}grafo;

/*
*******************************************************
*un grafo vuoto e' rappresentato con un puntatore grafo contenente NULL
*Per inizializzare un grafo e utilizzarlo, usare la funzione nuovoGrafo
*******************************************************
*/

//Funzioni generali. Agiscono su grafi pesati o non

int grafoVuoto(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce 0 o 1 a seconda che il grafo sia vuoto (puntatore uguale a NULL) o meno
*/
int nuovoGrafo(int vertici, grafo **g, int pesato);
/*prende in ingresso un numero di vertici, un puntatore a puntatore a grafo e un intero
*un valore di pesato diverso da 0 indica che il grafo creato sara' pesato
*il puntatore passato puntera' alla memoria allocata per il grafo
*restituisce 0 se non e' possibile allocare memoria per il grafo o se si cerca di creare un grafo con 0 vertici, 1 altrimenti
*/
void menuGrafo(grafo *g);
/*prende un puntatore a grafo
*permette di inserire o rimuovere archi dal grafo finche' non si sceglie di uscire
*/
int isPesato(grafo *g);
/*prende un puntatore a grafo
*se il grafo non e' vuoto
*restituisce 1 se il grafo e' pesato, 0 altrimenti
*/
void stampaGrafo(grafo *g);
/*Prende in ingresso un puntatore a grafo
*per ogni vertice stampa su una riga tutti gli archi uscenti completi di peso qualora il grafo fosse pesato
*/
int numeroVertici(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di vertici, 0 se il grafo e' vuoto
*/
int numeroArchi(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di archi, 0 se non sono presenti archi
*/
int aggiungiArco(grafo *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo non e' gia' presente
*inserisce l'arco da partenza ad arrivo nel grafo, con peso 0 qualora il grafo fosse pesato
*ritorna 1 se l'arco e' stato inserito oppure è già presente, 0 altrimenti
*/
int rimuoviArco(grafo *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo e' presente nel grafo
*elimina l'arco da partenza ad arrivo dal grafo
*ritorna 1 se l'arco e' stato eliminato oppure non era presente, 0 altrimenti
*/
int esisteArco(grafo *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti due vertici del grafo
*ritorna 1 se esiste un arco da partenza ad arrivo, 0 altrimenti
*/
int esisteVertice(grafo *g, int v);
/*prende un puntatore a grafo e un intero rappresentante un vertice
*ritorna 1 se il vertice e' presente nel grafo, 0 altrimenti
*/
int aggiungiVertice(grafo *g);
/*prende un puntatore a grafo
*se il grafo non e' vuoto, aggiunge un vertice
*ritorna 1 se il vertice e' stato inserito, 0 altrimenti
*/
int rimuoviVertice(grafo *g, int vertice);
/*prende un puntatore a grafo e un intero rappresentante un vertice
*elimina dal grafo il vertice e tutti gli archi uscenti o entranti da questo, i vertici successivi hanno il loro numero ridotto di conseguenza
*ritorna 1 se il vertice e' stato eliminato, 0 altrimenti
*/
void randomizzaGrafo(grafo *g);
/*prende un puntatore a grafo
*se il grafo non e' vuoto
*aggiunge archi pseudo-randomicamente nel grafo puntato da g, con peso 0 qualora il grafo fosse pesato
*/

//Funzioni prettamente per grafi pesati

int aggiungiArcoPesato(grafo *g, int partenza, int arrivo, int peso);
/*prende un puntatore a grafo, due interi rappresentanti vertici del grafo e un intero reppresentante il peso dell'arco da inserire
*se il grafo non e' vuoto, e' pesato, i vertici di partenza e arrivo esistono e l'arco non e' gia' presente
*aggiunge l'arco da partenza ad arrivo nel grafo con peso
*ritorna 1 se l'arco e' stato inserito o era gia' presente, 0 altrimenti. Il peso di un arco preesistente non viene modificato.
*/
int pesoArco(grafo *g, int partenza, int arrivo);
/*prende un grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto e esiste un arco fra partenza e arrivo
*ritorna il peso dell'arco, 0 se il grafo non e' pesato
*/
void randomizzaGrafoPesato(grafo *g, int massimo);
/*prende un puntatore a grafo e un intero
*se il grafo non e' vuoto, e' pesato e il valore di massimo non e' negativo
*aggiunge archi pesati nel grafo puntato da g con peso compreso fra 0 e massimo
*/
#endif
