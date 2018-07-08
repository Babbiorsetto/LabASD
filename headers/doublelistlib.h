#ifndef DOUBLE_LIST_LIB_H
#define DOUBLE_LIST_LIB_H

//*******************************************************************************
//includere srand((unsigned int)time(0)) nel main se si fa uso di randomizzaListaDop
//*******************************************************************************

typedef struct delem delem;

typedef delem* dlista;

/*
*******************************************************
*una lista vuota e' rappresentata con un puntatore dlista contenente NULL
*Inizializzare sempre a NULL i puntatori a dliste vuote
*******************************************************
*/

dlista inizializzaListaDop(dlista top);
/*data una lista doppiamente puntata
*chiede all'utente quanti elementi vuole inserire in essa e, nel caso in cui siano più di 0, li inserisce.
*/
void stampaListaDop(dlista top);
/*data una lista doppiamente puntata
*stampa in stdout la lista
*/
dlista newElemDop(int k);
/*dato un intero k
*alloca spazio per un nuovo nodo di lista doppiamente puntata contenente l'intero
*restituisce un puntatore al nodo così creato
*/
dlista precedenteDop(dlista nodo);
/*prende un puntatore a nodo di lista doppiamente puntata
*se nodo non e' NULL
*restituisce un puntatore all'elemento precedente
*/
dlista successivoDop(dlista nodo);
/*prende un puntatore a nodo di lista doppiamente puntata
*se nodo non e' NULL
*restituisce un puntatore all'elemento successivo
*/
int valoreDiDop(dlista nodo);
/*prende un puntatore a nodo di lista doppiamente puntata
*se nodo non e' NULL
*restituisce l'intero contenuto nel nodo
*/
dlista aggiungiInTestaDop(dlista top, int k);
/*data una lista doppiamente puntata e un intero
*aggiunge un nodo contenente l'intero in testa alla lista
*restituisce il nuovo top della lista
*/
dlista aggiungiInCodaDop(dlista top, int k);
/*data una lista doppiamente puntata e un intero
*aggiunge un nodo contenente l'intero in coda alla lista
*restituisce il top della lista eventualmente modificato
*/
dlista eliminaTopDop(dlista top);
/*data una lista doppiamente puntata
*elimina il top della lista
*restituisce il nuovo top, NULL nel caso la lista fosse gia' vuota o contenesse un solo nodo
*/
dlista randomizzaListaDop(dlista top, int numeroElementi, int valoreMax);
/*data una lista doppiamente puntata e due interi
*inserisce nella lista numeroElementi interi compresi fra 1 e valoreMax
*restituisce il nuovo top della lista
*/
#endif //DOUBLE_LIST_LIB_H
