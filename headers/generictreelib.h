#ifndef GENERIC_TREE_LIB_H
#define GENERIC_TREE_LIB_H

typedef struct gnodo{
  int info;
  struct gnodo *figlio;
  struct gnodo *fratello;
}gnodo;

typedef gnodo* galbero;

galbero nuovoGnodo(int key);
/*dato un intero
*alloca memoria per un nuovo gnodo contenente l'intero
*restituisce un puntatore al gnodo creato
*/
int setFratello(galbero sinistro, galbero destro);
/*Dati due puntatori a gnodi
*se sinistro e' diverso da NULL
*il gnodo destro viene posto come fratello del sinistro
*restituisce 1 se ha effettuato l'operazione, 0 se non e' stato possibile
*/
int setFiglio(galbero padre, galbero figlio);
/*Dati due puntatori a gnodi
*se padre e' diverso da NULL
*il gnodo figlio viene posto come figlio di padre
*restituisce 1 se ha effettuato l'operazione, 0 se non e' stato possibile
*/
galbero getFiglio(galbero padre);
/*dato un puntatore a un gnodo
*se il puntatore non e' NULL
*restituisce il figlio di padre, NULL se non ha un figlio
*/
galbero getFratello(galbero sinistro);
/*dato un puntatore a un gnodo
*se il puntatore non e' NULL
*restituisce il fratello a destra piu' vicino, NULL se non ha fratelli a destra
*/
#endif /* end of include guard: GENERIC_TREE_LIB_H */
