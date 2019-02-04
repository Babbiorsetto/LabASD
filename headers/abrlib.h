#ifndef ABR_LIB_H
#define ABR_LIB_H

//*******************************************************************************
//includere srand((unsigned int)time(0)) nel main se si fa uso di randomizzaABR
//*******************************************************************************

typedef struct nodo{
  int info;
  struct nodo *sx;
  struct nodo *dx;
}nodo;

typedef nodo* albero;

/*
*******************************************************
*un albero vuoto e' rappresentato con un puntatore albero contenente NULL
*Inizializzare sempre a NULL i puntatori a alberi vuoti
*******************************************************
*/

int alberoVuoto(albero radice);
/*prende come argomento un albero
*ritorna 1 se l'albero e' vuoto, 0 altrimenti
*/
void inizializzaABR(albero *radice);
/*prende un puntatore ad ABR
*chiede all'utente quanti elementi desidera inserire nell'ABR e nel caso in cui siano piu' di 0 li inserisce
*/
int valoreRadice(albero radice, int *val);
/*prende come argomento un albero e un intero passato per riferimento
*se la radice non e' NULL
*il valore della radice e' posto nella variabile var
*ritorna 1 se il valore della radice e' stato recuperato, 0 se non e' stato possibile
*/
albero figlioSx(albero radice);
/*ritorna il sottoalbero sinistro di radice
*/
albero figlioDx(albero radice);
/*ritorna il sottoalbero destro di radice
*/
albero costruisciAlbero(int e, albero s, albero d);
/*dati un intero e due alberi
*alloca spazio per un nuovo nodo, contenente l'intero e i due alberi come figli
*ritorna l'albero cosi' creato
*/
albero deallocaNodo(albero radice);
/*elimina la radice dell'albero passato come argomento
*ritorna NULL se il nodo e' stato deallocato con successo
*/
void visitaPreOrder(albero radice);
/*stampa a standard output la visita pre order dell'albero
*/
void visitaInOrder(albero radice);
/*stampa a standard output la visita in order dell'albero
*/
void visitaPostOrder(albero radice);
/*stampa a standard output la visita post order dell'albero
*/
int ricercaInABR(albero radice, int key);
/*prende in ingresso un ABR e un intero
*ritorna 1 se key e' presente nell'ABR, 0 altrimenti
*/
int inserisciInABR(albero *radice, int e);
/*prende in ingresso un puntatore ad un ABR e un intero
*se l'intero non e' gia' presente nell'ABR
*inserisce l'intero nell'ABR preservandone le proprieta', eventualmente modifica la radice dell'albero
*ritorna 1 se l'intero e' stato inserito, 0 se era gia' presente
*/
int minimoABR(albero radice);
/*dato un ABR ritorna il minimo intero contenuto
*/
void eliminaInABR(albero *radice, int e);
/*dato un puntatore ad ABR e un intero
*se l'intero e' presente nell'ABR
*lo elimina e ripristina l'ABR, eventualmente modifica la radice dell'albero
*/
void randomizzaABR(albero *radice, int numeroElementi, int valoreMax);
/*dato un puntatore ad ABR e due interi
*se l'ABR e' vuoto e numeroElementi non e' maggiore di valoreMax
*inizializza l'ABR con numeroElementi interi compresi fra 1 e valoreMax
*/
#endif
