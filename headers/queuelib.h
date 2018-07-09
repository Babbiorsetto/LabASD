#ifndef QUEUE_LIB_H
#define QUEUE_LIB_H

//*******************************************************************************
//includere srand((unsigned int)time(0)) nel main se si fa uso di randomizzaQueue
//*******************************************************************************

/*prima di utilizzare un puntatore a queue, inizializzarlo con un puntatore ritornato da una chiamata a creaQueue*/

typedef struct queue{
  int *array;
  int dimensione;
}queue;
/*La struttura utilizzata e' una coda implementata in una struct
array e' un puntatore all'array contenente la coda, dimensione e' il numero massimo di elementi della coda
l'array avra' spazio per due interi in piu' che serviranno da indici alla testa e alla coda
array[0] contiene l'indice della testa, cioe' il primo posto occupato, o 0 se la queue e' vuota
array[dimensione+1] contiene l'indice della coda, cioe' il primo posto libero*/

queue *creaQueue(int dim_max);
/*dato un intero
*alloca memoria per una nuova queue di massimo dim_max elementi
*ritorna un puntatore all'area di memoria
*/
void riempiQueue(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL e la queue non si riempie
*chiede all'utente quanti elementi desidera inserire e nel caso in cui siano piu' di 0 li inserisce
*/
queue *eliminaQueue(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*libera la memoria occupata dalla queue
*ritorna NULL se l'operazione e' andata a buon fine
*/
int queueEmpty(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*ritorna 1 se la queue e' vuota, 0 se e' presente almeno un elemento
*/
int queueFull(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*ritorna 1 se la queue e' piena, 0 se ha almeno un posto vuoto
*/
void enqueue(queue *Q, int da_inserire);
/*dato un puntatore a queue e un intero da_inserire
*se il puntatore non e' NULL
*inserisce l'intero in fondo alla queue
*/
int dequeue(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*estrae l'intero in testa alla queue
*restituisce l'intero estratto
*/
void stampaQueue(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*stampa gli elementi separati da uno spazio
*/
void randomizzaQueue(queue *Q, int numeroElementi, int valoreMax);
/*dato un puntatore a queue e due interi
*se il puntatore non e' NULL e valoreMax e' maggiore di 0
*inserisce nella queue numeroElementi interi compresi fra 1 e valoreMax, oppure si ferma quando la queue si riempie
*/
void reverseQueue(queue *Q);
/*dato un puntatore a queue
*se il puntatore non e' NULL
*inverte la queue sul posto
*/
#endif
