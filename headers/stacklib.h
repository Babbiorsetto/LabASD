#ifndef STACK_LIB_H
#define STACK_LIB_H

/*prima di utilizzare un puntatore a stack, inizializzarlo con un puntatore ritornato da una chiamata a creaStack*/

//*******************************************************************************
//includere srand((unsigned int)time(0)) nel main se si fa uso di randomizzaStack
//*******************************************************************************

typedef struct stack{
 int *array;
 int dimensione;
}stack;
/*La struttura utilizzata e' uno stack implementato in una struct
array e' un puntatore all'array contenente lo stack, dimensione e' il numero massimo di elementi dello stack
l'array avra' spazio per un intero in piu' che servira' da indice al top dello stack
array[0] contiene l'indice del top, cioe' il primo posto occupato, o 0 se lo stack e' vuoto
*/

stack *creaStack(int dim_max);
/*dato un intero
*alloca memoria per un nuovo stack di massimo dim_max elementi
*ritorna un puntatore all'area di memoria
*/
void riempiStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL e lo stack non si riempie
*chiede all'utente quanti elementi desidera inserire e nel caso in cui siano piu' di 0 li inserisce
*/
stack *eliminaStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*libera la memoria occupata dallo stack
*ritorna NULL se l'operazione e' andata a buon fine
*/
int stackEmpty(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*ritorna 1 se lo stack e' vuoto, 0 se e' presente almeno un elemento
*/
int stackFull(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*ritorna 1 se lo stack e' pieno, 0 se ha almeno un posto vuoto
*/
void push(stack *S, int da_inserire);
/*dato un puntatore a stack e un intero da_inserire
*se il puntatore non e' NULL
*inserisce l'intero in testa allo stack
*/
int pop(stack *S);
/*dato un puntatore a stack,
*se il puntatore non e' NULL
*estrae il prossimo intero dallo stack
*restituisce l'intero estratto
*/
int top(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*restituisce il top dello stack senza rimuoverlo
*/
void stampaStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*stampa gli elementi a partire dal basso separati da uno spazio
*/
void randomizzaStack(stack *S, int numeroElementi, int valoreMax);
/*dato un puntatore a stack e due interi
*se il puntatore non e' NULL e valoreMax e' maggiore di 0
*inserisce nello stack numeroElementi interi compresi fra 1 e valoreMax, oppure si ferma quando lo stack si riempie
*/
#endif
