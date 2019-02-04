#ifndef LIST_LIB_H
#define LIST_LIB_H

typedef struct elem
{
    int info;
    struct elem *next;
}elem;
/*un elem e' un nodo, elemento costitutivo di una lista*/

typedef elem* lista;
/*un puntatore di tipo lista e' una lista di nodi
puo' contenere solo un indirizzo di nodo o il valore NULL*/

void stampaLista(lista top);
/*stampa tutti gli elementi di una lista di interi*/

lista successivo(lista nodo);
/*restituisce il next del nodo puntato da nodo*/

int valoreDi(lista nodo);
/*restituisce l'intero contenuto nel nodo*/

lista newElem(int k);
/*dato un intero
*alloca memoria per un nuovo nodo contenente l'intero
*ritorna un puntatore al nodo creato
*/
lista aggiungiInTesta(lista top, int k);
/*data una lista top e un intero k, inserisce un nuovo nodo con valore k in testa alla lista
ritorna la posizione della nuova testa della lista*/

lista aggiungiInCoda(lista top, int k);
/*data una lista e un intero, inserisce un nuovo nodo con valore k in coda alla lista
ritorna la posizione della nuova testa della lista*/

int lunghezzaLista(lista top);
/*data una lista, ritorna il numero di elementi*/

lista deallocaLista(lista top);
/*dealloca la memoria di tutti gli elementi della lista,
ritorna NULL se e' andata a buon fine*/

lista eliminaTop(lista top);
/*elimina la testa, dealloca la memoria
ritorna la nuova testa*/
#endif // LIST_LIB_H
