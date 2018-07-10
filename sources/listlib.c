#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"
#include "inputReader.h"

void stampaListaHelper(lista top){

  if(top != NULL){
    printf("%d -> ", top->info);//stampa il campo info del top della lista
    stampaListaHelper(top->next);//richiama sul resto della lista
  }

  return;
}

void stampaLista(lista top){

  stampaListaHelper(top);
  printf("//\n");

  return;
}

lista successivo (lista nodo){
  lista ret = NULL;
  if (nodo != NULL) {
    ret = nodo->next;
  }
  return ret;
}

int valoreDi(lista nodo)
{
  int ret = 0;
  if(nodo != NULL){
    ret = nodo->info;
  }
  return ret;
}

lista newElem(int k){

    lista E =(lista)malloc(sizeof(elem));//alloca dinamicamente spazio per un elem, E diventa un puntatore a questo spazio
    E->info = k;//inizializza il nuovo elemento con il valore passato in ingresso
    E->next = NULL;//imposta a NULL il next, il next se non punta a un nodo deve essere sempre NULL
    return E;
}

lista aggiungiInTesta(lista top, int k){

    lista E = newElem(k);//crea un nodo
    E->next = top;//inserisci la lista dopo il nodo creato
    return E;//ritorna la lista aggiornata, il valore ritornato dovra' essere assegnato a un puntatore lista per poter essere utilizzato
}

lista aggiungiInCoda(lista top, int k){

  if(top == NULL)
    top = newElem(k);
  else
    top->next = aggiungiInCoda(top->next, k);

  return top;
}

int lunghezzaLista(lista top){

  if(top == NULL)//se la lista e' vuota
    return 0;
  else
    return 1 + lunghezzaLista(top->next);//ritorna la lunghezza del top (1) + la lunghezza del resto della lista
}

lista deallocaLista(lista top){

  if(top != NULL){//se la lista non e' vuota (caso base gestito implicitamente)
    deallocaLista(top->next);//dealloca il resto della lista
    free(top);//dealloca il top
    top = NULL;//il top non punta piu' a uno spazio di memoria allocato, e' diventato una lista vuota
  }

  return top;
}

lista eliminaTop(lista top){

  lista temp = NULL;//per conservare il valore di top

  if(top != NULL){

    temp = top;//temp punta all'elemento da eliminare
    top = top->next;//eliminando il top il nuovo top sara' il successivo
    free(temp);
  }

  return top;
}
