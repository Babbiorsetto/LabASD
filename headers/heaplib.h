#ifndef HEAPLIB_H
#define HEAPLIB_H

void riempi(int *array, int dimensione);
//dato un array, prompta l'utente per [dimensione] interi da inserire nell'array

void stampa(int *array, int dimensione);
//dato un array, stampa a standard output i primi [dimensione] elementi, non effettua controlli di bound superiore

void heapify(int *albero, int radice, int dimensione);
//ripristina la regola dell'heap da radice fino alle foglie di un albero rappresentato in array

int leftSon(int radice);
//se radice è l'indice di un nodo di un albero rappresentato con un array, ritorna l'indice del figlio sinistro di radice

int rightSon(int radice);
//se radice è l'indice di un nodo di un albero rappresentato con un array, ritorna l'indice del figlio destro di radice

void swap(int *array, int elem1, int elem2);
//scambia i valori contenuti nei posti di indice elem1 e elem2 di array

void buildHeap(int *albero, int dimensione);
//dato un albero rappresentato in un array, di [dimensione] elementi, lo trasforma in heap

void heapSort(int *heap, int dimensione);
//dato un heap rappresentato in array e il numero di elementi che contiene, mette gli elementi nell'array in ordine crescente

int eliminaInHeap(int *heap, int target, int *dimensione);
/*dato un heap rappresentato in un array, un intero target e il numero di elementi nell'heap, ricerca target nell'heap e lo elimina.
  Dopodiché ripristina la regola dell'heap su tutto l'heap.
  Ritorna 1 se l'eliminazione ha avuto successo, 0 se target non è presento nell'heap.
*/

#endif
