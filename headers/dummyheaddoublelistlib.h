#ifndef DUMMY_HEAD_DOUBLE_LIST_LIB_H
#define DUMMY_HEAD_DOUBLE_LIST_LIB_H

typedef struct dummyNode{
  int info;
  struct dummyNode *prev;
  struct dummyNode *next;
} dummyNode;

typedef dummyNode* dummyList;

/* Libreria per le liste circolari doppiamente concatenate con elemento fittizio. */

int listaVuotaDummy(dummyList dum);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio
*ritorna 0 se la lista non e' vuota, 1 se e' vuota o viene passato un puntatore NULL
*/
dummyList nuovaListaDummy(void);
/*ritorna un puntatore a lista puntata circolare con elemento fittizio vuota
*/

dummyList precedenteDummy(dummyList nodo);
/*ritorna il precedente del nodo*/

dummyList successivoDummy(dummyList nodo);
/*ritorna il next del nodo*/

int valoreDummy(dummyList nodo);
/*ritorna il campo del nodo*/

int aggiungiInCodaDummy(dummyList dum, int k);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio e un intero
*inserisce l'elemento k in coda alla lista dum
*ritorna 1 se l'inserimento e' andato a buon fine, 0 se non e' possibile inserire l'elemento
*/
int aggiungiInTestaDummy(dummyList dum, int k);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio
*inserisce l'elemento k in testa alla lista dum
*ritorna 1 se l'inserimento e' andato a buon fine, 0 se non e' possibile inserire l'elemento
*/
void stampaListaDummy(dummyList dum);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio
*stampa in stdout il contenuto dei nodi della lista
*/
void svuotaListaDummy(dummyList dum);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio
*elimina tutti gli elementi della lista lasciandola vuota
*/
dummyList deallocaListaDummy(dummyList dum);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio
*elimina la lista
*restituisce un puntatore a NULL
*/
int ricercaInListaDummy(dummyList dum, int k);
/*prende in ingresso un puntatore a lista doppiamente puntata circolare con elemento fittizio e un intero
*ritorna 1 se k e' presente nella lista, 0 altrimenti
*/
#endif
