#include <stdio.h>
#include <stdlib.h>
#include "queuelib.h"

queue *creaQueue(int dim_max){

  queue *Q = (queue *)malloc(sizeof(queue));//alloca spazio per la struct

  if(Q != NULL){

    Q->array = (int *)malloc( (dim_max + 2) * (sizeof(int)) );//alloca spazio per l'array puntato da Q->array di dimensione + 2 interi

    if(Q->array != NULL){
      Q->dimensione = dim_max;
      Q->array[0] = 0;//l'indice della testa (in posizione array[0]) viene posto uguale a 0, indica l'elemento da prelevare
      Q->array[Q->dimensione + 1] = 1;//l'indice della coda viene posto uguale a 1, indica il primo posto disponibile per inserire

    }else{
      free(Q);
      printf("Impossibile allocare memoria\n");
    }
  }else{
    printf("Impossibile allocare memoria\n");
  }

  return Q;
}

void riempiQueue(queue *Q){

  int scelta = -1;
  int x;
  int i = 0;

  if(Q!=NULL){

    do{
      printf("Quanti elementi inserire nella coda?: ");
      scanf("%d", &scelta);
    }while(scelta < 0);

    while(i < scelta && !queueFull(Q)){
      printf("inserire elemento %d: ", i+1);
      scanf("%d", &x);

      enqueue(Q, x);
      i++;
    }

  }else{
    printf("ERRORE in riempiQueue: puntatore NULL\n");
  }

  return;
}

queue *eliminaQueue(queue *Q){

  if(Q != NULL){
    free(Q->array);
    free(Q);
  }else{
    printf("ERRORE in eliminaQueue: puntatore NULL\n");
  }

  return NULL;
}

int queueEmpty(queue *Q){

  int ret;

  if(Q != NULL){

    if(Q->array[0] == 0){//se la queue e' vuota l'indice del primo posto occupato sara' sempre a 0
      ret = 1;
    }else{
      ret = 0;
    }

  }else{
    printf("ERRORE in queueEmpty: puntatore NULL\n");
  }

  return ret;
}

int queueFull(queue *Q){

  int ret;

  if(Q != NULL){

    if(Q->array[0] == Q->array[Q->dimensione + 1]){//se il primo posto libero e il primo occupato coincidono la queue e' piena
      ret = 1;
    }else{
      ret = 0;
    }

  }else{
    printf("ERRORE in queueFull: puntatore NULL\n");
  }

  return ret;
}

void enqueue(queue *Q, int da_inserire){

  if(Q != NULL){

    if(!queueFull(Q)){//se la queue non e' piena
      Q->array[Q->array[Q->dimensione+1]] = da_inserire;//inserisce nel primo posto vuoto
      if (Q->array[0] == 0){//se la queue era vuota
        Q->array[0] = 1;//imposta il primo posto occupato a quello appena riempito
      }
      Q->array[Q->dimensione+1] = (Q->array[Q->dimensione + 1] % Q->dimensione) + 1 ;//imposta il primo posto libero al prossimo
    }else{
      printf("Queue piena!\n");//sostituire con il settaggio di un errore
    }

  }else{
    printf("ERRORE in enqueue: puntatore NULL\n");
  }

  return;
}

int dequeue(queue *Q){

  int x = 0;//per contenere temporaneamente il valore estratto dalla queue

  if(Q != NULL){

    if (!queueEmpty(Q)){//se la queue non e' vuota
      x = Q->array[Q->array[0]];//estrai l'elemento dal primo posto occupato
      Q->array[0] = (Q->array[0] % Q->dimensione) + 1;//imposta il primo posto occupato a prossimo

      if (Q->array[0] == Q->array[Q->dimensione + 1]){//se a questo punto l'array si e' svuotato
        Q->array[0] = 0;//reimposta l'indice del primo posto occupato al valore speciale 0
        Q->array[Q->dimensione + 1] = 1;//reimposta l'indice del primo libero a 1
      }
    }else{
      printf("La queue e' vuota.\n");
    }

  }else{
    printf("ERRORE in dequeue: puntatore NULL\n");
  }

  return x;
}

void stampaQ(queue *Q){

  int x;

  if (!queueEmpty(Q)){
    x = dequeue(Q);//estrae un valore dalla queue
    stampaQ(Q);//stampa il resto della queue
    printf("%d ", x);//stampa il valore estratto
    enqueue(Q, x);//reinserisce il valore nella queue
  }
  //la queue sara' invertita all'uscita dalla funzione
  return;
}

void reverse(queue *Q){

  int x;

  if(!queueEmpty(Q)){
    x = dequeue(Q);//estrae un elemento
    reverse(Q);//inverte il resto della queue
    enqueue(Q, x);//reinserisce l'elemento estratto
  }
  return;
}

void stampaQueue(queue *Q){

  if(Q != NULL){

    stampaQ(Q);//stampa la queue e la inverte come effetto collaterale
    reverse(Q);//inverte la queue per ripristinare l'ordine iniziale
    printf("\n");

  }else{
    printf("ERRORE in stampaQueue: puntatore NULL\n");
  }

  return;
}

void randomizzaQueue(queue *Q, int numeroElementi, int valoreMax){

  int i = 0;

  if(valoreMax > 0){
    if(Q != NULL){

      while(i < numeroElementi && !queueFull(Q)){
        enqueue(Q, ( rand() % valoreMax ) + 1);
        i++;
      }

    }else{
      printf("ERRORE in randomizzaQueue: puntatore NULL\n");
    }
  }else{
    printf("ERRORE in randomizzaQueue: valoreMax non puo' essere minore di 1\n");
  }

  return;
}
